#include "game.hpp"

#include "components/position.hpp"
#include "components/size.hpp"
#include "components/speed.hpp"
#include "components/velocity.hpp"
#include "components/player.hpp"
#include "raymath.h"

void Game::run() {
    InitWindow(screenWidth, screenHeight, "2dgame");

    entt::entity const playerEntity = registry.create();
    registry.emplace<Player>(playerEntity);
    registry.emplace<Position>(playerEntity,
                               Vector2{static_cast<float>(screenWidth) / 2, static_cast<float>(screenHeight) / 2});
    registry.emplace<Velocity>(playerEntity, Vector2{0.0f, 0.0f});
    registry.emplace<Size>(playerEntity, Vector2{20.0f, 20.0f});
    registry.emplace<Speed>(playerEntity, 400.0f);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(DARKBLUE);
        // Game Logic Start
        auto view = registry.view<Player, Position, Velocity, Size, Speed>();
        auto &&[position] = view.get<Position>(playerEntity);
        auto &&[size] = view.get<Size>(playerEntity);
        auto &&[velocity] = view.get<Velocity>(playerEntity);
        auto &&[speed] = view.get<Speed>(playerEntity);

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

        DrawRectangleV(position, size, RED);

        auto playerCenter = Vector2{position.x + size.x / 2, position.y + size.y / 2};

        auto mouseDirection = Vector2Normalize(
                Vector2Subtract(GetMousePosition(), playerCenter));

        auto wP = Vector2Subtract(
                Vector2Add(playerCenter,
                           Vector2Scale(mouseDirection, size.x)),
                {size.x / 8, size.y / 8}
        );

        DrawRectangleV(wP, {size.x / 4, size.y / 4}, YELLOW);
        // Game Logic End
        EndDrawing();
    }
}

