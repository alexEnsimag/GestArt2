#ifndef DEF_RECEIVECLASSLABEL
#define DEF_RECEIVECLASSLABEL

#include <iostream>
#include <cstring>

#include "../../osc/OscReceivedElements.h"
#include "../../osc/OscPacketListener.h"
#include "../../osc/UdpSocket.h"


#define PORT 12346

class ExamplePacketListener : public osc::OscPacketListener {
public:
	void setS(UdpListeningReceiveSocket *s) {
		_s = s;
	}
protected:
	UdpListeningReceiveSocket * _s;

   


    virtual void ProcessMessage( const osc::ReceivedMessage& m, 
				const IpEndpointName& remoteEndpoint )
    {
        (void) remoteEndpoint; // suppress unused parameter warning

        try{
            // osc::OsckPacketListener handles the bundle traversal.
			osc::ReceivedMessage::const_iterator arg = m.ArgumentsBegin();
			std::string classLabel = (arg++)->AsString();

			
			std::cout << "ClassLabel : " << classLabel << "\n";

			if(classLabel != "0") {
				_s->Break();
				//socketUdp.Break();
			}
		

        }catch( osc::Exception& e ){
            // any parsing errors such as unexpected argument types, or 
            // missing arguments get thrown as exceptions.
            std::cout << "error while parsing message: "
                << m.AddressPattern() << ": " << e.what() << "\n";
        }
    }
};


#endif
