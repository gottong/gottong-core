#include "common.hpp"

extern "C" {
#include <SDL_opengl.h>
}

namespace Gottong {

class GottongImage : public Image {
private:
	const GLuint gid;

public:
	GottongImage(GLuint gid);

	void draw(const ImageRenderOpt &opt);
};

GottongImage::GottongImage(GLuint gid)
	: gid(gid)
{
}

static std::shared_ptr<Image> loadFromSurface(SDL_Surface *surface)
{
	GLenum format;

	switch (surface->format->BytesPerPixel) {
	case 4:
		format = GL_RGBA;
		break;
	default:
		format = GL_RGB;
	}

	GLuint gid;

	SDL_LockSurface(surface);

	glGenTextures(1, &gid);
	glBindTexture(GL_TEXTURE_2D, gid);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);

	glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h, 0, format, GL_UNSIGNED_BYTE, surface->pixels);

	SDL_UnlockSurface(surface);

	return std::make_shared<GottongImage>(gid);
}

static std::shared_ptr<Image> loadImageRW(SDL_RWops *rw, const char *format)
{
	if (!rw) {
		return nullptr;
	}

	SDL_Surface *s;

	if (format)
		s = IMG_LoadTyped_RW(rw, 1, format);
	else
		s = IMG_Load_RW(rw, 1);

	if (!s) {
		return nullptr;
	}

	auto img = loadFromSurface(s);

	SDL_FreeSurface(s);

	return img;
}

std::shared_ptr<Image> loadImage(const std::string &filename, const char *format)
{
	SDL_RWops *rw = SDL_RWFromFile(filename.c_str(), "rb");

	return loadImageRW(rw, format);
}

std::shared_ptr<Image> loadImage(const std::vector<char> &data, const char *format)
{
	SDL_RWops *rw = SDL_RWFromConstMem(data.data(), data.size());

	return loadImageRW(rw, format);
}

} /* namespace Gottong */

