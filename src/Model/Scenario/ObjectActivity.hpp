
#ifndef DEF_OBJECTACTIVITY
#define DEF_OBJECTACTIVITY

#include "Activity.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


class ObjectActivity : public Activity {
	public: 
		ObjectActivity(std::string p, int nb) : Activity("ActiviteObjet",p, nb){}
		virtual void init();
		virtual void exec();
		virtual void closeAct();

	private:
};

#endif
