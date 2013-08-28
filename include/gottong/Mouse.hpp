#ifndef __GOTTONG_MOUSE_HPP__
#define __GOTTONG_MOUSE_HPP__

#include <string>
#include <vector>

namespace Gottong {

class Button;

class Mouse {
public:
	bool hasChanged();
	std::vector<Button> getActiveButtons();
};

} /* namespace Gottong */

#endif /* __GOTTONG_MOUSE_HPP__ */

