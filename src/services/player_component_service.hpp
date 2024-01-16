#pragma once

#include "entt/entity/registry.hpp"
#include "components/position.hpp"
#include "components/size.hpp"
#include "components/velocity.hpp"
#include "components/speed.hpp"
#include "components/hit_points.hpp"

class PlayerComponentService {
public:
    explicit PlayerComponentService(entt::entity playerEntity) :
            playerEntity(playerEntity) {}

    Position &getPosition(entt::registry &registry);

    Size &getSize(entt::registry &registry);

    Velocity &getVelocity(entt::registry &registry);

    Speed &getSpeed(entt::registry &registry);

    HitPoints &getHitPoints(entt::registry &registry);

private:
    entt::entity playerEntity;
};