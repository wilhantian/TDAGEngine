//
//  Input.h
//  TDAGEngine
//
//  Created by wilhan on 18/2/6.
//
//

#ifndef Input_h
#define Input_h

#include "cocos2d.h"

#include "constants.h"

class Input
{
public:
    static void init(int priority = 0);
    
    static bool isButtonDown(cocos2d::EventKeyboard::KeyCode code);
    static bool isButtonUp(cocos2d::EventKeyboard::KeyCode code);
    
    static int getDirection(int inputIndex);
    static cocos2d::Vec2 getVector(int dir);
private:
    static std::map<cocos2d::EventKeyboard::KeyCode, bool> __keyMap;
};

#endif /* Input_h */
