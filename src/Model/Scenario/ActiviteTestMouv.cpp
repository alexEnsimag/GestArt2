
#include "ActiviteTestMouv.hpp"

using namespace std;


void ActiviteTestMouv::testerMouvement(string texteField){
	setWellDone(false);
	int key = MapGestes::getGestByName(texteField);
	if(key == -1) {
		cout << "Geste inexistant" << endl;
		return;		
	} else {

		cout << "ClassLabel du geste : " << key << endl;		
		Of *of = new Of();
		of->lancementOfRecognize(); 


		Osc *ocs = new Osc();
		ocs->lancerOsc(key, this); 
	}

}


