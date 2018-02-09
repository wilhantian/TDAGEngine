//
//  InputSystem.h
//  TDAGEngine
//
//  Created by wilhan on 18/2/7.
//
//

#ifndef InputSystem_h
#define InputSystem_h

#include "cocos2d.h"
#include "entityx/entityx.h"

#include "components/components.h"

class InputSystem : public entityx::System<InputSystem>, public entityx::Receiver<InputSystem>
{
public:
    void configure(entityx::EventManager &events);
    
    void update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt);
};

#endif /* InputSystem_h */
