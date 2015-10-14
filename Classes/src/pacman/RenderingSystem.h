#ifndef RENDERINGSYSTEM_H_
#define RENDERINGSYSTEM_H_

#include <entityx/entityx.h>


class RenderingSystem : public entityx::System<RenderingSystem>
{
public:
    void update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt) override;
};


#endif
