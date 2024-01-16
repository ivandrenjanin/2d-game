#include "app.hpp"
#include "game.hpp"
#include "services/player_component_service.hpp"
#include "factories/player_factory.hpp"

void App::run() {
    entt::registry registry;

    auto playerEntity = PlayerFactory::create(registry);
    entt::locator<PlayerComponentService>::emplace(PlayerComponentService{playerEntity});

    Game game = Game{registry};
    game.run();
}