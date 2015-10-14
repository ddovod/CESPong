#ifndef NODECOMPONENT_H_
#define NODECOMPONENT_H_

#include "cocos2d.h"
#include <string>


struct NodeComponent
{
    cocos2d::RefPtr<cocos2d::Node> node;
    explicit NodeComponent(cocos2d::Node* n) :
        node(n)
    {}
};


struct BallBodyComponent
{
    explicit BallBodyComponent(const cocos2d::Vec2& pos, const cocos2d::Vec2& vel, const cocos2d::Vec2& sz) :
        position(pos),
        velocity(vel),
        size(sz)
    {}
    cocos2d::Vec2 position;
    cocos2d::Vec2 velocity;
    cocos2d::Vec2 size;
};


struct PlankComponent
{
    PlankComponent(const cocos2d::Vec2& pos, float mSpeed, const cocos2d::Vec2& sz) :
        position(pos),
        maxSpeed(mSpeed),
        size(sz)
    {}
    
    cocos2d::Vec2 position;
    float maxSpeed;
    cocos2d::Vec2 size;
};


struct PlayerNameComponent
{
    PlayerNameComponent(const std::string& n) :
        name(n)
    {}
    
    std::string name;
};


#endif
