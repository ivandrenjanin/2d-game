#pragma once

#include "entt/entt.hpp"
#include "raylib.h"

class Game {
public:
    explicit Game(entt::registry &reg) :
            registry(reg),
            screenWidth(800),
            screenHeight(600) {};

    void run();

private:
    entt::registry &registry;
    int screenWidth;
    int screenHeight;
};