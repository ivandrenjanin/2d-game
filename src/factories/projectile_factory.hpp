#pragma once

#include "entt/entt.hpp"
#include "raymath.h"
#include "components/position.hpp"
#include "components/velocity.hpp"
#include "components/projectile.hpp"

class ProjectileFactory {
public:
    static entt::entity create(entt::registry &registry, Vector2 position, Vector2 direction) {
        auto projectile = registry.create();
        registry.emplace<Position>(projectile, position);
        registry.emplace<Velocity>(projectile);
        registry.emplace<Projectile>(projectile, direction);
        return projectile;
    }
};