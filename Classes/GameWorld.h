//
//  GameWorld.h
//  TDAGEngine
//
//  Created by wilhan on 18/2/6.
//
//

#ifndef GameWorld_h
#define GameWorld_h

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "entityx/entityx.h"

#include "Input.h"
#include "components/components.h"
#include "systems/RenderSystem.h"
#include "systems/MoveSystem.h"
#include "systems/PhysicsSystem.h"

class GameWorld : public entityx::EntityX
{
public:
    GameWorld();
    
    void init();
    
    void update(float dt);
    
    b2World* getPhysicsWorld();
    
private:
    b2World* __world;
};

#endif /* GameWorld_h */
