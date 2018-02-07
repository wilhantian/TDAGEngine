//
//  MoveSystem.cpp
//  TDAGEngine
//
//  Created by wilhan on 18/2/7.
//
//

#include "MoveSystem.h"

USING_NS_CC;
using namespace entityx;

void MoveSystem::configure(entityx::EventManager &events)
{
    
}

void MoveSystem::update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt)
{
    entities.each<MoveComponent, PositionComponent>([=](Entity entity, MoveComponent& move, PositionComponent& position)
    {
        auto physics = entity.component<PhysicsComponent>();
        if(physics)//使用物理移动
        {
            auto body = physics->body;
            if(body)
            {
                body->SetLinearVelocity(toBox2DVec2(move.velocity));
            }
        }
        else//不使用物理移动
        {
            auto offset = move.velocity * dt;
            position.pos.add(offset);
        }
    });
}