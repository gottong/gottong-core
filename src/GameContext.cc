#include "common.hpp"

#include "../include/Gottong.hpp"

#include "GameContext.hpp"

namespace Gottong {

GameContext::GameContext(std::unique_ptr<Game> game)
	: game(std::move(game))
{
	this->game->onCreate();
}

GameContext::~GameContext()
{
	game->onDestroy();
}

int GameContext::run()
{
	return 0;
}

} /* namespace Gottong */

