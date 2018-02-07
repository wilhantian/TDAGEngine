//
//  Profile.cpp
//  TDAGEngine
//
//  Created by wilhan on 18/2/6.
//
//

#include "Profile.h"

USING_NS_CC;

Profile::Profile(std::string filename)
{
    filename = "" + filename + ".plist";
    __isFileExist = FileUtils::getInstance()->isFileExist(filename);
    if(__isFileExist)
    {
        __map = FileUtils::getInstance()->getValueMapFromFile(filename);
    }
}

bool Profile::isEmpty()
{
    return !__isFileExist;
}

Animation* Profile::getAnimationByName(std::string animName)
{
    if(animName.length() == 0) return nullptr;
    
    auto anim = __animationMap.at(animName);
    if(anim)
    {
        return anim;
    }
    
    if(__map["animations"].isNull()) return nullptr;
    auto animations = __map["animations"].asValueMap();
    
    if(animations[animName].isNull()) return nullptr;
    auto animation = animations[animName].asValueMap();
    
    if(animation["filename"].isNull()) return nullptr;
    if(animation["size"].isNull()) return nullptr;
    if(animation["delay"].isNull()) return nullptr;
    
    auto filename = animation["filename"].asString();
    auto size = animation["size"].asInt();
    auto delay = animation["delay"].asFloat();
    
    Vector<SpriteFrame*> frames;
    for(int i=0; i<size; i++)
    {
        char buf[128];
        sprintf(buf, filename.c_str(), i);
        
        auto sprite = Sprite::create(buf);
        frames.pushBack(sprite->getSpriteFrame());
    }
    
    anim = Animation::createWithSpriteFrames(frames);
    anim->setDelayPerUnit(delay);
    __animationMap.insert(animName, anim);
    return anim;
}

SpriteFrame* Profile::getSpriteFrame(std::string animName, int index)
{
    auto anim = getAnimationByName(animName);
    if(!anim) return nullptr;
    
    auto frames = anim->getFrames();
    auto frame = frames.at(index);
    if(!frame) return nullptr;
    
    return frame->getSpriteFrame();
}