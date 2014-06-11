#ifndef DEF_GAME
#define DEF_GAME

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include "../../Model/Scenario/Scenario.hpp"

#ifndef WIN32
	#include <sys/types.h>
#endif

class Game{
	public:
		Game();
		int getNbScenar();
		Scenario* getScenar(int i);
		void launch(int i);
		void updateScenar();
		void delScenar(int i);

	private:	
		std::vector<Scenario> scenar;
};

#endif
