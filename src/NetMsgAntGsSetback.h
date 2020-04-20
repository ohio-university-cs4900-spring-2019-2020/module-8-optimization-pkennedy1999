#pragma once

#include "NetMsg.h"
#include "Vector.h"
#ifdef AFTR_CONFIG_USE_BOOST

namespace Aftr
{

class NetMsgAntGsSetback : public NetMsg
{
public:
   NetMsgMacroDeclaration( NetMsgAntGsSetback );

   NetMsgAntGsSetback(const Vector& position = Vector(0, 0, 0));
   virtual ~NetMsgAntGsSetback();
   virtual bool toStream( NetMessengerStreamBuffer& os ) const;
   virtual bool fromStream( NetMessengerStreamBuffer& is );
   virtual void onMessageArrived();
   virtual std::string toString() const;

protected:
    Vector position;

};

} //namespace Aftr

#endif
