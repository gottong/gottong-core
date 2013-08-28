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

	rectf src_rect;
	rectf dst_rect;
};

class Image {
public:
	virtual void draw(const ImageRenderOpt &opt) = 0;
};

} /* namespace Gottong */

#endif /* __GOTTONG_IMAGE_HPP__ */

