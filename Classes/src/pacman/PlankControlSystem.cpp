
#include "PlankControlSystem.h"
#include <vector>
#include <cocos2d.h>
#include "Components.h"


void PlankControlSystem::update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt)
{
    auto getNearestVec = [] (const std::vector<cocos2d::Vec2>& from, const cocos2d::Vec2& to) {
        cocos2d::Vec2 res(1000, 1000);
        float resLength = 1000;
        for (const auto& pos : from) {
            auto tempLength = std::abs((pos - to).x);
            if (tempLength < resLength) {
                resLength = tempLength;
                res = pos;
            }
        }
        return res;
    };
    
    std::vector<cocos2d::Vec2> ballPos;
    
    es.each<BallBodyComponent>([&ballPos] (entityx::Entity, BallBodyComponent& component) {
            ballPos.push_back(component.position);
        });

    es.each<PlankComponent>([&] (entityx::Entity, PlankComponent& component) {
            auto nearestBallPos = getNearestVec(ballPos, component.position);
            auto moveBy = std::min(component.maxSpeed, float(std::abs(nearestBallPos.y - component.position.y)));
            component.position.y += (component.position.y < nearestBallPos.y ?
                                     moveBy : -moveBy);
        });
}

