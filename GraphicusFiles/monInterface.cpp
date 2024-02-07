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
#include "../GraphicusSources/canevas.h"
#include "../GraphicusSources/Couche.h"
#include "../GraphicusSources/forme.h"
#include "../GraphicusSources/Carre.h"
#include "../GraphicusSources/Cercle.h"
#include "../GraphicusSources/Rectangle.h"

MonInterface::MonInterface(const char* theName) : GraphicusGUI(theName)
{
	reinitialiserCanevas();
	effacerInformations();
}

void MonInterface::reinitialiserCanevas()
{
	std::ostringstream os;
	random_device r;
	default_random_engine generator(r());
	uniform_int_distribution<int> coor(0, 300), dim(20, 100);

	// On s'amuse à générer aléatoirement un canevas en format texte à chaque
	// fois que la commande de réinitialisation de canevas est choisie par l'usager.
	os << "L x" << std::endl;
	//os << "R " << coor(generator) << " " << coor(generator) << " " << dim(generator) << " " << dim(generator) << std::endl;
	//os << "K " << coor(generator) << " " << coor(generator) << " " << dim(generator) << std::endl;
	os << "L a" << std::endl;
	//os << "K " << coor(generator) << " " << coor(generator) << " " << dim(generator) << std::endl;
	os << "C " << coor(generator) << " " << coor(generator) << " " << dim(generator) << std::endl;
	os << "L x" << std::endl;
	//os << "R " << coor(generator) << " " << coor(generator) << " " << dim(generator) << " " << dim(generator) << std::endl;
	//os << "C " << coor(generator) << " " << coor(generator) << " " << dim(generator) << std::endl;
	//os << "L x" << std::endl;
	//os << "R " << coor(generator) << " " << coor(generator) << " " << dim(generator) << " " << dim(generator) << std::endl;
	//os << "K " << coor(generator) << " " << coor(generator) << " " << dim(generator) << std::endl;
	os << "C " << coor(generator) << " " << coor(generator) << " " << dim(generator) << std::endl;

	// Ensuite, on dessine ce qui a été généré dans Graphicus

	std::cout << os.str() << std::endl;
	updateConsole();
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
	c.translater(deltaX, deltaY);
}
void MonInterface::ajouterCercle(int x, int y, int rayon)
{
	c.ajouterForme(new Cercle(x,y,rayon));
	//updateUI();
}
void MonInterface::ajouterRectangle(int x, int y, int longueur, int largeur)
{
	
	c.ajouterForme(new Rectangle(x, y, longueur, largeur));
}
void MonInterface::ajouterCarre(int x, int y, int cote)
{
	
	c.ajouterForme(new Carre (x, y, cote));
}
void MonInterface::modePileChange(bool mode)
{

}


	// Menu Canevas
void MonInterface::coucheAjouter()
{
	
	c.ajouterCouche(new Couche());
}
void MonInterface::coucheRetirer()
{
	//chercher couche active
	//detruire la couche
	//c.retirerCouche(c.NombreDeCouches());
	//std::cout << c;
}


	// Menu Formes
void MonInterface::retirerForme()
{
	//forme selectionner
	//retirer
}
	// Menu navigation
void MonInterface::couchePremiere()
{
	c.ChoisirCouche(0);
}
void MonInterface::couchePrecedente()
{
	c.CouchePrecedente();
}
void MonInterface::coucheSuivante()
{
	c.CoucheSuivante();
}
void MonInterface::coucheDerniere()
{
	c.CoucheDerniere();
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


void MonInterface::updateUI()
{
	std::ostringstream os;

	os << c;

	std::cout << os.str() << std::endl;
	dessiner(os.str().c_str());
}

void MonInterface::updateConsole()
{
	system("cls");
	c.afficher(std::cout);
}
