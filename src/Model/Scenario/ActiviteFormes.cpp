#include "ActiviteFormes.hpp"
#include "ReceiveClassLabel.hpp"


ActiviteFormes::ActiviteFormes(string p){
	Activite("ActiviteFormes",p);

}

void ActiviteFormes::launch(){
	// faire une forme
//	m->afficherMessage("faire un carre");
	// lancer of
	of = new Of();
	of->lancementOf();
	lancerOsc();
	// osc

	// processing
//	Processing *proc = new Processing();
//	proc->lancementProcessing();
}

void ActiviteFormes::lancerOsc(){
	ExamplePacketListener listener;

	UdpListeningReceiveSocket s(

			IpEndpointName( IpEndpointName::ANY_ADDRESS, PORT ),

			&listener );    

	listener.setS(&s);
	listener.setActivite(this);
	s.Run();
}


void ActiviteFormes::update(string classLabel){
	if(classLabel == "1"){
		cout<<"success!!";
		wellDone=true;
	}else{
		cout<<"echec!!";

	}
}

void ActiviteFormes::killOf(){
	of->killOf();
}





