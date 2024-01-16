#include "movement_system.hpp"
#include "components/position.hpp"
#include "components/velocity.hpp"
#include "components/projectile.hpp"
#include "components/size_radial.hpp"
#include "components/shape_color.hpp"
#include "components/speed.hpp"
#include "raymath.h"
#include "components/player.hpp"
#include "components/weapon.hpp"
#include "components/size.hpp"

void MovementSystem::update(entt::registry &registry, float deltaTime) {
    handlePlayerMovement(registry, deltaTime);
    handleWeaponMovement(registry, deltaTime);
    handleProjectileMovement(registry, deltaTime);
}

void MovementSystem::handlePlayerMovement(entt::registry &registry, float deltaTime) {
    auto view = registry.view<Position, Velocity, Speed, Player>();
    for (auto entity: view) {
        auto &&[velocity] = view.get<Velocity>(entity);
        auto &&[position] = view.get<Position>(entity);
        auto &&[speed] = view.get<Speed>(entity);
        position = Vector2Add(
                position,
                Vector2Scale(velocity, speed * deltaTime));
    }

}

void MovementSystem::handleWeaponMovement(entt::registry &registry, float deltaTime) {
    auto view = registry.view<Position, Weapon>();
    for (auto entity: view) {
        auto &&[wP, weapon] = view.get<Position, Weapon>(entity);
        auto &&[position] = registry.get<Position>(weapon.owner);
        auto &&[size] = registry.get<Size>(weapon.owner);

        auto playerCenter = Vector2{position.x + size.x / 2, position.y + size.y / 2};
        auto mouseDirection = Vector2Normalize(
                Vector2Subtract(GetMousePosition(), playerCenter));

        wP.value = Vector2Subtract(
                Vector2Add(playerCenter,
                           Vector2Scale(mouseDirection, size.x)),
                {size.x / 8, size.y / 8}
        );
    }

}

void MovementSystem::handleProjectileMovement(entt::registry &registry, float deltaTime) {
    auto view = registry.view<Position, Velocity, Projectile, SizeRadial, ShapeColor, Speed>();
    for (auto entity: view) {
        auto &&[velocity] = view.get<Velocity>(entity);
        auto &&[direction] = view.get<Projectile>(entity);
        auto &&[position] = view.get<Position>(entity);
        auto &&[speed] = view.get<Speed>(entity);

        auto mul = speed * deltaTime;
        velocity.x = direction.x * mul;
        velocity.y = direction.y * mul;

        position = Vector2Add(position, velocity);
    }
}
