
#include "PacmanScene.h"


bool PacmanScene::init()
{
    if (!Scene::init())
        return false;

    auto leftPlankNode = cocos2d::DrawNode::create();
    cocos2d::Vec2 halfSize(-5, -20);
    leftPlankNode->drawSolidRect(halfSize, -halfSize, cocos2d::Color4F(1,1,1,1));
    addChild(leftPlankNode);

    auto rightPlankNode = cocos2d::DrawNode::create();
    rightPlankNode->drawSolidRect(halfSize, -halfSize, cocos2d::Color4F(1,1,1,1));
    addChild(rightPlankNode);

    InitParams params;
    for (int i = 0; i < 5; i++) {
        auto ballNode = cocos2d::DrawNode::create();
        ballNode->drawSolidCircle(cocos2d::Vec2(0,0),
                                  10.0f,
                                  0,
                                  32,
                                  1.0f,
                                  1.0f,
                                  cocos2d::Color4F(1, 0.3, 0.3, 1)
                                  );
        ballNode->setPosition(320, 320);
        addChild(ballNode);
        
        params.balls.push_back(cocos2d::RefPtr<cocos2d::Node>(ballNode));
    }
    params.fieldSize = cocos2d::Vec2(720, 480);
    params.left = leftPlankNode;
    params.right = rightPlankNode;
    
    _entityApplication = std::unique_ptr<EntityApplication>(new EntityApplication(params));

    scheduleUpdate();
    
    return true;
}

void PacmanScene::update(float delta)
{
    _entityApplication->update(delta);
    Scene::update(delta);
}

