#include "ActiviteForme.hpp"
#include "../../Controler/Kinect/Osc.hpp"
#include "ActiviteInfo.hpp"


using namespace std;

void ActiviteForme::init(){
	wellDone = false;
	duration = DUR_RECO_GESTES;
	string uri = "Video/" + getParam() + ".avi";
	Video::lancerVideo(uri, getDuree());
	
	Video::lancerVideo("Video/RefaireGeste.avi", 5000);
}

void ActiviteForme::exec(){
	Osc *osc = new Osc();
	int numLabel = MapGestes::getGestByName(getParam());
	osc->lancerOsc(numLabel, this);
}

void ActiviteForme::closeAct(){
	if(getWellDone() == true){
		Video::lancerVideo("Video/Bravo.avi", 6000);
	}else{
		Video::lancerVideo("Video/Presque.avi", 5000);
	}
}

/*
void ActiviteForme::lancerOsc(int numLabel){
	ExamplePacketListener listener;
	// maj classLabel
	listener.setClassLabel(numLabel);
	UdpListeningReceiveSocket s(
			IpEndpointName( IpEndpointName::ANY_ADDRESS, PORT ),
			&listener );    
	listener.setS(&s);
	listener.setActivite(this);
	s.Run();

}
*/
