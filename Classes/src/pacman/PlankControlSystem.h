#ifndef PLANKCONTROLSYSTEM_H_
#define PLANKCONTROLSYSTEM_H_

#include <entityx/entityx.h>


class PlankControlSystem : public entityx::System<PlankControlSystem>
{
public:
    void update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt) override;
};


#endif
