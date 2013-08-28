#include "common.hpp"

#include "WindowManager.hpp"

namespace Gottong {

WindowManager::WindowManager(SDL_Window *window)
	: window(window)
{
}

WindowManager::~WindowManager()
{
	SDL_DestroyWindow(window);
}

SDL_Window *WindowManager::getWindow()
{
	return window;
}

} /* namespace Gottong */

