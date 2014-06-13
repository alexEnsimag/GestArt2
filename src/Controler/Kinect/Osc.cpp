
#include "Osc.hpp"
#include "../../Model/Scenario/ReceiveClassLabel.hpp"



void Osc::lancerOsc(int classLabel, Activite *act){
	ExamplePacketListener listener;
	// maj classLabel
	listener.setClassLabel(classLabel);
	UdpListeningReceiveSocket s(
			IpEndpointName( IpEndpointName::ANY_ADDRESS, PORT ),
			&listener );    
	listener.setS(&s);
	listener.setActivite(act);
	s.Run();
}
