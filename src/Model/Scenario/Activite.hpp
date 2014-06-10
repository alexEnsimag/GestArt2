#ifndef DEF_ACTIVITE
#define DEF_ACTIVITE

#include <iostream>
#include <string>
using namespace std;

class Activite {
	public:
		Activite(string n, string p,int nb);
		string getName();
		string getParam();
		string toString();
		bool getWellDone();
		virtual void launch();
		
	private:
		string name;
		string param;
	protected:
		bool wellDone;
		int nbEssai;
		
};
#endif
