//
//  Input.cpp
//  TDAGEngine
//
//  Created by wilhan on 18/2/6.
//
//

#include "Input.h"

USING_NS_CC;

void Input::init(int priority)
{
    auto keyboardListener = EventListenerKeyboard::create();
    keyboardListener->onKeyPressed = [=](EventKeyboard::KeyCode code, EventKeyboard::Event* eve)
    {
        __keyMap[code] = true;
    };
    keyboardListener->onKeyReleased = [=](EventKeyboard::KeyCode code, EventKeyboard::Event* eve)
    {
        __keyMap[code] = false;
        __keyMap.erase(code);
    };
    
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    dispatcher->addEventListenerWithFixedPriority(keyboardListener, priority);
}

bool Input::isButtonDown(cocos2d::EventKeyboard::KeyCode code)
{
    return __keyMap[code] == true;
}

bool Input::isButtonUp(cocos2d::EventKeyboard::KeyCode code)
{
    return !Input::isButtonDown(code);
}

int Input::getDirection(int inputIndex)
{
    bool up = Input::isButtonDown(EventKeyboard::KeyCode::KEY_W);
    bool right = Input::isButtonDown(EventKeyboard::KeyCode::KEY_D);
    bool down = Input::isButtonDown(EventKeyboard::KeyCode::KEY_S);
    bool left = Input::isButtonDown(EventKeyboard::KeyCode::KEY_A);
    
    if(up && !right && !down && !left)//up
    {
        return kDirU;
    }
    else if(up && right && !down && !left)//up right
    {
        return kDirRU;
    }
    else if(!up && right && !down && !left)// right
    {
        return kDirR;
    }
    else if(!up && right && down && !left)// right down
    {
        return kDirRD;
    }
    else if(!up && !right && down && !left)// down
    {
        return kDirD;
    }
    else if(!up && !right && down && left)// left down
    {
        return kDirLD;
    }
    else if(!up && !right && !down && left)// left
    {
        return kDirL;
    }
    else if(up && !right && !down && left)// left up
    {
        return kDirLU;
    }
    
    return kDirNone;
}

Vec2 Input::getVector(int dir)
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

std::map<cocos2d::EventKeyboard::KeyCode, bool> Input::__keyMap;