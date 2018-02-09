#include "HelloWorldScene.h"

#include "GameWorld.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();

    auto layer = HelloWorld::create();
    scene->addChild(layer);

    return scene;
}

bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    __world = new GameWorld();

    {
        b2BodyDef def;
        def.type = b2BodyType::b2_dynamicBody;
        auto body = __world->getPhysicsWorld()->CreateBody(&def);
        b2PolygonShape shape;
        shape.SetAsBox(40 / 2 / PTM_RATIO, 40 / 2 / PTM_RATIO);
        body->CreateFixture(&shape, 1);
        
        auto e = __world->entities.create();
        e.assign<RenderComponent>("test", this);
        e.assign<PositionComponent>(Vec2(100, 100));
        e.assign<MoveComponent>();
        e.assign<PhysicsComponent>(body);
        e.assign<InputComponent>(0);
        
        auto move = e.component<MoveComponent>();
        move->velocity.set(3, 3);
    }
    
    {
        b2BodyDef def;
        def.type = b2BodyType::b2_dynamicBody;
        auto body = __world->getPhysicsWorld()->CreateBody(&def);
        b2PolygonShape shape;
        shape.SetAsBox(40 / 2 / PTM_RATIO, 40 / 2 / PTM_RATIO);
        body->CreateFixture(&shape, 1);
        
        auto e = __world->entities.create();
        e.assign<RenderComponent>("test", this);
        e.assign<PositionComponent>(Vec2(100 + 50, 100));
        e.assign<MoveComponent>();
        
        auto move = e.component<MoveComponent>();
        move->velocity.set(3, 3);
        
        auto render = e.component<RenderComponent>();
        render->animation = "run";
        render->repeat = -1;
        render->sprite->setFlipX(false);
    }
    
    scheduleUpdate();
    
    return true;
}

void HelloWorld::update(float dt)
{
    __world->update(dt);
}
