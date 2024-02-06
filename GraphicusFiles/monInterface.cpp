/********
* Fichier: monInterface.cpp
* Auteurs: C.-A. Brunet
* Date: 10 janvier 2024
* Description: Voir fichier d'entête pour informations.
*
* Copyright 2024 Département de génie électrique et génie informatique
*                Université de Sherbrooke  
********/

#include <random>
#include <sstream>
#include "monInterface.h"

using namespace std;

MonInterface::MonInterface(const char* theName) : GraphicusGUI(theName)
{
	reinitialiserCanevas();
	effacerInformations();
}

void MonInterface::reinitialiserCanevas()
{
	ostringstream os;
	random_device r;
	default_random_engine generator(r());
	uniform_int_distribution<int> coor(0, 300), dim(20, 100);

	// On s'amuse à générer aléatoirement un canevas en format texte à chaque
	// fois que la commande de réinitialisation de canevas est choisie par l'usager.
	os << "L x" << endl;
	os << "R " << coor(generator) << " " << coor(generator) << " " << dim(generator) << " " << dim(generator) << endl;
	os << "K " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
	os << "L a" << endl;
	os << "K " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
	os << "C " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
	os << "L x" << endl;
	os << "R " << coor(generator) << " " << coor(generator) << " " << dim(generator) << " " << dim(generator) << endl;
	os << "C " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
	os << "L x" << endl;
	os << "R " << coor(generator) << " " << coor(generator) << " " << dim(generator) << " " << dim(generator) << endl;
	os << "K " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
	os << "C " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;

	// Ensuite, on dessine ce qui a été généré dans Graphicus
	dessiner(os.str().c_str());
}



bool MonInterface::ouvrirFichier(const char*)
{
	return true;
}
bool MonInterface::sauvegarderFichier(const char*)
{
	return true;
}
void MonInterface::coucheTranslater(int deltaX, int deltaY)
{

}
void MonInterface::ajouterCercle(int x, int y, int rayon)
{

}
void MonInterface::ajouterRectangle(int x, int y, int longueur, int largeur)
{

}
void MonInterface::ajouterCarre(int x, int y, int cote)
{

}
void MonInterface::modePileChange(bool mode)
{

}


	// Menu Canevas
void MonInterface::coucheAjouter()
{

}
void MonInterface::coucheRetirer()
{

}
	// Menu Formes
void MonInterface::retirerForme()
{

}
	// Menu navigation
void MonInterface::couchePremiere()
{

}
void MonInterface::couchePrecedente()
{

}
void MonInterface::coucheSuivante()
{

}
void MonInterface::coucheDerniere()
{

}
void MonInterface::formePremiere()
{

}
void MonInterface::formePrecedente()
{

}
void MonInterface::formeSuivante()
{

}
void MonInterface::formeDerniere()
{

}
