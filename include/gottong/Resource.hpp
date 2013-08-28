#ifndef __GOTTONG_RESOURCE_HPP__
#define __GOTTONG_RESOURCE_HPP__

#include <memory>

#include "GameObject.hpp"

namespace Gottong {

class Resource {
public:
	virtual std::shared_ptr<GameObject> instantiate() = 0;
};

} /* namespace Gottong */

#endif /* __GOTTONG_RESOURCE_HPP__ */

