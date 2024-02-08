/********
* Fichier: monInterface.h
* Auteurs: C.-A. Brunet
* Date: 10 janvier 2024
* Description: La classe MonInterface teste l'interface usager GraphicusGUI.
*
* Copyright 2024 Département de génie électrique et génie informatique
*                Université de Sherbrooke  
********/

#ifndef MONINTERFACE_H
#define MONINTERFACE_H

#include "graphicusGUI.h"
#include "../GraphicusSources/canevas.h"

class MonInterface : public GraphicusGUI
{
private:
	Informations info;
	Canevas c;
	void updateGUI();
	void updateConsole();
	void ajustementInformation();
public:
	MonInterface(const char *theName = nullptr);
	bool ouvrirFichier(const char*);
	bool sauvegarderFichier(const char*);
	void coucheTranslater(int deltaX, int deltaY);
	void ajouterCercle(int x, int y, int rayon);
	void ajouterRectangle(int x, int y, int longueur, int largeur);
	void ajouterCarre(int x, int y, int cote);
	void modePileChange(bool mode);

	Canevas* GetCanevas();
public slots:
	// Menu Canevas
	void reinitialiserCanevas();
	void coucheAjouter();
	void coucheRetirer();
	// Menu Formes
	void retirerForme();
	// Menu navigation
	void couchePremiere();
	void couchePrecedente();
	void coucheSuivante();
	void coucheDerniere();
	void formePremiere();
	void formePrecedente();
	void formeSuivante();
	void formeDerniere();
};

#endif // MONINTERFACE_H