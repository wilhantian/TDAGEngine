//
//  RenderSystem.cpp
//  TDAGEngine
//
//  Created by wilhan on 18/2/6.
//
//

#include "RenderSystem.h"

USING_NS_CC;
using namespace entityx;

void RenderSystem::configure(entityx::EventManager &events)
{
    
}

void RenderSystem::update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt)
{
    entities.each<RenderComponent, PositionComponent>([=](Entity entity, RenderComponent& render, PositionComponent& position)
    {
        render.sprite->setPosition(position.pos);
        
        if(render.animation.length() > 0 && !render.profile.isEmpty())//有动画
        {
            render.elapsed += dt;
            
            auto anim = render.profile.getAnimationByName(render.animation);
            if(anim)
            {
                if(render.elapsed > anim->getDuration())//播放完一次了
                {
                    if(render.repeat > 0)
                    {
                        render.repeat--;
                    }
                    if(render.repeat == 0)
                    {
                        render.animation = "idle";
                        render.repeat = -1;
                        anim = render.profile.getAnimationByName(render.animation);
                        if(!anim)
                        {
                            return;
                        }
                    }
                    render.elapsed = 0.0f;
                }
                
                // 取出帧
                auto frames = anim->getFrames();
                int frameIndex = render.elapsed / anim->getDelayPerUnit();
                frameIndex = frameIndex < 0 ? 0 : frameIndex;
                frameIndex = frameIndex > frames.size()-1 ? frames.size()-1 : frameIndex;
                
                // 设置帧
                auto frame = frames.at(frameIndex);
                render.sprite->setSpriteFrame(frame->getSpriteFrame());
            }
        }
    });
}