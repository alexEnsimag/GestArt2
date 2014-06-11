#ifndef DEF_SENARIO
#define DEF_SENARIO

#include "ActiviteForme.hpp"
#include "ActiviteObjet.hpp"
#include "../../Controler/Kinect/Of.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

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
		void charger(std::string nomFichier);

		//Permet d'ajouter une activite au sénario
		void addActivite(Activite *a);

		//Permet de récuperer le nom de sénario
		std::string getName();

		//Permet de changer le nom du sénario
		void setName(std::string s);

		//Permet de récuperer le nombre d'activité
		int getNbActivite();

		//Permet de récuperer l'activité n°i
		Activite* getActivite(int i);

		//Permet de lancer le scénario
		void launch();
		
		//Permet de supprimer une activité au sénario
		void removeActivite(int i);
	private:
		Of *of;
		std::string name;
		std::vector<Activite*> activites;

};
#endif
