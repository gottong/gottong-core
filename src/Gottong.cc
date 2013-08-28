#include "../include/Gottong.hpp"

#include "common.hpp"

#include "WindowManager.hpp"

extern "C" {
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
}

namespace Gottong {

static std::shared_ptr<WindowManager> wm;

void Init(const std::string &title, int width, int height, bool is_fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING)) {
		throw std::runtime_error("Error Initiating SDL");
	}

	Uint32 flags = SDL_WINDOW_OPENGL;

	if (is_fullscreen) {
		flags |= SDL_WINDOW_FULLSCREEN;
	}

	SDL_Window *window = SDL_CreateWindow(
		title.c_str(),
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		width,
		height,
		flags
	);

	if (!window) {
		throw std::runtime_error("Error Creating Window");
	}

	wm = std::make_shared<WindowManager>(window);
}

int Run(std::unique_ptr<Game> game)
{
	return 0;
}

std::shared_ptr<WindowManager> getWindowManager()
{
	return wm;
}

} /* namespace Gottong */

