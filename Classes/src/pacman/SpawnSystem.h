#ifndef SPAWNSYSTEM_H_
#define SPAWNSYSTEM_H_

#include <entityx/entityx.h>
#include <cocos2d.h>
#include "InitParams.h"
#include "RespawnEvent.h"


class SpawnSystem : public entityx::System<SpawnSystem>, public entityx::Receiver<SpawnSystem>
{
public:
    SpawnSystem(const InitParams& params);
    void update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt) override;
    void configure(entityx::EventManager &events) override;
    void receive(const RespawnEvent&);

private:
    InitParams _initParams;
    bool _respawn;
};


#endif
