//
//  MeleeSystem.h
//  TDAGEngine
//
//  Created by wilhan on 18/2/9.
//
//

#ifndef MeleeSystem_h
#define MeleeSystem_h

#include "cocos2d.h"
#include "entityx/entityx.h"

#include "components/components.h"

class MeleeSystem : public entityx::System<MeleeSystem>, public entityx::Receiver<MeleeSystem>
{
public:
    void configure(entityx::EventManager &events);
    
    void update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt);
};

#endif /* MeleeSystem_h */
