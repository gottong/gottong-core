#ifndef __WINDOW_MANAGER_HPP__
#define __WINDOW_MANAGER_HPP__

extern "C" {
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
}

namespace Gottong {

class WindowManager {
private:
	SDL_Window *window;

public:
	WindowManager(SDL_Window *window);
	~WindowManager();

	SDL_Window *getWindow();
};

std::shared_ptr<WindowManager> getWindowManager();

} /* namespace Gottong */

#endif

