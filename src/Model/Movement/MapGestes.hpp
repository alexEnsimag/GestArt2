#ifndef MAPGESTES_H
#define MAPGESTES_H	
#include <string>
#include <map>

class MapGestes{
	public:
		//MapGestes(); 
		static void addGest(std::string name, int number);
		static void enregistrementGeste(std::string name);
		static std::string getGestByKey(int key);	
		static int getGestByName(std::string name);
		static void addGestesFile();

		static const std::string gestFileName;
};
#endif
