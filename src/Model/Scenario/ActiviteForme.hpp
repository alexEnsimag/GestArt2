#ifndef DEF_ACTIVITEFORMES
#define DEF_ACTIVITEFORMES

#include "Activite.hpp"
#include <string>
#include "../../Controler/Kinect/Of.hpp"
#include "../../Controler/Kinect/Processing.hpp"
#include <gtkmm/messagedialog.h>

class ActiviteForme : public Activite {
		public: 
			ActiviteForme(string p, int nbE) : Activite("ActiviteForme", p, nbE){};
			virtual void init();
			virtual void exec();
			virtual void close();
			void update(string classLabel);
			void killOf();
/*			
		static const vector<string> possibleParams;
		static int getParamSize(){
			return possibleParams.size();
		}
*/

		private:
			Of *of;
			void lancerOsc();
};

#endif
