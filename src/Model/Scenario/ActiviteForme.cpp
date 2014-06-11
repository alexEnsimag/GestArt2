#include "ActiviteForme.hpp"
#include "ReceiveClassLabel.hpp"

using namespace std;

static vector<string> MakeVector(){
	vector<string> v;
	v.push_back("carre");
	v.push_back("triangle");
	v.push_back("cercle");
	return v;
}

const vector<string> ActiviteForme::possibleParams = MakeVector();



void ActiviteForme::launch(){  
// faire une forme
//	m->afficherMessage("faire un carre");
//	fen = new Fenetre();
//	fen->afficherMessage("Formes carre et rond");
	setWellDone(false);
	string nameForme = getParam();
	string msg = "Faire un " + nameForme;
	afficherMessage(msg);
		
 	// lancer of
	// osc
	of = new Of();
	of->lancementOfRecognize();
	
 	lancerOsc();
	// osc
 	// processing
	if(getWellDone() == true){
		afficherMessage("Bravo");
	}else{
		afficherMessage("Perdu!");
	}
	
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
