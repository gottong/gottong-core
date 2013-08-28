#include "common.hpp"

#include "../include/Gottong.hpp"

#include "GameContext.hpp"

namespace Gottong {

GameContext::GameContext(std::unique_ptr<Game> game)
	: game(std::move(game))
{
	prev_tick = 0;
	cur_tick = 0;

	this->game->onCreate();
}

GameContext::~GameContext()
{
	game->onDestroy();
}

int GameContext::run()
{
	while (1) {
		cur_tick = SDL_GetTicks();

		game->onUpdate();

		prev_tick = cur_tick;
	}

	return 0;
}

unsigned long GameContext::getTime()
{
	return cur_tick;
}

unsigned long GameContext::getDeltaTime()
{
	return (cur_tick - prev_tick);
}

} /* namespace Gottong */

