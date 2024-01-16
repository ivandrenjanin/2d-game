#include "game.hpp"

#include "raymath.h"
#include "factories/projectile_factory.hpp"
#include "factories/player_factory.hpp"
#include "factories/weapon_factory.hpp"
#include "systems/input_system.hpp"
#include "systems/movement_system.hpp"

void Game::run() {
    InitWindow(screenWidth, screenHeight, "2dgame");
    auto playerEntity = PlayerFactory::create(registry);
    auto weaponEntity = WeaponFactory::create(registry, playerEntity);
    InputSystem inputSystem;
    MovementSystem movementSystem;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(DARKBLUE);
        // Game Logic Start
        float deltaTime = GetFrameTime();
        inputSystem.update(registry, deltaTime);
        movementSystem.update(registry, deltaTime);

        auto &&[position] = registry.get<Position>(playerEntity);
        auto &&[size] = registry.get<Size>(playerEntity);
        auto &&[color] = registry.get<ShapeColor>(playerEntity);
        auto &&[weaponPosition] = registry.get<Position>(weaponEntity);
        auto &&[weaponSize] = registry.get<Size>(weaponEntity);
        auto &&[weaponColor] = registry.get<ShapeColor>(weaponEntity);

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            auto playerCenter = Vector2{position.x + size.x / 2, position.y + size.y / 2};
            auto mouseDirection = Vector2Normalize(
                    Vector2Subtract(GetMousePosition(), playerCenter));
            ProjectileFactory::create(registry, weaponPosition, mouseDirection);
        }

        auto view = registry.view<Position, Velocity, Projectile, SizeRadial, ShapeColor>();
        for (auto entity: view) {
            auto &&[pVelocity] = view.get<Velocity>(entity);
            auto &&[direction] = view.get<Projectile>(entity);
            auto &&[pPosition] = view.get<Position>(entity);
            auto &&[radialSize] = view.get<SizeRadial>(entity);
            auto &&[pColor] = view.get<ShapeColor>(entity);

            if (pPosition.x<0 || pPosition.x>(float)screenWidth || pPosition.y<0 || pPosition.y>(float)
            screenHeight) {
                registry.destroy(entity);
            } else {
                DrawCircleV(pPosition, radialSize, pColor);
            }
        }

        DrawRectangleV(position, size, color);
        DrawRectangleV(weaponPosition, weaponSize, weaponColor);
        // Game Logic End
        EndDrawing();
    }
}

