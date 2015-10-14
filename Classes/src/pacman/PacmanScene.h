#ifndef PACMANSCENE_H_
#define PACMANSCENE_H_

#include <memory>
#include <cocos2d.h>
#include "EntityApplication.h"


class PacmanScene : public cocos2d::Scene
{
public:
    CREATE_FUNC(PacmanScene);

    bool init() override;
    void update(float delta) override;
    
private:
    std::unique_ptr<EntityApplication> _entityApplication;
};


#endif
