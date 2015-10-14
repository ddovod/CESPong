#ifndef ENTITYAPPLICATION_H_
#define ENTITYAPPLICATION_H_

#include <entityx/entityx.h>
#include <cocos2d.h>
#include "InitParams.h"


class EntityApplication : public entityx::EntityX
{
public:
    EntityApplication(const InitParams& params);
    void update(entityx::TimeDelta dt);
};


#endif
