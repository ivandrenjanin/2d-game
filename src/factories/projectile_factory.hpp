#pragma once

#include "entt/entt.hpp"
#include "raymath.h"
#include "components/position.hpp"
#include "components/velocity.hpp"
#include "components/projectile.hpp"
#include "components/shape_color.hpp"
#include "components/size_radial.hpp"
#include "components/speed.hpp"
#include "core/constants.hpp"

class ProjectileFactory {
public:
    static entt::entity create(entt::registry &registry, Vector2 position, Vector2 direction) {
        auto projectile = registry.create();

        registry.emplace<Position>(projectile, position);
        registry.emplace<Velocity>(projectile);
        registry.emplace<Projectile>(projectile, direction);
        registry.emplace<ShapeColor>(projectile, springGreen);
        registry.emplace<SizeRadial>(projectile, 5.0f);
        registry.emplace<Speed>(projectile, 800.00f);

        return projectile;
    }
};