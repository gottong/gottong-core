#ifndef __GOTTONG_GAME_HPP__
#define __GOTTONG_GAME_HPP__

#include <string>
#include <vector>
#include <memory>

#include "Resource.hpp"

#include "Image.hpp"
#include "Sprite.hpp"
#include "Sound.hpp"

namespace Gottong {

class Image;
class Font;
class Keyboard;
class Mouse;

std::shared_ptr<Image> loadImage(const std::string &, const char * = NULL);
std::shared_ptr<Image> loadImage(const std::vector<char> &, const char * = NULL);
std::shared_ptr<Sound> loadSound(const std::string &, const char * = NULL);
std::shared_ptr<Sound> loadSound(const std::vector<char> &, const char * = NULL);

unsigned long getTime();
unsigned long getDeltaTime();

std::shared_ptr<Keyboard> getKeyboard();
std::shared_ptr<Mouse> getMouse();

class Game {
public:
	virtual void onCreate() = 0;
	virtual void onUpdate() = 0;
	virtual void onDestroy() = 0;
};

} /* namespace Gottong */

#endif /* __GOTTONG_GAME_HPP__ */

