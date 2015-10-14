//
//  ScoreSystem.cpp
//  Gestures
//
//  Created by David Dovodov on 14.10.15.
//
//

#include "ScoreSystem.hpp"
#include "Components.h"
#include "RespawnEvent.h"
#include <iostream>


void ScoreSystem::update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt)
{
    if (!_pendingEvents.empty()) {
        for (auto event : _pendingEvents) {
            const auto& component = event.getLoseEntity().component<PlayerNameComponent>();
            _playerScoreMap[component->name]++;
        }
        
        for (const auto& el : _playerScoreMap) {
            std::cout << el.first << " : " << el.second << " || ";
        }
        std::cout << std::endl;
        
        _pendingEvents.clear();
    }
}

void ScoreSystem::configure(entityx::EventManager &events)
{
    events.subscribe<RespawnEvent>(*this);
}

void ScoreSystem::receive(const RespawnEvent &event)
{
    _pendingEvents.push_back(event);
}
