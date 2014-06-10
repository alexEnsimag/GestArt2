#ifndef DEF_ACTIVITEFORMES
#define DEF_ACTIVITEFORMES

#include "Activite.hpp"


class ActiviteForme : public Activite {
	public: 
		ActiviteForme(string p,int nb) : Activite("ActiviteForme",p, nb){};
		virtual void launch();
		static const vector<string> possibleParams;
		static int getParamSize(){
			return possibleParams.size();
		}
	private:
};

#endif
