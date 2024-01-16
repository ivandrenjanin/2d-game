#include "input_system.hpp"
#include "components/player.hpp"
#include "components/velocity.hpp"
#include "core/constants.hpp"

void InputSystem::update(entt::registry &registry, float deltaTime) {
    handleMovement(registry);
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