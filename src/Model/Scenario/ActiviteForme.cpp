#include "ActiviteForme.hpp"
#include "ReceiveClassLabel.hpp"

using namespace std;

void ActiviteForme::init(){
	setWellDone(false);
	//string nameForme = getParam();
	//string msg = "Faire un " + nameForme;
	//afficherMessage(msg);
	string uri = "Videos/" + getParam() + ".avi";
	Video::lancerVideo(uri, getDuree());
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
		Video::lancerVideo("Video/gagne.avi", 1000);
	}else{
		Video::lancerVideo("Video/perdu.avi", 1000);
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
