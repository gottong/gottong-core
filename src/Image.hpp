#ifndef __IMAGE_HPP__
#define __IMAGE_HPP__

namespace Gottong {

class GottongImage : public Image {
private:
	const GLuint gid;

public:
	GottongImage(GLuint gid);
	~GottongImage();

	void draw(const ImageRenderOpt &opt);
	std::shared_ptr<GameObject> instantiate();
};

} /* namespace Gottong */

#endif /* __IMAGE_HPP__ */

