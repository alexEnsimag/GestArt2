#ifndef DEF_ACTIVITE
#define DEF_ACTIVITE

#include <iostream>
#include <string>
using namespace std;

class Activite {
	public:
		Activite(string n, string p);
		string getName();
		string getParam();
		bool getWellDone();
		void setWellDone(bool b);
		virtual void launch();
		
	private:
		string name;
		string param;
	protected:
		bool wellDone;
};
#endif
