//
//  constants.h
//  TDAGEngine
//
//  Created by wilhan on 18/2/6.
//
//

#ifndef constants_h
#define constants_h

#include "cocos2d.h"
#include "Box2D/Box2D.h"

#define PTM_RATIO 32.0f

enum Direction
{
    kDirNone = -1,//None
    
    kDirU  = 0,
    kDirD,
    kDirL,
    kDirR,
    kDirRU,
    kDirRD,
    kDirLD,
    kDirLU
};

cocos2d::Vec2 dirToVec2(int dir);

b2Vec2 toBox2DVec2(float x, float y);
b2Vec2 toBox2DVec2(cocos2d::Vec2 pos);
cocos2d::Vec2 toCocosVec2(float x, float y);
cocos2d::Vec2 toCocosVec2(b2Vec2 pos);

#endif /* constants_h */
