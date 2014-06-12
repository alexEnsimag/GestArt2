#include "ActiviteForme.hpp"
#include "ReceiveClassLabel.hpp"

using namespace std;

void ActiviteForme::init(){
	setWellDone(false);
	//string nameForme = getParam();
	//string msg = "Faire un " + nameForme;
	//afficherMessage(msg);
	string uri = "Videos/" + param + ".avi";
	Video::lancerVideo(uri);
}

void ActiviteForme::exec(){

	lancerOsc();
/*
	if(getWellDone() == true){
		afficherMessage("Bravo");
	}else{
		afficherMessage("Perdu!");
	}*/
}

void ActiviteForme::closeAct(){
	if(getWellDone() == true){
		Video::lancerVideo("Videos/gagné.avi");
	}else{
		Video::lancerVideo("Videos/perdu.avi");
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
