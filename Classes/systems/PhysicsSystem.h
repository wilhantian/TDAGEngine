//
//  PhysicsSystem.h
//  TDAGEngine
//
//  Created by wilhan on 18/2/7.
//
//

#ifndef PhysicsSystem_h
#define PhysicsSystem_h

#include "cocos2d.h"
#include "entityx/entityx.h"

#include "components/components.h"

class b2World;

class PhysicsSystem : public entityx::System<PhysicsSystem>, public entityx::Receiver<PhysicsSystem>
{
public:
    PhysicsSystem(b2World* world);
    
    void configure(entityx::EventManager &events);
    
    void receive(const entityx::ComponentAddedEvent<PhysicsComponent>& eve);
    
    void update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt);
    
private:
    b2World* __world;
};


#endif /* PhysicsSystem_h */
