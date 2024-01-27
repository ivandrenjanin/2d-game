#pragma once

#include "entt/entt.hpp"
#include "components/player.hpp"
#include "components/position.hpp"
#include "components/velocity.hpp"
#include "components/size.hpp"
#include "components/speed.hpp"
#include "core/constants.hpp"
#include "components/hit_points.hpp"
#include "components/weapon.hpp"
#include "components/shape_color.hpp"
#include "components/cursor_direction.hpp"

class WeaponFactory {
public:
    static entt::entity create(entt::registry &registry, entt::entity &owner) {
        entt::entity weaponEntity = registry.create();
        auto &&[ownerPos] = registry.get<Position>(owner);
        auto &&[ownerSize] = registry.get<Size>(owner);
        auto ownerCenter = Vector2{ownerPos.x + ownerSize.x / 2, ownerPos.y + ownerSize.y / 2};

        registry.emplace<Weapon>(weaponEntity, owner);
        registry.emplace<Position>(weaponEntity, ownerCenter);
        registry.emplace<Size>(weaponEntity, Vector2{ownerSize.x / 4, ownerSize.y / 4});
        registry.emplace<ShapeColor>(weaponEntity, orange);
        registry.emplace<CursorDirection>(weaponEntity, Vector2{0, 0});
        
        return weaponEntity;
    }
};