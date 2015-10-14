
#include "SpawnSystem.h"
#include <random>
#include "Components.h"
#include "RespawnEvent.h"


SpawnSystem::SpawnSystem(const InitParams& params)
{
    _initParams = params;
    _respawn = true;
}

void SpawnSystem::update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt)
{
    if (!_respawn)
        return;

    _respawn = false;
    es.each<NodeComponent>([&] (entityx::Entity entity, NodeComponent&) {
        entity.destroy();
    });
    
    cocos2d::Vec2 ballSize(
        10.0f,
        10.0f
    );
    cocos2d::Vec2 leftPlankPos(
        _initParams.left->getContentSize().width * 0.5f,
        _initParams.fieldSize.y * 0.5f
        );
    cocos2d::Vec2 rightPlankPos(
        _initParams.fieldSize.x - _initParams.left->getContentSize().width * 0.5f,
        _initParams.fieldSize.y * 0.5f
        );
    float plankMaxSpeed = 3.0f;
    cocos2d::Vec2 plankSize(
        10,
        40
        );

    // creating ball
    for (int i = 0; i < _initParams.balls.size(); i++) {
        cocos2d::Vec2 ballPosition(
                                   rand() % int(_initParams.fieldSize.x * 0.5f) +
                                   _initParams.fieldSize.x * 0.25f,
                                   ballPosition.y = rand() % int(_initParams.fieldSize.y * 0.5f) +
                                   _initParams.fieldSize.y * 0.25f
                                   );
        int ballVelDisp = 200;
        cocos2d::Vec2 maxBallVel(6.0f, 2.0f);
        cocos2d::Vec2 ballVelocity(
                                   (rand() % ballVelDisp - ballVelDisp / 2) * (maxBallVel.x / ballVelDisp),
                                   (rand() % ballVelDisp - ballVelDisp / 2) * (maxBallVel.y / ballVelDisp)
                                   );
        
        entityx::Entity ballEntity = es.create();
        ballEntity.assign<NodeComponent>(_initParams.balls[i].get());
        ballEntity.assign<BallBodyComponent>(ballPosition, ballVelocity, ballSize);
    }
    // left plank
    entityx::Entity leftPlankEntity = es.create();
    leftPlankEntity.assign<NodeComponent>(_initParams.left.get());
    leftPlankEntity.assign<PlankComponent>(leftPlankPos, plankMaxSpeed, plankSize);
    leftPlankEntity.assign<PlayerNameComponent>("Player 1");

    // right plank
    entityx::Entity rightPlankEntity = es.create();
    rightPlankEntity.assign<NodeComponent>(_initParams.right.get());
    rightPlankEntity.assign<PlankComponent>(rightPlankPos, plankMaxSpeed, plankSize);
    rightPlankEntity.assign<PlayerNameComponent>("Player 2");
}

void SpawnSystem::configure(entityx::EventManager &events)
{
    events.subscribe<RespawnEvent>(*this);
}

void SpawnSystem::receive(const RespawnEvent &)
{
    _respawn = true;
}
