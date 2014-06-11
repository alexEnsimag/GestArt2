#ifndef DEF_ACTIVITEFORMES
#define DEF_ACTIVITEFORMES

#include "Activite.hpp"
#include <string>
#include "../../Controler/Kinect/Of.hpp"
#include "../../Controler/Kinect/Processing.hpp"
#include <gtkmm/messagedialog.h>

class ActiviteForme : public Activite {
		public: 
			//ActiviteForme(string p, int nbE);
			ActiviteForme(string p, int nbE) : Activite("ActiviteFormes",p, nbE){};
		        virtual	void launch();
			void update(string classLabel);
			void killOf();
			
		static const vector<string> possibleParams;
		static int getParamSize(){
			return possibleParams.size();
		}

		private:
			Of *of;
			void lancerOsc();

};

#endif
