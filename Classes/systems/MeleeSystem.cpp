//
//  MeleeSystem.cpp
//  TDAGEngine
//
//  Created by wilhan on 18/2/9.
//
//

#include "MeleeSystem.h"

#include "Input.h"

USING_NS_CC;
using namespace entityx;

void MeleeSystem::configure(entityx::EventManager &events)
{
    
}

void MeleeSystem::update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt)
{
    entities.each<MeleeComponent>([=](Entity entity, MeleeComponent& melee)
    {
        //TODO
    });
}