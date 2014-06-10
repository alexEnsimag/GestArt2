#include "ActiviteFormes.hpp"
#include "ReceiveClassLabel.hpp"

void ActiviteFormes::launch(){
	// faire une forme
	// lancer of
	// osc
	lancerOsc();

	// processing
}

void ActiviteFormes::lancerOsc(){
	ExamplePacketListener listener;

	UdpListeningReceiveSocket s(

			IpEndpointName( IpEndpointName::ANY_ADDRESS, PORT ),

			&listener );    

	listener.setS(&s);
	s.Run();

}



