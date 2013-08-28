#ifndef __GOTTONG_GAMEOBJECT_HPP__
#define __GOTTONG_GAMEOBJECT_HPP__

namespace Gottong {

class GameObject {
private:
	std::string name;
public:
	virtual void instantiate() = 0;
};

} /* namespace Gottong */

#endif /* __GOTTONG_GAMEOBJECT_HPP__ */

