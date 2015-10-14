#ifndef INITPARAMS_H_
#define INITPARAMS_H_

#include <cocos2d.h>
#include <vector>


struct InitParams
{
    std::vector<cocos2d::RefPtr<cocos2d::Node>> balls;
    cocos2d::RefPtr<cocos2d::Node> left;
    cocos2d::RefPtr<cocos2d::Node> right;
    cocos2d::Vec2 fieldSize;
};


#endif
