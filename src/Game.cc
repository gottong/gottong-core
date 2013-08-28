#include "common.hpp"

#include "../include/Gottong.hpp"

#include "GameContext.hpp"

namespace Gottong {

unsigned long Game::getTime()
{
	auto ctx = getGameContext();

	return ctx->getTime();
}

unsigned long Game::getDeltaTime()
{
	auto ctx = getGameContext();

	return ctx->getDeltaTime();
}

} /* namespace Gottong */

