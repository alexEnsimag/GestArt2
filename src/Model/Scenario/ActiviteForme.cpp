#include "ActiviteForme.hpp"
#include "ReceiveClassLabel.hpp"

using namespace std;

void ActiviteForme::init(){
	setWellDone(false);
	string nameForme = getParam();
	string msg = "Faire un " + nameForme;
	afficherMessage(msg);
	of = new Of();
	of->lancementOfRecognize();
}

void ActiviteForme::exec(){

	lancerOsc();
	if(getWellDone() == true){
		afficherMessage("Bravo");
	}else{
		afficherMessage("Perdu!");
	}
}

void ActiviteForme::exec(){
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
