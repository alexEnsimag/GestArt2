#ifndef DEF_RECEIVECLASSLABEL
#define DEF_RECEIVECLASSLABEL

#include <iostream>
#include <cstring>


#include "../../osc/OscReceivedElements.h"
#include "../../osc/OscPacketListener.h"
#include "../../osc/UdpSocket.h"

#include "ShapeActivity.hpp"
#include "../../View/Interface/PageAdmin.hpp"


#define PORT 12346
#define ACT_DURATION 1000

class ExamplePacketListener : public osc::OscPacketListener {
public:
	int time;
	int duration;
	void setS(UdpListeningReceiveSocket *s) {
		time = 0;
		_s = s;
	}

	void setActivite(Activity *a) {
		_activity = a;
		duration = a->getDuration();
	}
	
	void setClassLabel(int num){
		_classLabel = num;
	}

protected:
	UdpListeningReceiveSocket * _s;
	Activity * _activity;
	int _classLabel;

   


    virtual void ProcessMessage( const osc::ReceivedMessage& m, 
				const IpEndpointName& remoteEndpoint )
    {
        (void) remoteEndpoint; // suppress unused parameter warning

        try{
            // osc::OsckPacketListener handles the bundle traversal.
			osc::ReceivedMessage::const_iterator arg = m.ArgumentsBegin();
			std::string classLabel = (arg++)->AsString();

			char * s;
			sprintf(s, "%d",_classLabel);
			if(strcmp(classLabel.c_str(), s) == 0) {
				std::cout << "ClassLabel : " << classLabel << "\n";
				_activity->setWellDone(true);
				sleep(2);
				
				_s->Break();
			}else if(duration != 0) {
				time++;
				if(time == duration){
				    		time = 0;
						_s->Break();
				}

			}
		

        }catch( osc::Exception& e ){
            // any parsing errors such as unexpected argument types, or 
            // missing arguments get thrown as exceptions.
            std::cout << m.AddressPattern() << ": " << e.what() << "\n";
        }
    }
};


#endif
