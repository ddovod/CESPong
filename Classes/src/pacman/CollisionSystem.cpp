
#include "CollisionSystem.h"
#include "Components.h"
#include "RespawnEvent.h"


CollisionSystem::CollisionSystem(const cocos2d::Vec2& fieldSize) :
    _fieldSize(fieldSize)
{}

void CollisionSystem::update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt)
{
    es.each<BallBodyComponent>([&] (entityx::Entity, BallBodyComponent& ball) {
            if (ball.position.y - ball.size.y * 0.5f < 0) {
                ball.velocity.y *= -1.0f;
            } else if (ball.position.y + ball.size.y * 0.5f > _fieldSize.y) {
                ball.velocity.y *= -1.0f;
            }

            es.each<PlankComponent>([&] (entityx::Entity entity, PlankComponent& plank) {
                    if (std::abs(ball.position.x - plank.position.x) <
                        (ball.size.x + plank.size.x) * 0.5f) {
                        if (ball.position.y < plank.position.y + plank.size.y * 0.5f &&
                            ball.position.y > plank.position.y - plank.size.y * 0.5f) {
                            ball.velocity.x *= -1.0f;
                        } else {
                            events.emit<RespawnEvent>(entity);
                        }
                    }
                });
        });
}
