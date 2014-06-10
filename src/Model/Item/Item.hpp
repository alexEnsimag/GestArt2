#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Item {
	public :
		Item( string name, string imageFileName, string qrFileName,string audioFileName);
		 /*cette fonction sert à créer, ou modidier le fichier ayant pour nom qrFileName pour qu'il contienne le qr code associé à l'objet*/  
		void qrEncode ();
		string getName();
	private: 
		string name;
		string imageFileName;
    		string qrFileName;
    		string audioFileName;
};

#endif
