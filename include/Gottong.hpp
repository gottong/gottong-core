#ifndef __GOTTONG_HPP__
#define __GOTTONG_HPP__

#include <memory>
#include <string>

#include "gottong/Game.hpp"

namespace Gottong {

void Init(const std::string &title, int width, int height, bool is_fullscreen);
int Run(std::unique_ptr<Game> game);

} /* namespace Gottong */

#endif /* __GOTTONG_HPP__ */

