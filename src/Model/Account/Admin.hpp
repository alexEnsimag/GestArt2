#ifndef ADMIN_H
#define ADMIN_H	
#include <string>
using namespace std;
#include <map>
//#include <pair>
class Admin{
	public:
		Admin(string id, string mdp); 
		void addGest(string name, int number);
		
	private:	
		string identifiant;
		string motDePasse;
		string gestFileName;
		std::map<int, string> gests;
};
#endif
