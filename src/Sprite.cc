#include "common.hpp"

#include "Image.hpp"
#include "Sprite.hpp"

namespace Gottong {

GottongSprite::GottongSprite(std::shared_ptr<Image> image)
	: image(image)
{
}

} /* namespace Gottong */

