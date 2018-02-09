//
//  constants.cpp
//  TDAGEngine
//
//  Created by wilhan on 18/2/6.
//
//

#include "constants.h"

USING_NS_CC;

cocos2d::Vec2 dirToVec2(int dir)
{
    if(dir == kDirU) return cocos2d::Vec2(0.0f, 1.0f);
    if(dir == kDirR) return cocos2d::Vec2(1.0f, 0.0f);
    if(dir == kDirD) return cocos2d::Vec2(0.0f, -1.0f);
    if(dir == kDirL) return cocos2d::Vec2(-1.0f, 0.0f);
    if(dir == kDirRU) return cocos2d::Vec2(1.0f, 1.0f);
    if(dir == kDirRD) return cocos2d::Vec2(1.0f, -1.0f);
    if(dir == kDirLD) return cocos2d::Vec2(-1.0f, -1.0f);
    if(dir == kDirLU) return cocos2d::Vec2(-1.0f, 1.0f);
    
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