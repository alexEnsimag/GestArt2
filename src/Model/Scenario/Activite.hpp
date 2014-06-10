#ifndef DEF_ACTIVITE
#define DEF_ACTIVITE

#include <string>
using namespace std;

class Activite {
	public:
		Activite(string n, string p);
		string getName();
		string getParam();
		bool getWellDone();
		void setWellDone(bool b);
		void launch();
		
	private:
		string name;
		string param;
		bool wellDone;
};
#endif
