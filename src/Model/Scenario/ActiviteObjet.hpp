
#ifndef DEF_ACTIVITEOBJET
#define DEF_ACTIVITEOBJET

#include "Activite.hpp"


	class ActiviteObjet : Activite {
		public: 
			ActiviteObjet(string p) : Activite("ActiviteObjet",p){};
			void launch();

		private:
	};
			 
#endif
