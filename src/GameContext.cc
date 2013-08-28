#include "common.hpp"

#include "../include/Gottong.hpp"

#include "GameContext.hpp"
#include "WindowManager.hpp"

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

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glPushMatrix();

		glMatrixMode(GL_MODELVIEW);
		glEnable(GL_TEXTURE_2D);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		game->onUpdate();

		glDisable(GL_BLEND);
		glDisable(GL_TEXTURE_2D);

		glPopMatrix();

		SDL_GL_SwapWindow(getWindowManager()->getWindow());

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

