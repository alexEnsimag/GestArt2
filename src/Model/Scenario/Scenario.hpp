#ifndef DEF_SENARIO
#define DEF_SENARIO

#include "ActiviteFormes.hpp"
#include "ActiviteObjet.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;
#include <vector>
#include <string>

class Scenario{
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
		void addActivite(Activite *a);

		//Permet de récuperer le nom de sénario
		string getName();

		//Permet de changer le nom du sénario
		void setName(string s);

		//Permet de récuperer le nombre d'activité
		int getNbActivite();

		//Permet de récuperer l'activité n°i
		Activite* getActivite(int i);

		//Permet de lancer le scénario
		void launch();
		
		//Permet de supprimer une activité au sénario
		void removeActivite(int i);
	private:
		string name;
		vector<Activite*> activites;

};
#endif
