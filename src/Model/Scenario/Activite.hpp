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
		int getEssais();
		bool getWellDone();
		virtual void launch();
		
		vector<string> possibleParams;
	private:
		string name;
		string param;
	protected:
		bool wellDone;
		int nbEssai;
		
};
#endif
