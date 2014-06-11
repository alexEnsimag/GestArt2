#include "ActiviteForme.hpp"
#include "ReceiveClassLabel.hpp"
static vector<string> MakeVector(){
	vector<string> v;
	v.push_back("carre");
	v.push_back("triangle");
	v.push_back("cercle");
	return v;
}

const vector<string> ActiviteForme::possibleParams = MakeVector();

void ActiviteForme::lancerOsc(){
	ExamplePacketListener listener;

	UdpListeningReceiveSocket s(

			IpEndpointName( IpEndpointName::ANY_ADDRESS, PORT ),

			&listener );    

	listener.setS(&s);
	listener.setActivite(this);
	s.Run();
}


void ActiviteForme::update(string classLabel){
	if(classLabel == "1"){
		cout<<"success!!";
		wellDone=true;
	}else{
		cout<<"echec!!";

	}
}

void ActiviteForme::killOf(){
	of->killOf();
}





