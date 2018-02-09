//
//  MoveSystem.cpp
//  TDAGEngine
//
//  Created by wilhan on 18/2/7.
//
//

#include "MoveSystem.h"

#include "Input.h"

USING_NS_CC;
using namespace entityx;

void MoveSystem::configure(entityx::EventManager &events)
{
    
}

void MoveSystem::update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt)
{
    entities.each<MoveComponent, PositionComponent>([=](Entity entity, MoveComponent& move, PositionComponent& position)
    {
        auto input = entity.component<InputComponent>();
        int inputDir = -1;
        Vec2 inputVec = Vec2::ZERO;
        
        if(input)
        {
            inputDir = Input::getDirection(input->inputIndex);
            inputVec = Input::getVector(inputDir);
            
            if(inputDir >= 0)
            {
                move.dir = inputDir;
            }
        }
        
        // 设置移动量
        inputVec.normalize();
        move.velocity = inputVec * move.speed;
        
        // 计算移动量
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
        
        // 修改渲染组件
        auto render = entity.component<RenderComponent>();
        if(render)
        {
            std::string anim;
            
            if(inputDir >= 0)
            {
                move.dir = inputDir;
                if(move.dir == kDirU)
                {
                    anim = "runUp";
                }
                else if(move.dir == kDirD)
                {
                    anim = "runDown";
                }
                else
                {
                    anim = "run";
                    auto isFlipped = move.velocity.x > 0.0f;
                    render->sprite->setFlippedX(isFlipped);
                }
            }
            else
            {
                if(move.dir == kDirU)
                {
                    anim = "idleUp";
                }
                else if(move.dir == kDirD)
                {
                    anim = "idleDown";
                }
                else
                {
                    anim = "idle";
                }
            }
            
            if(render->animation != anim)
            {
                render->animation = anim;
                render->repeat = -1;
                render->elapsed = 0.0f;
            }
        }
    });
}
