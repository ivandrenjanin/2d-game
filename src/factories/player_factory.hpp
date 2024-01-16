#pragma once

#include "entt/entt.hpp"
#include "components/player.hpp"
#include "components/position.hpp"
#include "components/velocity.hpp"
#include "components/size.hpp"
#include "components/speed.hpp"
#include "core/constants.hpp"
#include "components/hit_points.hpp"

class PlayerFactory {
public:
    static entt::entity create(entt::registry &registry) {
        entt::entity playerEntity = registry.create();
        registry.emplace<Player>(playerEntity);
        registry.emplace<Position>(playerEntity, screenCenter);
        registry.emplace<Velocity>(playerEntity, Vector2{0.0f, 0.0f});
        registry.emplace<Size>(playerEntity, Vector2{40.0f, 40.0f});
        registry.emplace<Speed>(playerEntity, 400.0f);
        registry.emplace<HitPoints>(playerEntity, 50);
        return playerEntity;
    }
};