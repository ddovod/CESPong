#ifndef BODYSYSTEM_H_
#define BODYSYSTEM_H_

#include <entityx/entityx.h>


class BodySystem : public entityx::System<BodySystem>
{
public:
    void update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt) override;
};


#endif
