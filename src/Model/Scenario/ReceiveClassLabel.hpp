#ifndef DEF_RECEIVECLASSLABEL
#define DEF_RECEIVECLASSLABEL

#include <iostream>
#include <cstring>

#include "../../osc/OscReceivedElements.h"
#include "../../osc/OscPacketListener.h"
#include "../../osc/UdpSocket.h"

#include "ActiviteForme.hpp"


#define PORT 12346

class ExamplePacketListener : public osc::OscPacketListener {
public:
	void setS(UdpListeningReceiveSocket *s) {
		_s = s;
	}

	void setActivite(ActiviteForme *a) {
		_activite = a;
	}

protected:
	UdpListeningReceiveSocket * _s;
	ActiviteForme * _activite;

   


    virtual void ProcessMessage( const osc::ReceivedMessage& m, 
				const IpEndpointName& remoteEndpoint )
    {
        (void) remoteEndpoint; // suppress unused parameter warning

        try{
            // osc::OsckPacketListener handles the bundle traversal.
			osc::ReceivedMessage::const_iterator arg = m.ArgumentsBegin();
			std::string classLabel = (arg++)->AsString();

			
			

			if(classLabel != "0") {
				std::cout << "ClassLabel : " << classLabel << "\n";
				
				_s->Break();
				//_activite->update(classLabel);
				_activite->killOf();				//socketUdp.Break();
			}
		

        }catch( osc::Exception& e ){
            // any parsing errors such as unexpected argument types, or 
            // missing arguments get thrown as exceptions.
           // std::cout << "error while parsing message: "
             //   << m.AddressPattern() << ": " << e.what() << "\n";
        }
    }
};


#endif
