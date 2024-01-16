#include "player_component_service.hpp"

Position &PlayerComponentService::getPosition(entt::registry &registry) {
    return registry.get<Position>(playerEntity);
}

Velocity &PlayerComponentService::getVelocity(entt::registry &registry) {
    return registry.get<Velocity>(playerEntity);
}

Speed &PlayerComponentService::getSpeed(entt::registry &registry) {
    return registry.get<Speed>(playerEntity);
}

Size &PlayerComponentService::getSize(entt::registry &registry) {
    return registry.get<Size>(playerEntity);
}

HitPoints &PlayerComponentService::getHitPoints(entt::registry &registry) {
    return registry.get<HitPoints>(playerEntity);
}