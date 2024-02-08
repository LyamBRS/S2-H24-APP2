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
#include <fstream>
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
	//os << "L x" << std::endl;
	//os << "R " << coor(generator) << " " << coor(generator) << " " << dim(generator) << " " << dim(generator) << std::endl;
	//os << "K " << coor(generator) << " " << coor(generator) << " " << dim(generator) << std::endl;
	//os << "L a" << std::endl;
	//os << "K " << coor(generator) << " " << coor(generator) << " " << dim(generator) << std::endl;
	//os << "C " << coor(generator) << " " << coor(generator) << " " << dim(generator) << std::endl;
	//os << "L x" << std::endl;
	//os << "R " << coor(generator) << " " << coor(generator) << " " << dim(generator) << " " << dim(generator) << std::endl;
	//os << "C " << coor(generator) << " " << coor(generator) << " " << dim(generator) << std::endl;
	//os << "L x" << std::endl;
	//os << "R " << coor(generator) << " " << coor(generator) << " " << dim(generator) << " " << dim(generator) << std::endl;
	//os << "K " << coor(generator) << " " << coor(generator) << " " << dim(generator) << std::endl;
	//os << "C " << coor(generator) << " " << coor(generator) << " " << dim(generator) << std::endl;

	// Ensuite, on dessine ce qui a été généré dans Graphicus
	c.reinitialiser();
	std::cout << os.str() << std::endl;
	updateConsole();
	dessiner(os.str().c_str());
}

bool MonInterface::ouvrirFichier(const char*document)
{
	// Open the text file
	
	std::ifstream file;

	file.open(document, ios::in);

	// Check if the file is opened successfully
	if (!file.is_open()) {
		std::cerr << "Failed to open the file." << std::endl;
		return 1;
	}

	// Read the contents of the file into a string
	std::ostringstream oss;
	oss << file.rdbuf();

	string s = oss.str();
	istringstream os(s);
	
	os >> c;
	

	
	updateConsole();
	// Close the file
	file.close();

	updateGUI();
	//dessiner(oss.str().c_str());

	
	return true;
}
bool MonInterface::sauvegarderFichier(const char* document)
{
	return true;
}
void MonInterface::coucheTranslater(int deltaX, int deltaY)
{
	c.translater(deltaX, deltaY);
	updateConsole();
	updateGUI();
}
void MonInterface::ajouterCercle(int x, int y, int rayon)
{
	c.ajouterForme(new Cercle(x,y,rayon));
	updateConsole();
	updateGUI();
}
void MonInterface::ajouterRectangle(int x, int y, int longueur, int largeur)
{
	c.ajouterForme(new Rectangle(x, y, longueur, largeur));
	updateConsole();
	updateGUI();
}
void MonInterface::ajouterCarre(int x, int y, int cote)
{
	c.ajouterForme(new Carre (x, y, cote));
	updateConsole();
	updateGUI();
}
void MonInterface::modePileChange(bool mode)
{

}


	// Menu Canevas
void MonInterface::coucheAjouter()
{
	c.ajouterCouche(new Couche());
	updateConsole();
	updateGUI();
}
void MonInterface::coucheRetirer()
{
	c.retirerCouche();
	updateConsole();
	updateGUI();
}


	// Menu Formes
void MonInterface::retirerForme()
{
	//forme selectionner
	//retirer
	c.retirerForme();
	updateConsole();
	updateGUI();
}
	// Menu navigation
void MonInterface::couchePremiere()
{
	c.ChoisirCouche(0);
	updateConsole();
	updateGUI();
}
void MonInterface::couchePrecedente()
{
	c.CouchePrecedente();
	updateConsole();
	updateGUI();
}
void MonInterface::coucheSuivante()
{
	c.CoucheSuivante();
	updateConsole();
	updateGUI();
}
void MonInterface::coucheDerniere()
{
	c.CoucheDerniere();
	updateConsole();
	updateGUI();
}
void MonInterface::formePremiere()
{
	c.ChoisirForme(0);
	updateConsole();
	updateGUI();
}
void MonInterface::formePrecedente()
{
	c.FormePrecedente();
	updateConsole();
	updateGUI();
}
void MonInterface::formeSuivante()
{
	c.FormeSuivante();
	updateConsole();
	updateGUI();
}
void MonInterface::formeDerniere()
{
	c.FormeDerniere();
	updateConsole();
	updateGUI();
}


void MonInterface::updateGUI()
{
	std::ostringstream os;

	os << c;

	//std::cout << os.str() << std::endl;
	dessiner(os.str().c_str());
}

void MonInterface::updateConsole()
{
	system("cls");
	std::cout << std::endl;
	std::cout << c;
	c.afficher(std::cout);
}
