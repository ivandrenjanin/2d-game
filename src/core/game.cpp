#include "game.hpp"

#include "raymath.h"
#include "services/player_component_service.hpp"

void Game::run() {
    InitWindow(screenWidth, screenHeight, "2dgame");
    auto playerComponentService = entt::locator<PlayerComponentService>::value();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(DARKBLUE);
        // Game Logic Start
        auto &&[position] = playerComponentService.getPosition(registry);
        auto &&[size] = playerComponentService.getSize(registry);
        auto &&[velocity] = playerComponentService.getVelocity(registry);
        auto &&[speed] = playerComponentService.getSpeed(registry);
        auto &&[hp] = playerComponentService.getHitPoints(registry);

        if (IsKeyDown(KEY_W)) {
            velocity.y -= 1;
        } else if (IsKeyDown(KEY_S)) {
            velocity.y += 1;
        } else {
            velocity.y = 0;
        }

        if (IsKeyDown(KEY_A)) {
            velocity.x -= 1;
        } else if (IsKeyDown(KEY_D)) {
            velocity.x += 1;
        } else {
            velocity.x = 0;
        }

        if (Vector2Length(velocity) > 0) {
            velocity = Vector2Normalize(velocity);
        }

        position = Vector2Add(
                position,
                Vector2Scale(velocity, speed * GetFrameTime()));

        auto playerCenter = Vector2{position.x + size.x / 2, position.y + size.y / 2};


        auto mouseDirection = Vector2Normalize(
                Vector2Subtract(GetMousePosition(), playerCenter));

        auto wP = Vector2Subtract(
                Vector2Add(playerCenter,
                           Vector2Scale(mouseDirection, size.x)),
                {size.x / 8, size.y / 8}
        );

        DrawRectangleV(position, size, RED);
        DrawRectangleV(wP, {size.x / 4, size.y / 4}, YELLOW);
        
        // Game Logic End
        EndDrawing();
    }
}

