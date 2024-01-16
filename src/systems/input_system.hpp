#pragma once

#include "entt/entt.hpp"
#include "raylib.h"
#include "raymath.h"

class InputSystem {
public:
    void update(entt::registry &registry, float deltaTime);

private:
    static void handleMovement(entt::registry &registry);
};