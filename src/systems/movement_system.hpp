#pragma once

#include "entt/entt.hpp"

class MovementSystem {
public:
    void update(entt::registry &registry, float deltaTime);

private:
    static void handlePlayerMovement(entt::registry &registry, float deltaTime);

    static void handleWeaponMovement(entt::registry &registry, float deltaTime);

    static void handleProjectileMovement(entt::registry &registry, float deltaTime);
};