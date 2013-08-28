#ifndef __GOTTONG_IMAGE_HPP__
#define __GOTTONG_IMAGE_HPP__

#include <string>

#include "Types.hpp"

namespace Gottong {

class ImageRenderOpt {
public:
	float w, h;
	float angle;
	float alpha;
};

class Image {
public:
	const std::string name;

public:
	Image(const std::string &name);

	virtual void draw(const ImageRenderOpt &opt) = 0;
};

} /* namespace Gottong */

#endif /* __GOTTONG_IMAGE_HPP__ */

