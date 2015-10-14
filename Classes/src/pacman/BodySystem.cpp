
#include "BodySystem.h"
#include "Components.h"


void BodySystem::update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt)
{
    es.each<BallBodyComponent>([] (entityx::Entity, BallBodyComponent& component) {
            component.position += component.velocity;
        });
}
