#ifndef DEF_SENARIO
#define DEF_SENARIO

#include "ShapeActivity.hpp"
#include "ObjectActivity.hpp"
#include "../../Controller/Kinect/Of.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

#include "../../Controller/Video/Video.hpp"

#include <vector>
#include <string>

class Scenario{
	public:
		/*
		 *Cette fonction enregistre tout les paramètres 
		 *du sénario dans un fichier. 
		 */
		void record();

		/*
		 *Cette fonction rempli le sénario avec des activites et 
		 *un nom issus d'un fichier.
		 */
		void load(std::string fileName);

		//Permet d'ajouter une activite au sénario
		void addActivite(Activity *a);

		//Permet de récuperer le nom de sénario
		std::string getName();

		//Permet de changer le nom du sénario
		void setName(std::string s);

		//Permet de récuperer le nombre d'activité
		int getNbActivities();

		//Permet de récuperer l'activité n°i
		Activity* getActivity(int i);

		//Permet de lancer le scénario
		void launch();
		
		//Permet de supprimer une activité au sénario
		void removeActivity(int i);
	private:
		Of *of;
		std::string name;
		std::vector<Activity*> activities;
		void killOf();

};
#endif
