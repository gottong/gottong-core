#include "common.hpp"

#include "../include/Gottong.hpp"

#include "GameContext.hpp"

namespace Gottong {

unsigned long getTime()
{
	auto ctx = getGameContext();

	return ctx->getTime();
}

unsigned long getDeltaTime()
{
	auto ctx = getGameContext();

	return ctx->getDeltaTime();
}

} /* namespace Gottong */

