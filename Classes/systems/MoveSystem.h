//
//  MoveSystem.h
//  TDAGEngine
//
//  Created by wilhan on 18/2/7.
//
//

#ifndef MoveSystem_h
#define MoveSystem_h

#include "cocos2d.h"
#include "entityx/entityx.h"

#include "components/components.h"

class MoveSystem : public entityx::System<MoveSystem>, public entityx::Receiver<MoveSystem>
{
public:
    void configure(entityx::EventManager &events);
    
    void update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt);
};

#endif /* MoveSystem_h */
