
#include "MoveTestActivity.hpp"
#include "InfoActivity.hpp"

using namespace std;


void MoveTestActivity::tryGesture(string textField){
	duration = DUR_TEST_MOV;
	wellDone = false;
	int key = GesturesMap::getGestByName(textField);
	if(key == -1) {
		cout << "Geste inexistant" << endl;
		return;		
	} else {

		cout << "ClassLabel du geste : " << key << endl;		
		Of *of = new Of();
		of->launchOfRecognize(); 


		Osc *ocs = new Osc();
		ocs->launchOsc(key, this); 
	}

}


