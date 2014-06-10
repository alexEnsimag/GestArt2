
#ifndef DEF_ACTIVITEFORMES
#define DEF_ACTIVITEFORMES

#include "Activite.hpp"


	class ActiviteFormes : Activite {
		public: 
			ActiviteFormes(string p) : Activite("ActiviteFormes",p){};
			void launch();

		private:
	};
			 
#endif
