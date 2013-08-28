#include "common.hpp"

extern "C" {
#include <SDL_opengl.h>
}

namespace Gottong {

class GottongImage : public Image {
private:
	const GLuint gid;

public:
	GottongImage(const std::string &name, GLuint gid);

	void draw(const ImageRenderOpt &opt);
};

GottongImage::GottongImage(const std::string &name, GLuint gid)
	: Image(name), gid(gid)
{
}

std::shared_ptr<Image> loadFromSurface(const std::string &name, SDL_Surface *surface)
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

	return std::make_shared<GottongImage>(name, gid);
}

std::shared_ptr<Image> loadImage(const std::string &filename, const char *format)
{
	SDL_Surface *s = IMG_Load(filename.c_str());
	
	auto img = loadFromSurface(filename, s);

	SDL_FreeSurface(s);

	return img;
}

std::shared_ptr<Image> loadImage(const std::vector<char> &data, const char *format)
{
	return nullptr;
}

} /* namespace Gottong */

