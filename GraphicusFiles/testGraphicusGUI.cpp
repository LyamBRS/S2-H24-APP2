/********
* Fichier: testGraphicusGUI.cpp
* Auteurs: C.-A. Brunet
* Date: 10 janvier 2024
* Description: Ce programme teste l'interface usager GraphicusGUI.
*
* Copyright 2024 Département de génie électrique et génie informatique
*                Université de Sherbrooke  
********/

#include <QApplication>
#include "monInterface.h"
#include "../GraphicusSources/tests.h"

int main( int argc, char ** argv )
{
	QApplication app(argc, argv);
	MonInterface gui("TestGraphicusGUI 1.0");

	Tests tests = Tests();
	// ATTENTION, SI VOUS NE COMMENTEZ PAS L'INTÉRIEUR DE MonInterface.updateConsole() AVANT DE DÉCOMMENTER CES TESTS, LE PROGRAM VAS PRENDRE 30 SEC+ À ROULER!
	//tests.tests_application_cas_02(&gui); // POUR ROULER LE TEST AUTOMATIQUE D'AFFICHAGE' NE PAS OUBLIÉ DE METTRE EN COMMENTAIRE LE CONTENUE DE MonInterface.updateConsole. SANS QUOI LE RESULTAT DU TEST SERA RESET DANS LA CONSOLE (affichage graphique affiche le bon resultat pareil)
	//tests.tests_unitaires();				// 240 TESTS UNITAIRE
	//tests.tests_unitaires_vecteur();		// JUSTE LES VECTEURS (118 tests)
	return app.exec();
}
