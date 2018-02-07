//
//  RenderSystem.h
//  TDAGEngine
//
//  Created by wilhan on 18/2/6.
//
//

#ifndef RenderSystem_h
#define RenderSystem_h

#include "cocos2d.h"
#include "entityx/entityx.h"

#include "components/components.h"

class RenderSystem : public entityx::System<RenderSystem>, public entityx::Receiver<RenderSystem>
{
public:
    void configure(entityx::EventManager &events);
    
    void update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt);
};

#endif /* RenderSystem_h */
