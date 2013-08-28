#ifndef __GAME_CONTEXT_HPP__
#define __GAME_CONTEXT_HPP__

#include "../include/Gottong.hpp"

#include <memory>

namespace Gottong {

class GameContext {
private:
	unsigned long prev_tick;
	unsigned long cur_tick;

	const std::unique_ptr<Game> game;

public:
	GameContext(std::unique_ptr<Game>);
	~GameContext();

	unsigned long getTime();
	unsigned long getDeltaTime();
	
	int run();
};

std::shared_ptr<GameContext> getGameContext();

} /* namespace Gottong */

#endif /* __GAME_CONTEXT_HPP__ */

