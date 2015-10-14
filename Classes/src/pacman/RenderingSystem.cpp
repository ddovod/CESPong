
#include "RenderingSystem.h"
#include "Components.h"


void RenderingSystem::update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt)
{
    es.each<NodeComponent>([] (entityx::Entity entity, NodeComponent& component) {
            auto ball = entity.component<BallBodyComponent>();
            if (ball) {
                component.node->setPosition(ball->position);
                return;
            }

            auto plank = entity.component<PlankComponent>();
            if (plank) {
                component.node->setPosition(plank->position);
                return;
            }
        });
}

