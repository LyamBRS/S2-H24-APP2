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

Canevas* MonInterface::GetCanevas()
{
	return &c;
}

void MonInterface::reinitialiserCanevas()
{
	std::ostringstream os;
		
	c.reinitialiser();
	std::cout << os.str() << std::endl;
	updateConsole();
	dessiner(os.str().c_str());
}

bool MonInterface::ouvrirFichier(const char*document)
{
	// Open the text file

	c.reinitialiser();
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
	std::cout << document << std::endl;
	ofstream outFile;
	outFile.open(document);

	if (outFile.is_open()) 
	{
		outFile << c;
		outFile.close();
		
	}
	else return false;
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
	c.modePile = mode;
	updateGUI();
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
	int oldIndex = c.GetIndexCoucheActive();
	c.retirerCouche();
	c.activerCouche(oldIndex);
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
	ajustementInformation();
	setInformations(info);
}

void MonInterface::updateConsole()
{
	system("cls");
	std::cout << std::endl;
	std::cout << c;
	c.afficher(std::cout);
}

void MonInterface::ajustementInformation()
{

	Couche* couche = c.ObtenirCoucheCourant();
	Forme* f = c.ObtenirFormeCourant();

	if (f != NULL)
	{
		info.aireForme = f->aire();

		Coordonnee coordonne = f->getAncrage();
		info.coordX = coordonne.x;
		info.coordY = coordonne.y;

		std::ostringstream os2;
		f->afficher(os2);

		///cout << endl << "info forme: ";
		for (int i = 0; i < 50; i++)
		{
			if (i >= os2.str().length())
			{
				info.informationForme[i] = '\0';
			}
			else
			{
				info.informationForme[i] = os2.str()[i];
			}
			//cout << os2.str()[i];
			
		}
		

		info.formeActive = c.GetIndexFormeActive();
	}

	info.aireCanevas = c.aire();
	info.aireCouche = couche->AireCouche();
	

	info.coucheActive = c.GetIndexCoucheActive(); 

	std::ostringstream os;
	couche->AfficherCoucheSeulement(os);

	//cout << "info couche: ";
	for (int i = 0; i < 20; i++)
	{
		if (i >= os.str().length())
		{
			info.etatCouche[i] = '\0';
		}
		else
		{
			info.etatCouche[i] = os.str()[i];
		}
		//cout << os.str()[i];
	}
	

	info.nbCouches = c.NombreDeCouches();
	

	int nbForme = 0;
	for (int i = 0; i < c.NombreDeCouches(); i++)
	{
		nbForme += c.coucheAIndex(i)->NombreDeFormes();
	}
	info.nbFormesCanevas = nbForme;

	info.nbFormesCouche = couche->NombreDeFormes();
}
