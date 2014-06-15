#ifndef DEF_Activity
#define DEF_Activity

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <fstream>
//#include <sstream>
#include <string>
#include <vector>

#include "../../View/Interface/Window.hpp"
#include "../../Controller/Video/Video.hpp"

#include "../../Model/Movement/GesturesMap.hpp"

class Activity {
	public:
		Activity(std::string n, std::string p,int nb);
		virtual ~Activity(){}
		std::string getName();
		std::string getParam();
		std::string toString();
		int getTrialsNumber();
		int getDuree();
		void decrementTrialsNumber();
		bool getWellDone();
		void setWellDone(bool b);
		virtual void init();
		void launch();
		virtual void exec();
		virtual void closeAct();
		void displayMessage(std::string s);
		int getDuration();
	protected:
		bool wellDone;
		int duration; // duree de l'Activite avant qu'elle soit considérée comme ratée, durée en ms
	private:
		int trialsNumber;
		std::string name;
		std::string param;
		int duree;
		void chargerDuree();
		
};
#endif
