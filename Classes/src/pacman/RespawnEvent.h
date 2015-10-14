#ifndef RespawnEvent_h
#define RespawnEvent_h

#include <entityx/entityx.h>


class RespawnEvent
{
public:
    RespawnEvent(entityx::Entity loseEntity) :
        _loseEntity(loseEntity)
    {}
    entityx::Entity getLoseEntity() const { return _loseEntity; }
    
private:
    entityx::Entity _loseEntity;
};


#endif
