#ifndef __SPRITE_HPP__
#define __SPRITE_HPP__

namespace Gottong {

class GottongSprite : public Sprite {
private:
	std::shared_ptr<Image> image;

public:
	GottongSprite(std::shared_ptr<Image> image);
};

} /* namespace Gottong */

#endif /* __SPRITE_HPP__ */

