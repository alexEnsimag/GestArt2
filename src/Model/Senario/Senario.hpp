#ifndef DEF_SENARIO
#define DEF_SENARIO

#include "Activite.hpp"

using namespace std;
#include <vector>

class Senario{
	public:
		void addActivite(Activite a);
	private:
		vector<Activite> activites;

};
#endif
