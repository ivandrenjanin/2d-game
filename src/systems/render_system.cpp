#include "render_system.hpp"

void RenderSystem::update(entt::registry &registry) {
    renderPlayer(registry);
    renderProjectile(registry);
}


void RenderSystem::renderPlayer(entt::registry &registry) {}

void RenderSystem::renderProjectile(entt::registry &registry) {}