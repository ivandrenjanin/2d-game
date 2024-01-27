#pragma once

#include "entt/entt.hpp"
#include "raylib.h"
#include "raymath.h"

class InputSystem {
public:
    void update(entt::registry &registry);

private:
    static void handleMovement(entt::registry &registry);

    static void handleMouseActions(entt::registry &registry);
};