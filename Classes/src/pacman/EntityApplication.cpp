
#include "EntityApplication.h"
#include "SpawnSystem.h"
#include "CollisionSystem.h"
#include "BodySystem.h"
#include "PlankControlSystem.h"
#include "RenderingSystem.h"
#include "ScoreSystem.hpp"


EntityApplication::EntityApplication(const InitParams& params)
{
    systems.add<SpawnSystem>(params);
    systems.add<BodySystem>();
    systems.add<PlankControlSystem>();
    systems.add<CollisionSystem>(params.fieldSize);
    systems.add<RenderingSystem>();
    systems.add<ScoreSystem>();
    systems.configure();
}

void EntityApplication::update(entityx::TimeDelta dt)
{
    systems.update<SpawnSystem>(dt);
    systems.update<BodySystem>(dt);
    systems.update<PlankControlSystem>(dt);
    systems.update<CollisionSystem>(dt);
    systems.update<RenderingSystem>(dt);
    systems.update<ScoreSystem>(dt);
}

