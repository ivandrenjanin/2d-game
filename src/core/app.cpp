#include "app.hpp"
#include "game.hpp"

void App::run() {
    entt::registry registry;
    Game game = Game{registry};
    game.run();
}