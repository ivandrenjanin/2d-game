#pragma once

#include "entt/entt.hpp"

class RenderSystem {
public:
    void update(entt::registry &registry);

private:
    void renderPlayer(entt::registry &registry);

    void renderProjectile(entt::registry &registry);
};