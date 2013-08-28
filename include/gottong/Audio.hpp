#ifndef __GOTTONG_AUDIO_HPP__
#define __GOTTONG_AUDIO_HPP__

#include "GameObject.hpp"
extern "C" {
#include "include/SDL_Mixer.h"
}

namespace Gottong {

class Audio : public GameObject {
};

} /* namespace Gottong */

#endif /* __GOTTONG_AUDIO_HPP__ */

