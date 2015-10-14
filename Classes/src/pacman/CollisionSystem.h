#ifndef COLLISIONSYSTEM_H_
#define COLLISIONSYSTEM_H_

#include <entityx/entityx.h>
#include <cocos2d.h>


class CollisionSystem : public entityx::System<CollisionSystem>
{
public:
    explicit CollisionSystem(const cocos2d::Vec2& fieldSize);
    void update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt) override;

private:
    cocos2d::Vec2 _fieldSize;
};


#endif
