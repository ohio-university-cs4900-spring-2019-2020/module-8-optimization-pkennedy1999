
#include <iostream>
#include <sstream>
#include <string>
#include "AftrManagers.h"
#include "Vector.h"
#include "WO.h"
#include "GLView.h"
#include "WorldContainer.h"
#include "GLViewNewModule.h"
#include "NetMsgAntGsSetback.h"
#include "Model.h"

using namespace Aftr;

NetMsgMacroDefinition( NetMsgAntGsSetback );

NetMsgAntGsSetback::NetMsgAntGsSetback(const Vector& position)
{
   this->position = position;
}

NetMsgAntGsSetback::~NetMsgAntGsSetback()
{
}

bool NetMsgAntGsSetback::toStream( NetMessengerStreamBuffer& os ) const
{
   os << this->position.x << this->position.y << this->position.z;
   return true;
}

bool NetMsgAntGsSetback::fromStream( NetMessengerStreamBuffer& is )
{
   std::cout << "Message Arrived" << std::endl;
   is >> this->position.x >> this->position.y >> this->position.z;
   return true;
}

void NetMsgAntGsSetback::onMessageArrived()
{
   ((GLViewNewModule*)ManagerGLView::getGLView())->clone->setPosition(this -> position.x, this -> position.y, this -> position.z);

   std::cout << this->toString() << std::endl;
}

std::string NetMsgAntGsSetback::toString() const
{
   std::stringstream ss;

   ss << NetMsg::toString();
   ss << "Position: " << this->position << "...\n";

   return ss.str();
}
