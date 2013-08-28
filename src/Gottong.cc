#include "../include/Gottong.hpp"

#include "common.hpp"

#include "WindowManager.hpp"
#include "GameContext.hpp"

namespace Gottong {

static std::shared_ptr<WindowManager> wm(nullptr);
static std::shared_ptr<GameContext> ctx(nullptr);

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

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE,		8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,		8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,		8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,		8);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,		8);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,	1);
	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL,	1);

	glClearColor(0, 0, 0, 0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(0, width, height, 0, 0, 1);
	glViewport(0, 0, width, height);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int Run(std::unique_ptr<Game> game)
{
	ctx = std::make_shared<GameContext>(std::move(game));

	return ctx->run();
}

std::shared_ptr<WindowManager> getWindowManager()
{
	return wm;
}

std::shared_ptr<GameContext> getGameContext()
{
	return ctx;
}

} /* namespace Gottong */

