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
	int temps = 0;
	void setS(UdpListeningReceiveSocket *s) {
		_s = s;
	}

	void setActivite(ActiviteForme *a) {
		_activite = a;
	}
	
	void setClassLabel(int num){
		_classLabel = num;
	}

protected:
	UdpListeningReceiveSocket * _s;
	ActiviteForme * _activite;
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
			std::cout << s << " " << classLabel << std::endl;
			if(strcmp(classLabel.c_str(), s) == 0) {
				std::cout << "ClassLabel : " << classLabel << "\n";
				_activite->setWellDone(true);
				
				_s->Break();
				//_activite->killOf();				//socketUdp.Break();
			}else{
				temps++;
				if(temps%1000==0){
					//_activite->decrementEssai();
					//if(_activite->getEssais()==0){
						_s->Break();
						//_activite->killOf();
					//}else{
						//_activite->afficherMessage("Essaie encore!");
				//	}
				}

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
