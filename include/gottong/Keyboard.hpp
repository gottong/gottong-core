#ifndef __GOTTONG_KEYBOARD_HPP__
#define __GOTTONG_KEYBOARD_HPP__

#include <string>
#include <vector>

namespace Gottong {

class Keyboard {
public:
	bool hasChanged();
	std::vector<Key> getActiveKeys();
};

} /* namespace Gottong */

#endif /* __GOTTONG_KEYBOARD_HPP__ */

