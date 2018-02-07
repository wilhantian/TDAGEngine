//
//  GameWorld.cpp
//  TDAGEngine
//
//  Created by wilhan on 18/2/6.
//
//

#include "GameWorld.h"

GameWorld::GameWorld()
{
    init();
}

void GameWorld::init()
{
    __world = new b2World(b2Vec2(0.0f, 0.0f));
    
    systems.add<RenderSystem>();
    systems.add<MoveSystem>();
    systems.add<PhysicsSystem>(__world);
    systems.configure();
}

void GameWorld::update(float dt)
{
    systems.update<RenderSystem>(dt);
    systems.update<MoveSystem>(dt);
    systems.update<PhysicsSystem>(dt);
}

b2World* GameWorld::getPhysicsWorld()
{
    return __world;
}