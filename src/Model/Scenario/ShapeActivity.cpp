#include "ShapeActivity.hpp"
#include "../../Controller/Kinect/Osc.hpp"
#include "InfoActivity.hpp"


using namespace std;

void ShapeActivity::init(){
	wellDone = false;
	duration = DUR_RECO_GESTES;
	string uri = "Video/" + getParam() + ".avi";
	Video::launchVideo(uri, getDuree());
	
	Video::launchVideo("Video/RefaireGeste.avi", 8000);
}

void ShapeActivity::exec(){
	Osc *osc = new Osc();
	int numLabel = GesturesMap::getGestByName(getParam());
	osc->launchOsc(numLabel, this);
}

void ShapeActivity::closeAct(){
	if(getWellDone() == true){
		Video::launchVideo("Video/Bravo.avi", 3000);
	}else{
		Video::launchVideo("Video/Presque.avi", 11000);
	}
}

/*
void ShapeActivity::launchOsc(int numLabel){
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
