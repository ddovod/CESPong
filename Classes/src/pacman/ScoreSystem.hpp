//
//  ScoreSystem.hpp
//  Gestures
//
//  Created by David Dovodov on 14.10.15.
//
//

#ifndef ScoreSystem_hpp
#define ScoreSystem_hpp

#include <entityx/entityx.h>
#include "RespawnEvent.h"
#include <map>
#include <string>
#include <vector>


class ScoreSystem : public entityx::System<ScoreSystem>, public entityx::Receiver<ScoreSystem>
{
public:
    void update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt) override;
    void configure(entityx::EventManager &events) override;
    void receive(const RespawnEvent&);
    
private:
    std::map<std::string, int> _playerScoreMap;
    std::vector<RespawnEvent> _pendingEvents;
};


#endif /* ScoreSystem_hpp */
