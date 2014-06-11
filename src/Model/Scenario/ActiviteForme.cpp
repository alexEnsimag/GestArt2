#include "ActiviteForme.hpp"
#include "ReceiveClassLabel.hpp"

using namespace std;

static vector<string> MakeVector(){
	vector<string> v;
	v.push_back("Alex");
	return v;
}

const vector<string> ActiviteForme::possibleParams = MakeVector();



void ActiviteForme::launch(){  
// faire une forme
//	m->afficherMessage("faire un carre");
 	// lancer of
	// osc
	of = new Of();
	of->lancementOf();
 	lancerOsc();
	// osc
 	// processing
	lancerOsc();
}

void ActiviteForme::lancerOsc(){
	ExamplePacketListener listener;

	UdpListeningReceiveSocket s(

			IpEndpointName( IpEndpointName::ANY_ADDRESS, PORT ),

			&listener );    

	listener.setS(&s);
	listener.setActivite(this);
	s.Run();

}

void ActiviteForme::killOf(){
	of->killOf();
}
