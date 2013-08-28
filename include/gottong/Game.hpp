#ifndef __GOTTONG_GAME_HPP__
#define __GOTTONG_GAME_HPP__

#include <string>
#include <vector>
#include <memory>

#include "GameObject.hpp"
#include "Resource.hpp"

namespace Gottong {

class Image;
class Sound;
class Font;
class Keyboard;
class Mouse;

class Game {
protected:
	std::shared_ptr<Image> loadImage(const std::string &, const char * = NULL);
	std::shared_ptr<Image> loadImage(const std::vector<char> &, const char * = NULL);
	std::shared_ptr<Sound> loadSound(const std::string &, const char * = NULL);
	std::shared_ptr<Sound> loadSound(const std::vector<char> &, const char * = NULL);
	unsigned long getTime();
	unsigned long getDeltaTime();
	std::shared_ptr<Keyboard> getKeyboard();
	std::shared_ptr<Mouse> getMouse();
public:
	virtual void onCreate() = 0;
	virtual void onUpdate() = 0;
	virtual void onDestroy() = 0;
};

} /* namespace Gottong */

#endif /* __GOTTONG_GAME_HPP__ */

