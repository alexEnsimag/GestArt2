#ifndef GESTURESMAP_H
#define GESTURESMAP_H	
#include <string>
#include <map>

class GesturesMap{
	public:
		//GesturesMap(); 
		static void addGest(std::string name, int number);
		static void recordGeste(std::string name);
		static std::string getGestByKey(int key);	
		static int getGestByName(std::string name);
		static void addGestesFile();

		static const std::string gestFileName;
};
#endif
