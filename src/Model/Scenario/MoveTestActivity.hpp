
#ifndef DEF_MOVETESTACTIVITY
#define DEF_MOVETESTACTIVITY

#include "Activity.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "../../View/Interface/Dialogue.hpp"
#include "../../Controller/Kinect/Osc.hpp"
#include "../../Controller/Kinect/Of.hpp"


class MoveTestActivity : Activity{
	public: 
		MoveTestActivity() : Activity("ActiviteTestMouv", "", 0){};
		void tryGesture(std::string gestureName);
		virtual void init(){};
		virtual void exec(){};
		virtual void closeAct(){};
		void launch() { cout << "Activite Test, ne peut etre lancee !" << endl; };
	private:
};

#endif
