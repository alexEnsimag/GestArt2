#ifndef DEF_ACTIVITEFORMES
#define DEF_ACTIVITEFORMES

#include "Activite.hpp"
#include <string>
#include "../../Controler/Kinect/Of.hpp"
#include "../../Controler/Kinect/Processing.hpp"
#include <gtkmm/messagedialog.h>

class ActiviteForme : public Activite {
		public: 
			ActiviteFormes(string p);
			//ActiviteFormes(string p) : Activite("ActiviteFormes",p){};
		        virtual	void launch();
			void update(string classLabel);
			void killOf();
			
		static const vector<string> possibleParams;
		static int getParamSize(){

		private:
			Of *of;
			void lancerOsc();

};

#endif
