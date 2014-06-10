#ifndef DEF_SENARIO
#define DEF_SENARIO

#include "Activite.hpp"

using namespace std;
#include <vector>
#include <string>

class Senario{
	public:
		/*
		 *Cette fonction enregistre tout les paramètres 
		 *du sénario dans un fichier. 
		 */
		void enregistrer();

		/*
		 *Cette fonction rempli le sénario avec des activites et 
		 *un nom issus d'un fichier.
		 */
		void charger(string nomFichier);

		//Permet d'ajouter une activite au sénario
		void addActivite(Activite a);
		//Permet de récuperer le nom de sénario
		string getName();
		//Permet de changer le nom du sénario
		void setName(string s);
	private:
		string name;
		vector<Activite> activites;

};
#endif
