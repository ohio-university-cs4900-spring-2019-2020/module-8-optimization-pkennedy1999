#include "CloneTrooper.h"

#ifdef AFTR_CONFIG_USE_BOOST

using namespace Aftr;

CloneTrooper* CloneTrooper::New(Vector position, const std::string file) {
    return new CloneTrooper(position, file);
}

CloneTrooper::CloneTrooper(Vector position, const std::string file) {
    this -> clone = WO::New(file);
    this -> clone -> setPosition(position);
}

#endif
