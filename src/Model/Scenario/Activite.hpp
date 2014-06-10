#ifndef DEF_ACTIVITE
#define DEF_ACTIVITE

#include <string>
using namespace std;

class Activite {
	public:
		Activite(string n, string p);
		string getName();
		string getParam();
		
	private:
		string name;
		string param;
};
#endif
