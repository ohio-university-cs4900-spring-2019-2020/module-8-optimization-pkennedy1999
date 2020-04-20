#pragma once

#include "Model.h"
#include "WO.h"

#ifdef AFTR_CONFIG_USE_BOOST

namespace Aftr
{

class CloneTrooper
{
public:
   static CloneTrooper* New(Vector position = Vector(0, 70, 5), const std::string file = "../mm/models/model.dae");
   void setPosition(float x, float y, float z) {
     clone -> setPosition(Vector(x, y, z));
   };
   void setPosition(Vector v) {
     clone -> setPosition(v);
   };
   Vector getPosition() {
     return clone -> getPosition();
   };
   WO* getClone() {
     return clone;
   };

protected:
   WO* clone;

   CloneTrooper(Vector position = Vector(0, 70, 5), const std::string file = "../mm/models/model.dae");
};

}

#endif
