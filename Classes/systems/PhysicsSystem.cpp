//
//  PhysicsSystem.cpp
//  TDAGEngine
//
//  Created by wilhan on 18/2/7.
//
//

#include "PhysicsSystem.h"

#include "Box2D/Box2D.h"

USING_NS_CC;
using namespace entityx;

PhysicsSystem::PhysicsSystem(b2World* world)
{
    __world = world;
}

void PhysicsSystem::configure(entityx::EventManager &events)
{
    events.subscribe<ComponentAddedEvent<PhysicsComponent>>(*this);
}

void PhysicsSystem::receive(const ComponentAddedEvent<PhysicsComponent> &eve)
{
    auto physics = eve.component;
    if(physics)
    {
        physics->self = eve.entity;//将实体指针保存给物理组件，并传给body中的userdata
        if(physics->body)
        {
            physics->body->SetUserData(&physics->self);
        }
    }
}

void PhysicsSystem::update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt)
{
    // 将ECS位置同步给Box2D
    entities.each<PhysicsComponent>([=](Entity entity, PhysicsComponent& physics)
    {
        auto body = physics.body;
        if(!body)
        {
            return;
        }
        
        auto position = entity.component<PositionComponent>();
        if(position)
        {
            body->SetTransform(toBox2DVec2(position->pos), body->GetAngle());
        }
    });
    
    static int velocityIterations = 8;
    static int positionIterations = 1;
    __world->Step(dt, velocityIterations, positionIterations);
    
    // 将Box2D位置同步给ECS
    entities.each<PhysicsComponent>([=](Entity entity, PhysicsComponent& physics)
    {
        auto body = physics.body;
        if(!body)
        {
            return;
        }
                                        
        auto position = entity.component<PositionComponent>();
        if(position)
        {
            position->pos.set(toCocosVec2(body->GetPosition()));
        }
    });
}