#ifndef __WINDOW_MANAGER_HPP__
#define __WINDOW_MANAGER_HPP__

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

