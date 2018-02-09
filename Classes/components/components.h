//
//  components.h
//  TDAGEngine
//
//  Created by wilhan on 18/2/6.
//
//

#ifndef components_h
#define components_h

#include "cocos2d.h"
#include "entityx/entityx.h"
#include "Box2D/Box2D.h"

#include "constants.h"
#include "Profile.h"

struct RenderComponent
{
    RenderComponent(std::string name = "", cocos2d::Node* parent = nullptr):profile(name),animation("idle"),repeat(0),elapsed(0.0f)
    {
        if(profile.isEmpty())
        {
            sprite = cocos2d::Sprite::create(name);
        }
        else
        {
            auto firstFrame = profile.getSpriteFrame(animation, 0);
            if(firstFrame)
            {
                sprite = cocos2d::Sprite::createWithSpriteFrame(firstFrame);
            }
            else
            {
                sprite = cocos2d::Sprite::create();
            }
        }
        
        parent->addChild(sprite);
    }
    
    ~RenderComponent()
    {
        sprite->removeFromParent();
        sprite = nullptr;
    }
    
    cocos2d::Sprite* sprite;
    Profile profile;
    
    std::string animation;
    int repeat;
    float elapsed;
};

struct PositionComponent
{
    PositionComponent(cocos2d::Vec2 pos = cocos2d::Vec2(0,0)):pos(pos)
    {}
    
    cocos2d::Vec2 pos;
};

struct MoveComponent
{
    MoveComponent(int dir = kDirD, float speed = 50.0f):dir(dir),speed(speed),velocity(0.0f, 0.0f)
    {}
    
    int dir;
    float speed;
    
    cocos2d::Vec2 velocity;
};

struct PhysicsComponent
{
    PhysicsComponent(b2Body* body):body(body)
    {}
    
    b2Body* body;
    
    entityx::Entity self;//body中的UserData
};

struct InputComponent
{
    InputComponent(int inputIndex = -1):inputIndex(inputIndex)
    {}
    
    int inputIndex;
};

struct MeleeComponent
{
    MeleeComponent(float attactBoxV = 10.0f, float attactBoxH = 20.0f, float duration = 1.0f):duration(duration),delay(0.0f),attactBoxV(attactBoxV),attackBoxH(attackBoxH)
    {}
    
    float delay;//运行了多久
    float duration;//持续时间
    float attactBoxV, attackBoxH;
};

#endif /* components_h */
