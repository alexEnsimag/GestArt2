#include "ActiviteForme.hpp"
#include "ReceiveClassLabel.hpp"



using namespace std;

void ActiviteForme::init(){
	setWellDone(false);
	string uri = "Video/" + getParam() + ".avi";
	Video::lancerVideo(uri, getDuree());
}

void ActiviteForme::exec(){

	lancerOsc();
	
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
	// maj classLabel
	int numLabel = MapGestes::getGestByName(getParam());
	listener.setClassLabel(numLabel);
	UdpListeningReceiveSocket s(
			IpEndpointName( IpEndpointName::ANY_ADDRESS, PORT ),
			&listener );    
	listener.setS(&s);
	listener.setActivite(this);
	s.Run();

}
