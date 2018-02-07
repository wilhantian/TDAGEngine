//
//  constants.cpp
//  TDAGEngine
//
//  Created by wilhan on 18/2/6.
//
//

#include "constants.h"

USING_NS_CC;

cocos2d::Vec2 directionToVec2(Direction dir)
{
    if(dir == Direction::Up) return cocos2d::Vec2(0.0f, 1.0f);
    if(dir == Direction::Right) return cocos2d::Vec2(1.0f, 0.0f);
    if(dir == Direction::Down) return cocos2d::Vec2(0.0f, -1.0f);
    if(dir == Direction::Left) return cocos2d::Vec2(-1.0f, 0.0f);
    return cocos2d::Vec2::ZERO;
}

b2Vec2 toBox2DVec2(float x, float y)
{
    return b2Vec2(x / PTM_RATIO, y / PTM_RATIO);
}

b2Vec2 toBox2DVec2(cocos2d::Vec2 pos)
{
    return toBox2DVec2(pos.x, pos.y);
}

cocos2d::Vec2 toCocosVec2(float x, float y)
{
    return Vec2(x * PTM_RATIO, y * PTM_RATIO);
}

cocos2d::Vec2 toCocosVec2(b2Vec2 pos)
{
    return toCocosVec2(pos.x, pos.y);
}