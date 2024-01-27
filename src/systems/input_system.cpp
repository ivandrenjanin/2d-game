#include "input_system.hpp"
#include "components/player.hpp"
#include "components/velocity.hpp"
#include "components/weapon.hpp"
#include "components/cursor_direction.hpp"
#include "factories/projectile_factory.hpp"

void InputSystem::update(entt::registry &registry) {
    handleMovement(registry);
    handleMouseActions(registry);
}

void InputSystem::handleMovement(entt::registry &registry) {
    auto view = registry.view<Player, Velocity>();
    for (auto entity: view) {
        auto &&[velocity] = view.get<Velocity>(entity);
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
    }

}

void InputSystem::handleMouseActions(entt::registry &registry) {
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        auto view = registry.view<Weapon, Position, CursorDirection>();
        for (auto entity: view) {
            auto &&[position] = view.get<Position>(entity);
            auto &&[cursorDirection] = view.get<CursorDirection>(entity);
            ProjectileFactory::create(registry, position, cursorDirection);
        }
    }
}