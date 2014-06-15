#ifndef DEF_SHAPEACTIVITY
#define DEF_SHAPEACTIVITY

#include "Activity.hpp"
#include <string>
#include "../../Controller/Kinect/Processing.hpp"
#include <gtkmm/messagedialog.h>

class ShapeActivity : public Activity {
		public: 
			ShapeActivity(string p, int nbE) : Activity("ActiviteForme", p, nbE){};
			virtual void init();
			virtual void exec();
			virtual void closeAct();
			void update(string classLabel);

		private:
			//void lancerOsc(int classLabel);
};

#endif
