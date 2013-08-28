#ifndef __GOTTONG_GAMEOBJECT_HPP__
#define __GOTTONG_GAMEOBJECT_HPP__

#include <memory>

namespace Gottong {

class GameObject {
private:
	std::string name;

public:
	virtual bool onUpdate() = 0; 
};

} /* namespace Gottong */

#endif /* __GOTTONG_GAMEOBJECT_HPP__ */

