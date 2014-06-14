
#include "ActiviteTestMouv.hpp"
#include "ActiviteInfo.hpp"

using namespace std;


void ActiviteTestMouv::testerMouvement(string texteField){
	duration = DUR_TEST_MOUV;
	wellDone = false;
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


