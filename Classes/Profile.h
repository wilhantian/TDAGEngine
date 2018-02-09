//
//  Profile.h
//  TDAGEngine
//
//  Created by wilhan on 18/2/6.
//
//

#ifndef Profile_h
#define Profile_h

#include "cocos2d.h"

class Profile
{
public:
    Profile(std::string filename);
    
    bool isEmpty();
    
    cocos2d::Animation* getAnimationByName(std::string animName);
    cocos2d::SpriteFrame* getSpriteFrame(std::string animName, int index);
    
private:
    cocos2d::ValueMap __map;
    bool __isFileExist;
    
    cocos2d::Map<std::string, cocos2d::Animation*> __animationMap;
};

#endif /* Profile_h */
