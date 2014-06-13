#ifndef DEF_ACTIVITEFORMES
#define DEF_ACTIVITEFORMES

#include "Activite.hpp"
#include <string>
#include "../../Controler/Kinect/Processing.hpp"
#include <gtkmm/messagedialog.h>

class ActiviteForme : public Activite {
		public: 
			ActiviteForme(string p, int nbE) : Activite("ActiviteForme", p, nbE){};
			virtual void init();
			virtual void exec();
			virtual void closeAct();
			void update(string classLabel);

		private:
			//void lancerOsc(int classLabel);
};

#endif
