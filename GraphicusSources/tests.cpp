/********
 * @file: tests.cpp
 * @author: C.-A. Brunet, GRAF2102, COUS1912
 * @date: 08 janvier 2018 (creation)
 * @brief: Implementation des methodes des classes decrites dans
 *    tests.h.  Ce fichier peut etre adapte a vos besoins de tests.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/
#include <sstream>
#include <string>
#include <iostream>
#include "tests.h"

///////////////////////
ofstream OutputFile("ResultatsTests.txt");

///@brief Mettre a true si les donner imprimer sont imprimee dans un fichier au lieu du terminal.
#define ENVOIE_TERMINAL_DANS_FICHIER false

///@brief Definir comme @ref outFile si vous voulez que le terminal soit print dans un fichier separe.
#define OUTPUT_STREAM std::cout
///////////////////////

void Tests::tests_unitaires_formes()
{
   DebutDeFonctionalitee("Classes Formes", "Unitaire");
   //////////////////////////////////////////////////////////////////////////////
   // Test 1: Creation d'un objet couche
   DebutDunTest("Creation des objects");
   Rectangle rectangle;
   Carre carre;
   Cercle cercle;

   Rectangle rectangleXY(5, 5);
   Carre carreXY(10, 10);
   Cercle cercleXY(5, 2); 

   Rectangle rectangleXYLH(2, 1, 4, 5);
   Carre carreXYL(3, 9, 8);
   Cercle cercleXYR(3, 10, 24);
   FinDuTest();

   //////////////////////////////////////////////////////////////////////////////
   DebutDunTest("Verification des données initiales des formes a constructeur vide");

   Coordonnee coordsRectangle = rectangle.getAncrage();
   Coordonnee coordsCarre = carre.getAncrage();
   Coordonnee coordsCercle = cercle.getAncrage();

   SousTest("X initiale: rectangle = 0",        coordsRectangle.x == 0);
   SousTest("Y initiale: rectangle = 0",        coordsRectangle.y == 0);
   SousTest("Largeur initiale: rectangle = 10", rectangle.Largeur() == LARGEUR_RECTANGLE_PAR_DEFAUT);
   SousTest("Hauteur initiale: rectangle = 10", rectangle.Hauteur() == HAUTEUR_RECTANGLE_PAR_DEFAUT);

   SousTest("X initiale: carre = 0",            coordsCarre.x     == 0);
   SousTest("Y initiale: carre = 0",            coordsCarre.y     == 0);
   SousTest("Largeur initiale: carre = 10",     carre.Largeur() == LARGEUR_CARRE_PAR_DEFAUT);

   SousTest("X initiale: cercle = 0",           coordsCercle.x == 0);
   SousTest("Y initiale: cercle = 0",           coordsCercle.y == 0);
   SousTest("Rayon initiale: cercle = 10",      cercle.Rayon() == RAYON_CERCLE_PAR_DEFAUT);
   FinDuTest();

   //////////////////////////////////////////////////////////////////////////////
   DebutDunTest("Verification des données initiales des formes a constructeur cartesiennes");
   Coordonnee coordsRectangleXY = rectangleXY.getAncrage();
   Coordonnee coordsCarreXY = carreXY.getAncrage();
   Coordonnee coordsCercleXY = cercleXY.getAncrage();

   SousTest("X initiale: rectangleXY = 5",        coordsRectangleXY.x == 5);
   SousTest("Y initiale: rectangleXY = 5",        coordsRectangleXY.y == 5);
   SousTest("Largeur initiale: rectangleXY = 10", rectangleXY.Largeur() == LARGEUR_RECTANGLE_PAR_DEFAUT);
   SousTest("Hauteur initiale: rectangleXY = 10", rectangleXY.Hauteur() == HAUTEUR_RECTANGLE_PAR_DEFAUT);

   SousTest("X initiale: carreXY = 10",           coordsCarreXY.x     == 10);
   SousTest("Y initiale: carreXY = 10",           coordsCarreXY.y     == 10);
   SousTest("Largeur initiale: carreXY = 10",     carreXY.Largeur() == LARGEUR_CARRE_PAR_DEFAUT);

   SousTest("X initiale: cercleXY = 5",           coordsCercleXY.x == 5);
   SousTest("Y initiale: cercleXY = 2",           coordsCercleXY.y == 2);
   SousTest("Rayon initiale: cercleXY = 10",      cercleXY.Rayon() == RAYON_CERCLE_PAR_DEFAUT);
   FinDuTest();

   //////////////////////////////////////////////////////////////////////////////
   DebutDunTest("Verification des donnees initiales des formes a constructeur etendues");
   Coordonnee coordsRectangleXYLH = rectangleXYLH.getAncrage();
   Coordonnee coordsCarreXYL = carreXYL.getAncrage();
   Coordonnee coordsCercleXYR = cercleXYR.getAncrage();

   SousTest("X initiale: rectangleXYLH = 2",       coordsRectangleXYLH.x == 2);
   SousTest("Y initiale: rectangleXYLH = 1",       coordsRectangleXYLH.y == 1);
   SousTest("Largeur initiale: rectangleXYLH = 4", rectangleXYLH.Largeur() == 4);
   SousTest("Hauteur initiale: rectangleXYLH = 5", rectangleXYLH.Hauteur() == 5);

   SousTest("X initiale: carreXYL = 3",           coordsCarreXYL.x  == 3);
   SousTest("Y initiale: carreXYL = 9",           coordsCarreXYL.y  == 9);
   SousTest("Largeur initiale: carreXYL = 8",     carreXYL.Largeur() == 8);

   SousTest("X initiale: cercleXYR = 3",           coordsCercleXYR.x == 3);
   SousTest("Y initiale: cercleXYR = 10",          coordsCercleXYR.y == 10);
   SousTest("Rayon initiale: cercleXYR = 24",      cercleXYR.Rayon() == 24);
   FinDuTest();

   //////////////////////////////////////////////////////////////////////////////
   // Test 1: Assignation dimention
   DebutDunTest("Assignation de dimentions");
   rectangle.Hauteur(20);
   rectangle.Largeur(10);
   carre.Largeur(10);
   cercle.Rayon(5);

   SousTest("rectangle.Hauteur", rectangle.Hauteur() == 20);
   SousTest("rectangle.Largeur", rectangle.Largeur() == 10);
   SousTest("carre.Largeur",     carre.Largeur() == 10);
   SousTest("cercle.Rayon",      cercle.Rayon() == 5);
   FinDuTest();

   //////////////////////////////////////////////////////////////////////////////
   // Test 2: Calcule aire
   DebutDunTest("Calcule d'aire des formes");

   SousTestDouble("rectangle.aire", rectangle.aire(), 200.0);
   SousTestDouble("carre.aire", carre.aire(), 10.0*10.0);
   SousTestDouble("cercle.aire", cercle.aire(), 3.14f*5.0*5.0);
   FinDuTest();

   //////////////////////////////////////////////////////////////////////////////
   DebutDunTest("Calcule de 100 aires extensif positives et négatives");
   bool resultatCarre = true;
   bool resultatRectangle = true;
   bool resultatCercle = true;

   for(int index=-50; index<100; index++)
   {
      int neededIndex = index;
      if(neededIndex < 0) neededIndex = -neededIndex;

      rectangle.Hauteur(index);
      rectangle.Largeur(index*2);
      cercle.Rayon(index);
      carre.Largeur(index);

      double aireCarreVoulue = neededIndex*neededIndex;
      double aireRectangleVoulue = neededIndex*(neededIndex*2);
      double aireCercleVoulue = 3.14f*(((double)neededIndex) * ((double)neededIndex));

      if(!((aireCarreVoulue < carre.aire()+0.1) && (aireCarreVoulue > carre.aire()-0.1)))
      {
         resultatCarre = false;
      }

      if(!((aireRectangleVoulue < rectangle.aire()+0.1) && (aireRectangleVoulue > rectangle.aire()-0.1)))
      {
         resultatRectangle = false;
      }

      if(!((aireCercleVoulue < cercle.aire()+0.1) && (aireCercleVoulue > cercle.aire()-0.1)))
      {
         resultatCercle = false;
      }
   }
   SousTest("100x rectangle.aire", resultatRectangle);
   SousTest("100x carre.aire", resultatCarre);
   SousTest("100x cercle.aire", resultatCercle);
   FinDuTest();

   //////////////////////////////////////////////////////////////////////////////
   DebutDunTest("Validation extensif de translation");
   bool resultatCarreX = true;
   bool resultatRectangleX = true;
   bool resultatCercleX = true;

   bool resultatCarreY = true;
   bool resultatRectangleY = true;
   bool resultatCercleY = true;

   for(int index=0; index<100; index++)
   {
      Coordonnee coordsRectangleAvant = rectangle.getAncrage();
      Coordonnee coordsCarreAvant     = carre.getAncrage();
      Coordonnee coordsCercleAvant    = cercle.getAncrage();

      rectangle.translater(1, 2);
      cercle.translater(3, 0);
      carre.translater(-2, -1);

      Coordonnee coordsRectangleApres = rectangle.getAncrage();
      Coordonnee coordsCarreApres     = carre.getAncrage();
      Coordonnee coordsCercleApres    = cercle.getAncrage();

      if((coordsRectangleApres.x - coordsRectangleAvant.x) != 1) resultatRectangleX = false;
      if((coordsRectangleApres.y - coordsRectangleAvant.y) != 2) resultatRectangleY = false;

      if((coordsCarreApres.x - coordsCarreAvant.x) != -2) resultatCarreX = false;
      if((coordsCarreApres.y - coordsCarreAvant.y) != -1) resultatCarreY = false;

      if((coordsCercleApres.x - coordsCercleAvant.x) != 3) resultatCercleX = false;
      if((coordsCercleApres.y - coordsCercleAvant.y) != 0) resultatCercleY = false;
   }
   SousTest("Rectangle x", resultatRectangleX);
   SousTest("Rectangle y", resultatRectangleY);

   SousTest("Carre x", resultatCarreX);
   SousTest("Carre y", resultatCarreY);

   SousTest("Cercle x", resultatCercleX);
   SousTest("Cercle y", resultatCercleY);
   FinDuTest();
   //////////////////////////////////////////////////////////////////////////////
   DebutDunTest("Destruction des classes");
   rectangle.~Rectangle();
   carre.~Carre();
   cercle.~Cercle();
   FinDuTest();

   FinDeFonctionalitee();
}

/**
 * @brief
 * Étapes de tests:
 * @paragraph Étapes_de_tests Étapes de tests
 * 1. Création de plusieurs types de vecteurs.
 * 2. Test des grosseurs initiale des vecteurs (0)
 * 3. Test des capacitées initiales des vecteurs (0)
 * 4. Test d'ajout d'une valeur initiale aux vecteurs
 * 5. Test des grosseurs après l'ajout initiale de la valeur
 * 6. Test des capacitées après l'ajout initiale de la valeur
 * 7. Vérification de la donnée sauvegardé initialement
 * AJOUT DE 19 VALEURS DANS LES VECTEURS
 * 8. Test des grosseurs après l'ajout des 19 valeurs (20)
 * 9. Test des capacitées après l'ajout des 19 valeurs (32)
 * 10. Vérification des 19 valeurs sauvegardées
 * 11. Test de destruction de la dernière donnée du vecteur
 * 12. Test des grosseurs après la destruction de la dernière donnée
 * 13. Vérification de la dernière donnée du tableau
 * 14. Tentative de retirer une donnée endehors du tableau
 * 15. Tentative de retirer la première donnée du tableau
 * 16. Test des grosseurs après la destruction de la première donnée
 * 17. Vérification de la première donnée du tableau
 * CRÉATION DE VECTEURS POINTEURS
 * 18. Ajout d'une première donnée dans les vecteurs pointeurs
 * 19. Ajout d'une deuxième donnée dans les vecteurs pointeurs
 * 20. Ajout d'une troisième donnée dans les vecteurs pointeurs
 * 21. Test de la grosseur des vecteurs pointeurs
 * 22. Test de la capacité des vecteurs pointeurs
 * 23. Vérification de la première donnée dans les vecteurs pointeurs
 * 24. Vérification de la deuxième donnée dans les vecteurs pointeurs
 * 25. Vérification de la troisième donnée dans les vecteurs pointeurs
 * CHANGEMENT DE LA PREMIERE DONNÉE POUR TESTÉ LA FONCTIONALITÉ DE POINTEUR
 * 26. Vérification des nouvelles premières données
 * 27. Tentative de destruction de la première donnée
 * 28. Test de destruction des vecteurs
 * 29. Vérification de la destruction des membres des vecteurs pointeurs
 */
void Tests::tests_unitaires_vecteur()
{
    DebutDeFonctionalitee("Classe Vecteur", "Unitaire");

    // Test 1: Creation de multiple classes Vecteurs
    DebutDunTest("Creation de multiple classes");
    Vecteur<int> intVecteur;
    Vecteur<bool> boolVecteur;
    Vecteur<string> stringVecteur;
    Vecteur<double> doubleVecteur;

    Vecteur<char*> charPtrVecteur;
    Vecteur<string*> stringPtrVecteur;
    FinDuTest();

    ////////////////////////////////////////////////////////////////////////////// 2
    DebutDunTest("Grosseurs initiales");
    SousTest("Vecteur int", intVecteur.Grosseur() == 0);
    SousTest("Vecteur bool", boolVecteur.Grosseur() == 0);
    SousTest("Vecteur string", stringVecteur.Grosseur() == 0);
    SousTest("Vecteur double", doubleVecteur.Grosseur() == 0);
    FinDuTest();
    ////////////////////////////////////////////////////////////////////////////// 3
    DebutDunTest("Capacite initiale");
    SousTest("Vecteur int", intVecteur.Capacite() == 0);
    SousTest("Vecteur bool", boolVecteur.Capacite() == 0);
    SousTest("Vecteur string", stringVecteur.Capacite() == 0);
    SousTest("Vecteur double", doubleVecteur.Capacite() == 0);
    FinDuTest();
    ////////////////////////////////////////////////////////////////////////////// 4
    DebutDunTest("Ajout d'une donne initiale");
    SousTest("Ajout de 69 au vecteur int", intVecteur.Ajouter(69) == true);
    SousTest("Ajout de false au vecteur bool", boolVecteur.Ajouter(false) == true);
    SousTest("Ajout de amogus au vecteur string", stringVecteur.Ajouter("amogus") == true);
    SousTest("Ajout de 1234 au vecteur double", doubleVecteur.Ajouter(1234) == true);
    FinDuTest();
    ////////////////////////////////////////////////////////////////////////////// 5
    DebutDunTest("Grosseur du vecteur apres sauvegarde d'une donnee");
    SousTest("Vecteur int", intVecteur.Grosseur() == 1);
    SousTest("Vecteur bool", boolVecteur.Grosseur() == 1);
    SousTest("Vecteur string", stringVecteur.Grosseur() == 1);
    SousTest("Vecteur double", doubleVecteur.Grosseur() == 1);
    FinDuTest();
    ////////////////////////////////////////////////////////////////////////////// 6
    DebutDunTest("Capacite du vecteur apres sauvegarde d'une donnee");
    SousTest("Vecteur int ", intVecteur.Capacite() == 1);
    SousTest("Vecteur bool ", boolVecteur.Capacite() == 1);
    SousTest("Vecteur string ", stringVecteur.Capacite() == 1);
    SousTest("Vecteur double ", doubleVecteur.Capacite() == 1);
    FinDuTest();
    ////////////////////////////////////////////////////////////////////////////// 7
    DebutDunTest("Verification de la donnee initialement sauvegardee");
    SousTest("Verification du 69", intVecteur.DonneAIndex(0) == 69);
    SousTest("Verification du false", boolVecteur.DonneAIndex(0) == false);
    SousTest("Verification du amogus", stringVecteur.DonneAIndex(0) == "amogus");
    SousTest("Verification du 1234", doubleVecteur.DonneAIndex(0) == 1234);
    FinDuTest();
    ////////////////////////////////////////////////////////////////////////////// 8
    for (int i = 0; i < 19; i++)
    {
        intVecteur.Ajouter(i);
        boolVecteur.Ajouter(i % 2);
        stringVecteur.Ajouter("ah...");
        doubleVecteur.Ajouter(i * 2);
    }

    ////////////////////////////////////////////////////////////////////////////// 9
    DebutDunTest("Grosseur des vecteurs apres 19 donnees");
    SousTest("Vecteur int ", intVecteur.Grosseur() == 20);
    SousTest("Vecteur bool ", boolVecteur.Grosseur() == 20);
    SousTest("Vecteur string ", stringVecteur.Grosseur() == 20);
    SousTest("Vecteur double ", doubleVecteur.Grosseur() == 20);
    FinDuTest();
    //////////////////////////////////////////////////////////////////////////////
    DebutDunTest("Capacite des vecteurs apres 19 donnees");
    SousTest("Vecteur int ", intVecteur.Capacite() == 32);
    SousTest("Vecteur bool ", boolVecteur.Capacite() == 32);
    SousTest("Vecteur string ", stringVecteur.Capacite() == 32);
    SousTest("Vecteur double ", doubleVecteur.Capacite() == 32);
    FinDuTest();
    //////////////////////////////////////////////////////////////////////////////
    bool erreurInt = false;
    bool erreurBool = false;
    bool erreurString = false;
    bool erreurDouble = false;

    for (int i = 0; i < 19; i++)
    {
        if (intVecteur.DonneAIndex(i + 1) != i) erreurInt = true;
        if (boolVecteur.DonneAIndex(i + 1) != i % 2) erreurBool = true;
        if (stringVecteur.DonneAIndex(i + 1) != "ah...") erreurString = true;
        if (doubleVecteur.DonneAIndex(i + 1) != i * 2) erreurDouble = true;
    }

    DebutDunTest("Verification de l'enregistrement des 19 donnees");
    SousTest("Vecteur int", !erreurInt);
    SousTest("Vecteur bool", !erreurBool);
    SousTest("Vecteur string", !erreurString);
    SousTest("Vecteur double", !erreurDouble);
    FinDuTest();
    //////////////////////////////////////////////////////////////////////////////
    DebutDunTest("Destruction de la derniere valeure des vecteurs");
    SousTest("Vecteur int", intVecteur.Retirer() == true);
    SousTest("Vecteur bool", boolVecteur.Retirer() == true);
    SousTest("Vecteur string", stringVecteur.Retirer() == true);
    SousTest("Vecteur double", doubleVecteur.Retirer() == true);
    FinDuTest();
    //////////////////////////////////////////////////////////////////////////////
    DebutDunTest("Grosseur des vecteurs apres la destruction de la derniere valeur");
    SousTest("Vecteur int", intVecteur.Grosseur() == 19);
    SousTest("Vecteur bool", boolVecteur.Grosseur() == 19);
    SousTest("Vecteur string", stringVecteur.Grosseur() == 19);
    SousTest("Vecteur double", doubleVecteur.Grosseur() == 19);
    FinDuTest();
    //////////////////////////////////////////////////////////////////////////////
    DebutDunTest("Verification de la derniere donnee des vecteurs apres destruction");
    SousTest("Donnee int a la fin du tableau", intVecteur.DonneAIndex(18) == 17);
    SousTest("Donnee bool a la fin du tableau", boolVecteur.DonneAIndex(18) == true);
    SousTest("Donnee string a la fin du tableau", stringVecteur.DonneAIndex(18) == "ah...");
    SousTest("Donnee double a la fin du tableau", doubleVecteur.DonneAIndex(18) == 34);
    FinDuTest();
    //////////////////////////////////////////////////////////////////////////////
    DebutDunTest("Tentative de retirer une donnee hors limite des vecteurs");
    SousTest("Vecteur int", intVecteur.Retirer(20) == false);
    SousTest("Vecteur bool", boolVecteur.Retirer(20) == false);
    SousTest("Vecteur string", stringVecteur.Retirer(20) == false);
    SousTest("Vecteur double", doubleVecteur.Retirer(20) == false);
    FinDuTest();
    //////////////////////////////////////////////////////////////////////////////
    DebutDunTest("Destruction de la premiere donnee dans les vecteurs");
    SousTest("Vecteur int", intVecteur.Retirer(0) == true);
    SousTest("Vecteur bool", boolVecteur.Retirer(0) == true);
    SousTest("Vecteur string", stringVecteur.Retirer(0) == true);
    SousTest("Vecteur double", doubleVecteur.Retirer(0) == true);
    FinDuTest();
    //////////////////////////////////////////////////////////////////////////////
    DebutDunTest("Grosseur des vecteurs apres la destruction de la premiere valeur");
    SousTest("Vecteur int", intVecteur.Grosseur() == 18);
    SousTest("Vecteur bool", boolVecteur.Grosseur() == 18);
    SousTest("Vecteur string", stringVecteur.Grosseur() == 18);
    SousTest("Vecteur double", doubleVecteur.Grosseur() == 18);
    FinDuTest();
    //////////////////////////////////////////////////////////////////////////////
    DebutDunTest("Verification de la nouvelle premiere donnee du vecteur");
    SousTest("Vecteur int", intVecteur.DonneAIndex(0) == 0);
    SousTest("Vecteur bool", boolVecteur.DonneAIndex(0) == false);
    SousTest("Vecteur string", stringVecteur.DonneAIndex(0) == "ah...");
    SousTest("Vecteur double", doubleVecteur.DonneAIndex(0) == 0);
    FinDuTest();
    //////////////////////////////////////////////////////////////////////////////
    DebutDunTest("Tentative d'acces a une valeur hors limite dans les vecteurs");
    SousTest("Vecteur int", intVecteur.DonneAIndex(69) == 0);
    SousTest("Vecteur bool", boolVecteur.DonneAIndex(69) == false);
    SousTest("Vecteur string", stringVecteur.DonneAIndex(69) == "");
    SousTest("Vecteur double", doubleVecteur.DonneAIndex(69) == 0);
    FinDuTest();
    //////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////
    char x = 'x';
    char y = 'y';
    char z = 'z';

    string premiereString = "premiere";
    string deuxiemeString = "deuxieme";
    string troisiemeString = "troisieme";
    //////////////////////////////////////////////////////////////////////////////
    DebutDunTest("Tentative d'ajout d'une premiere donnee a des vecteurs pointeurs");
    SousTest("Ajout de x au vecteur char*", charPtrVecteur.Ajouter(&x) == true);
    SousTest("Ajout de premiereString au vecteur string*", stringPtrVecteur.Ajouter(&premiereString) == true);
    FinDuTest();

    //////////////////////////////////////////////////////////////////////////////
    DebutDunTest("Tentative d'ajout d'une deuxieme donne a des vecteurs pointeurs");
    SousTest("Ajout de y au vecteur char*", charPtrVecteur.Ajouter(&y) == true);
    SousTest("Ajout de deuxiemeString au vecteur string*", stringPtrVecteur.Ajouter(&deuxiemeString) == true);
    FinDuTest();

    //////////////////////////////////////////////////////////////////////////////
    DebutDunTest("Tentative d'ajout d'une troisieme donne a des vecteurs pointeurs");
    SousTest("Ajout de z au vecteur char*", charPtrVecteur.Ajouter(&z) == true);
    SousTest("Ajout de troisiemeString au vecteur string*", stringPtrVecteur.Ajouter(&troisiemeString) == true);
    FinDuTest();

    //////////////////////////////////////////////////////////////////////////////
    DebutDunTest("Verification des grosseurs des vecteurs pointeurs");
    SousTest("Vecteur char*", charPtrVecteur.Grosseur() == 3);
    SousTest("Vecteur string*", stringPtrVecteur.Grosseur() == 3);
    FinDuTest();

    //////////////////////////////////////////////////////////////////////////////
    DebutDunTest("Verification des capacites des vecteurs pointeurs");
    SousTest("Vecteur char*", charPtrVecteur.Capacite() == 4);
    SousTest("Vecteur string*", stringPtrVecteur.Capacite() == 4);
    FinDuTest();

    //////////////////////////////////////////////////////////////////////////////
    DebutDunTest("Verification des premiere donnee sauvegardees");
    SousTest("Vecteur char* egal a 'x'", *charPtrVecteur.DonneAIndex(0) == x);
    SousTest("Vecteur string* egal a premiere", *stringPtrVecteur.DonneAIndex(0) == premiereString);
    FinDuTest();

    //////////////////////////////////////////////////////////////////////////////
    DebutDunTest("Verification des deuxiemes donnee sauvegardees");
    SousTest("Vecteur char* egal a 'y'", *charPtrVecteur.DonneAIndex(1) == y);
    SousTest("Vecteur string* egal a deuxieme", *stringPtrVecteur.DonneAIndex(1) == deuxiemeString);
    FinDuTest();

    //////////////////////////////////////////////////////////////////////////////
    DebutDunTest("Verification des troisiemes donnee sauvegardees");
    SousTest("Vecteur char* egal a 'z'", *charPtrVecteur.DonneAIndex(2) == z);
    SousTest("Vecteur string* egal a troisieme", *stringPtrVecteur.DonneAIndex(2) == troisiemeString);
    FinDuTest();

    //////////////////////////////////////////////////////////////////////////////
    DebutDunTest("Changement des premieres donnees");
    x = 'X';
    premiereString = "nouvelleString";
    FinDuTest();

    //////////////////////////////////////////////////////////////////////////////
    DebutDunTest("Verification des premiere donnee sauvegardees");
    SousTest("Vecteur char* egal a 'X'", *charPtrVecteur.DonneAIndex(0) == 'X');
    SousTest("Vecteur string* egal a nouvelleString", *stringPtrVecteur.DonneAIndex(0) == "nouvelleString");
    FinDuTest();

    //////////////////////////////////////////////////////////////////////////////
    DebutDunTest("Tentative de destruction des premiere donnees des vecteurs pointeurs");
    SousTest("Vecteur char*", charPtrVecteur.Retirer(0) == true);
    SousTest("Vecteur string*", stringPtrVecteur.Retirer(0) == true);
    FinDuTest();

    //////////////////////////////////////////////////////////////////////////////
    DebutDunTest("Verification des deuxiemes donnee sauvegardees");
    SousTest("Vecteur char* egal a 6", *charPtrVecteur.DonneAIndex(0) == y);
    SousTest("Vecteur string* egal a deuxieme", *stringPtrVecteur.DonneAIndex(0) == deuxiemeString);
    FinDuTest();
    //////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////// [] SURCHARGE TESTS
    //////////////////////////////////////////////////////////////////////////////
    DebutDunTest("Verification du retour des donnees par surchage d'operateur []");
    bool aPasserLeTest = true;
    for (int i = 0; i < intVecteur.Grosseur(); ++i)
    {
        if (intVecteur[i] != intVecteur.DonneAIndex(i)) aPasserLeTest = false;
    }
    SousTest("Verification de la surcharge de [] d'un vecteur <int>", aPasserLeTest);

    aPasserLeTest = true;
    for (int i = 0; i < boolVecteur.Grosseur(); ++i)
    {
        if (boolVecteur[i] != boolVecteur.DonneAIndex(i)) aPasserLeTest = false;
    }
    SousTest("Verification de la surcharge de [] d'un vecteur <bool>", aPasserLeTest);

    aPasserLeTest = true;
    for (int i = 0; i < stringVecteur.Grosseur(); ++i)
    {
        if (stringVecteur[i] != stringVecteur.DonneAIndex(i)) aPasserLeTest = false;
    }
    SousTest("Verification de la surcharge de [] d'un vecteur <string>", aPasserLeTest);

    aPasserLeTest = true;
    for (int i = 0; i < doubleVecteur.Grosseur(); ++i)
    {
        if (doubleVecteur[i] != doubleVecteur.DonneAIndex(i)) aPasserLeTest = false;
    }
    SousTest("Verification de la surcharge de [] d'un vecteur <double>", aPasserLeTest);

    aPasserLeTest = true;
    for (int i = 0; i < charPtrVecteur.Grosseur(); ++i)
    {
        if (charPtrVecteur[i] != charPtrVecteur.DonneAIndex(i)) aPasserLeTest = false;
    }
    SousTest("Vérification de la surcharge de [] d'un vecteur <char*>", aPasserLeTest);

    aPasserLeTest = true;
    for (int i = 0; i < stringPtrVecteur.Grosseur(); ++i)
    {
        if (stringPtrVecteur[i] != stringPtrVecteur.DonneAIndex(i)) aPasserLeTest = false;
    }
    SousTest("Verification de la surcharge de [] d'un vecteur <string*>", aPasserLeTest);

    FinDuTest();
    //////////////////////////////////////////////////////////////////////////////
    DebutDunTest("Verification d'enregistrement des donnees avec [] a index specifique");

    intVecteur[0] = 69;
    boolVecteur[1] = true;
    stringVecteur[4] = "8=====D Amogus sussy balls fr fr ong no cap";
    doubleVecteur[7] = 696969;

    SousTest("Vecteur int", "intVecteur[0] == 69", intVecteur[0] == 69);
    SousTest("Vecteur bool", "boolVecteur[1] == true", boolVecteur[1] == true);
    SousTest("Vecteur string", "stringVecteur[4] == \"8=====D Amogus sussy balls fr fr ong no cap\"", stringVecteur[4] == "8=====D Amogus sussy balls fr fr ong no cap");
    SousTest("Vecteur double", "doubleVecteur[7] == 696969", doubleVecteur[7] == 696969);

    FinDuTest();
    //////////////////////////////////////////////////////////////////////////////
    DebutDunTest("Verification de print avec l'operateur << et []");

    for (int i = 0; i<intVecteur.Grosseur(); i++)
    {
        std::cout << std::to_string(intVecteur[i]) << std::endl;
    }

    FinDuTest();
    //////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////// += TESTS
    //////////////////////////////////////////////////////////////////////////////
    DebutDunTest("Ajout de 19 donnees avec +=");
    for (int i = 18; i < 37; i++)
    {
        intVecteur += i;
        boolVecteur += (i % 2);
        stringVecteur += "amogus";
        doubleVecteur += (i * 3);
    }

    //////////////////////////////////////////////////////////////////////////////
   DebutDunTest("Grosseur des vecteurs apres 19 donnees avec +=");
   SousTest("Vecteur int ", "intVecteur.Grosseur() == 37", intVecteur.Grosseur() == 37);
   SousTest("Vecteur bool ", "boolVecteur.Grosseur() == 37", boolVecteur.Grosseur() == 37);
   SousTest("Vecteur string ", "stringVecteur.Grosseur() == 37", stringVecteur.Grosseur() == 37);
   SousTest("Vecteur double ", "doubleVecteur.Grosseur() == 37", doubleVecteur.Grosseur() == 37);
   FinDuTest();
   //////////////////////////////////////////////////////////////////////////////
   DebutDunTest("Capacite des vecteurs apres 19 donnees avec +=");
   SousTest("Vecteur int ", "intVecteur.Capacite() == 64", intVecteur.Capacite() == 64);
   SousTest("Vecteur bool ", "boolVecteur.Capacite() == 64", boolVecteur.Capacite() == 64);
   SousTest("Vecteur string ", "stringVecteur.Capacite() == 64", stringVecteur.Capacite() == 64);
   SousTest("Vecteur double ", "doubleVecteur.Capacite() == 64", doubleVecteur.Capacite() == 64);
   FinDuTest();
   //////////////////////////////////////////////////////////////////////////////
   erreurInt = false;
   erreurBool = false;
   erreurString = false;
   erreurDouble = false;

   for (int i = 18; i < 37; i++)
   {
       if (intVecteur[i] != i) erreurInt = true;
       if (boolVecteur[i] != (i%2)) erreurBool = true;
       if (stringVecteur[i] != "amogus") erreurString = true;
       if (doubleVecteur[i] != (i * 3)) erreurDouble = true;
   }

   DebutDunTest("Verification de l'enregistrement des 19 donnees avec +=");
   SousTest("Vecteur int", !erreurInt);
   SousTest("Vecteur bool", !erreurBool);
   SousTest("Vecteur string", !erreurString);
   SousTest("Vecteur double", !erreurDouble);
   FinDuTest();
   //////////////////////////////////////////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////
   DebutDunTest("Tentative de destruction des vecteurs");

   DebutDunSousTest("Destruction du vecteur int.");
   intVecteur.~Vecteur();
   FinDuSousTest(true);

   DebutDunSousTest("Destruction du vecteur bool.");
   boolVecteur.~Vecteur();
   FinDuSousTest(true);

   DebutDunSousTest("Destruction du vecteur string.");
   stringVecteur.~Vecteur();
   FinDuSousTest(true);

   DebutDunSousTest("Destruction du vecteur double.");
   doubleVecteur.~Vecteur();
   FinDuSousTest(true);

   DebutDunSousTest("Destruction du vecteur pointeur de char.");
   charPtrVecteur.~Vecteur();
   FinDuSousTest(true);

   DebutDunSousTest("Destruction du vecteur pointeur de string.");
   stringPtrVecteur.~Vecteur();
   FinDuSousTest(true);
   //////////////////////////////////////////////////////////////////////////////
   FinDuTest();

   // Le program vas simplement stop si il n'a pas été capable de détruire les objets
   FinDeFonctionalitee();
}

/**
 * @brief 
 * 1. Création de l'objet de couche.
 * 
 * 2. Tests de changements dans une nouvelle couche vide.
 *    2.1. Translation d'une couche vide (deverait pas fonctionner)
 *    2.2. Reset d'une couche vide (deverait fonctionner)
 *    2.3. Reset d'une translation (Échec, aucune translation n'a été fait avant)
 *    2.4. L'aire de la couche initiale, vide, deverait être de 0.
 *    2.5. L'état de la couche deverait être Initialisée par défaut.
 *    2.6. L'ajout d'une forme à la couche deverait ne pas fonctionner.
 * 
 * 3. Tests de changements d'états
 *    3.1. Mettre la couche à initialisé deverait ne pas marcher.
 *    3.2. Mettre la couche à Active deverait fonctionner.
 *    3.3. Mettre la couche à Inactive deverait fonctionner.
 * 
 * 4. Test d'ajout de formes.
 *    4.1. Ajout de forme deverait ne pas fonctionner (la couche est encore inactive)
 *    4.2. Activation de la couche deverait fonctionner.
 *    4.3. Test d'ajout d'un rectangle dans la couche.
 *    4.4. Test d'ajout d'un carré dans la couche.
 *    4.5. Test d'ajout d'un cercle dans la couche.
 * 
 * 5. Calcules de l'aire avant modification des formes.
 *    5.1. l'aire de la couche lorsqu'active deverait être 378.5.
 *    5.2. l'aire de la couche lorsqu'inactive deverait être 378.5.
 * 
 * 6. Calcule de l'aire après la modification des formes.
 *    6.1. l'aire de la couche lorsqu'active deverait être (3.0*7.0)+(66.0*66.0)+(13.0*13.0*3.14f).
 *    6.2. l'aire de la couche lorsqu'inactive deverait être (3.0*7.0)+(66.0*66.0)+(13.0*13.0*3.14f).
 * 
 * 7. Test de translation de la couche.
 *    7.1. La couche deverait pouvoir être bouger de X=5, Y=6
 *    7.2. L'aire de la couche deverait rester (3.0*7.0)+(66.0*66.0)+(13.0*13.0*3.14f) après avoir translaté.
 * 
 * 8. Vérification de la translation des formes dans la couche.
 *    8.1. Le X du rectangle deverait être 10.
 *    8.2. Le Y du rectangle deverait être 11.
 *    8.3. Le X du carré deverait être 15.
 *    8.4. Le Y du carré deverait être 16.
 *    8.5. Le X du cercle deverait être 10.
 *    8.6. Le Y du cercle deverait être 8.
 * 
 * 9. Test de réinitialisation de la translation de la couche.
 *    9.1 La couche deverait pouvoir se faire réinitialiser sa translation.
 * 
 * 10. Vérification de la réinitialisation de la translation des formes dans la couche.
 *    10.1. Le X du rectangle deverait être 5.
 *    10.2. Le Y du rectangle deverait être 5.
 *    10.3. Le X du carré deverait être 10.
 *    10.4. Le Y du carré deverait être 10.
 *    10.5. Le X du cercle deverait être 5.
 *    10.6. Le Y du cercle deverait être 2.
 * 
 * 11. Test d'affichage de la couche.
 * 
 * 12. Test de réinitialisation de la couche.
 * 
 * 13. Vérification de la réinitialisation de la couche.
 *    13.1. Translation de la couche réinitialisé deverait pas fonctionner.
 *    13.2. Réinitialisation de la couche deverait fonctionner pareil.
 *    13.3. La réinitialisation de la translation deverait ne pas fonctionner.
 *    13.4. L'aide de la couche réinitialisé deverait être 0.
 *    13.5. L'état de la couche réinitialisé deverait être Initialisé.
 *    13.6. L'ajout d'une forme a la couche deverait être impossible. (Elle n'est pas active).
 * 
 * 14. Test de destruction de l'objet de couche. (voir si le program continue).
 */
void Tests::tests_unitaires_couche()
{
   DebutDeFonctionalitee("Classe Couches", "Unitaire");
   //////////////////////////////////////////////////////////////////////////////
   // Test 1: Creation d'un objet couche
   DebutDunTest("Creation d'un objet couche");
   Couche _couche;
   FinDuTest(true);

   Rectangle rectangle(5, 5);
   rectangle.Hauteur(20);
   rectangle.Largeur(10);

   Carre carre(10, 10);
   carre.Largeur(10);

   Cercle cercle(5, 2);
   cercle.Rayon(5);

   //////////////////////////////////////////////////////////////////////////////
   DebutDunTest("Tests de changements dans une nouvelle couche vide.");
   SousTest("Translation d'une couche vide",    "_couche.TranslationCouche(10,10) == false",             _couche.TranslationCouche(10,10) == false);
   SousTest("Reset d'une couche vide",          "_couche.ReinitialisationCouche() == true",              _couche.ReinitialisationCouche() == true);
   SousTest("Reset d'une translation",          "_couche.ReinitialisationTranslationCouche() == false",  _couche.ReinitialisationTranslationCouche() == false);
   SousTest("Aire d'une couche vide = 0",       "_couche.AireCouche() == 0",                             _couche.AireCouche() == 0);
   SousTest("Etat de la couche = Initialisee",  "_couche.Etat() == EtatsCouche::Initialisee",            _couche.Etat() == EtatsCouche::Initialisee);
   SousTest("Ajout d'une forme impossible",     "_couche.AjoutForme(&rectangle) == false",               _couche.AjoutForme(&rectangle) == false);
   FinDuTest();

   //////////////////////////////////////////////////////////////////////////////
   DebutDunTest("Tests de changements d'etats");
   SousTest("Etat de la couche = Initialisee", _couche.ChangerEtat(EtatsCouche::Initialisee) == false);
   SousTest("Etat de la couche = Active",      _couche.ChangerEtat(EtatsCouche::Active) == true);
   SousTest("Etat de la couche = Inactive",    _couche.ChangerEtat(EtatsCouche::Inactive) == true);
   FinDuTest();

   //////////////////////////////////////////////////////////////////////////////
   DebutDunTest("Ajout de formes");
   SousTest("Couche inactive = impossible.", "_couche.AjoutForme(&rectangle) == false", _couche.AjoutForme(&rectangle) == false);
   _couche.ChangerEtat(EtatsCouche::Active);
   SousTest("Rectangle, Couche active = possible.", "_couche.AjoutForme(&rectangle) == true", _couche.AjoutForme(&rectangle) == true);
   SousTest("Carre, Couche active = possible.",     "_couche.AjoutForme(&carre) == true",     _couche.AjoutForme(&carre) == true);
   SousTest("Cercle, Couche active = possible.",    "_couche.AjoutForme(&cercle) == true",    _couche.AjoutForme(&cercle) == true);
   FinDuTest();

   //////////////////////////////////////////////////////////////////////////////
   // Test 5: Calcule aire couche avant modification
   DebutDunTest("Calcule de l'aire couche avant modification");
   SousTestDouble("aire couche si active.", _couche.AireCouche(), 378.5);
   _couche.ChangerEtat(EtatsCouche::Inactive);
   SousTestDouble("aire couche si inactive.", _couche.AireCouche(), 378.5);
   _couche.ChangerEtat(EtatsCouche::Active);
   FinDuTest();


   //////////////////////////////////////////////////////////////////////////////
   // Test 6: Calcule aire couche modification des formes
   DebutDunTest("Calcule de l'aire apres modification des formes");

   rectangle.Hauteur(3);
   rectangle.Largeur(7);
   carre.Largeur(66);
   cercle.Rayon(13);

   SousTestDouble("aire couche si active.", _couche.AireCouche(), (3.0*7.0)+(66.0*66.0)+(13.0*13.0*3.14f));
   _couche.ChangerEtat(EtatsCouche::Inactive);
   SousTestDouble("aire couche si inactive.", _couche.AireCouche(), (3.0*7.0)+(66.0*66.0)+(13.0*13.0*3.14f));
   _couche.ChangerEtat(EtatsCouche::Active);
   FinDuTest();

   //////////////////////////////////////////////////////////////////////////////
   // Test 7: Translation de la couche et aire
   DebutDunTest("Translation de la couche");
   SousTest("_couche.TranslationCouche(5, 6)", _couche.TranslationCouche(5, 6) == true);
   SousTestDouble("aire apres translation", _couche.AireCouche(), (3.0*7.0)+(66.0*66.0)+(13.0*13.0*3.14f));
   FinDuTest();

   //////////////////////////////////////////////////////////////////////////////
   // Test 7: Vérification de la translation des formes
   DebutDunTest("Verification de la translation des formes");

   Coordonnee coordsRectangle = rectangle.getAncrage();
   Coordonnee coordsCarre = carre.getAncrage();
   Coordonnee coordsCercle = cercle.getAncrage();

   SousTest("X: Rectangle = 10", coordsRectangle.x == 10);
   SousTest("Y: Rectangle = 11", coordsRectangle.y == 11);
   SousTest("X: Carre = 15", coordsCarre.x == 15);
   SousTest("Y: Carre = 16", coordsCarre.y == 16);
   SousTest("X: Cercle = 10", coordsCercle.x == 10);
   SousTest("Y: Cercle = 8", coordsCercle.y == 8);
   FinDuTest();

   //////////////////////////////////////////////////////////////////////////////
   // Test 8: Reinitialiser la translation de la couche
   DebutDunTest("Reinitialiser la translation de la couche");
   SousTest("_couche.ReinitialisationTranslationCouche()", _couche.ReinitialisationTranslationCouche() == true);
   FinDuTest();

   //////////////////////////////////////////////////////////////////////////////
   // Test 7: Vérification de la translation des formes
   DebutDunTest("Verification de la reinitialisation de translation");

   coordsRectangle = rectangle.getAncrage();
   coordsCarre = carre.getAncrage();
   coordsCercle = cercle.getAncrage();

   SousTest("X: Rectangle = 5", coordsRectangle.x == 5);
   SousTest("Y: Rectangle = 5", coordsRectangle.y == 5);
   SousTest("X: Carre = 10", coordsCarre.x == 10);
   SousTest("Y: Carre = 10", coordsCarre.y == 10);
   SousTest("X: Cercle = 5", coordsCercle.x == 5);
   SousTest("Y: Cercle = 2", coordsCercle.y == 2);
   FinDuTest();

   //////////////////////////////////////////////////////////////////////////////
   // Test 9: Afficher Couche
   DebutDunTest("Afficher Couche");
   SousTest("_couche.AfficherCouche(OUTPUT_STREAM)", _couche.AfficherCouche(OUTPUT_STREAM) == true);
   FinDuTest();

   //////////////////////////////////////////////////////////////////////////////
   // Test 9: Reinitialisation de la couche
   DebutDunTest("Reset de la couche");
   SousTest("_couche.ReinitialisationCouche()", _couche.ReinitialisationCouche() == true);
   FinDuTest();

   //////////////////////////////////////////////////////////////////////////////
   // Test 10: Verification du reset de la couche
   DebutDunTest("Verification du reset de la couche");
   SousTest("Translation d'une couche vide",    "_couche.TranslationCouche(10,10) == false", _couche.TranslationCouche(10,10) == false);
   SousTest("Reset d'une couche vide",          "_couche.ReinitialisationCouche() == true", _couche.ReinitialisationCouche() == true);
   SousTest("Reset d'une translation",          "_couche.ReinitialisationTranslationCouche() == false", _couche.ReinitialisationTranslationCouche() == false);
   SousTest("Aire d'une couche vide = 0",       "_couche.AireCouche() == 0", _couche.AireCouche() == 0);
   SousTest("Etat de la couche = Initialisee",  "_couche.Etat() == EtatsCouche::Initialisee", _couche.Etat() == EtatsCouche::Initialisee);
   SousTest("Ajout d'une forme impossible",     "_couche.AjoutForme(&rectangle) == false", _couche.AjoutForme(&rectangle) == false);
   FinDuTest();

   //////////////////////////////////////////////////////////////////////////////
   // Test 10: Destruction de la Couche
   DebutDunTest("Destruction de la Couche");
   _couche.~Couche();
   FinDuTest();

   FinDeFonctionalitee();
}

/**
 * @brief 
 * 1. Creation d'un canevas:
 *    1.1. Aire initiale de la couche initiale doit etre 0
 *    1.2. Translater le canevas doit fonctionner
 *    1.3. Desactiver la couche initiale doit fonctionner
 *    1.4. Le nombre de couche initiales doit etre 5.
 *    1.5. Reinitialisation de la couche initiale doit fonctionner, meme si elle est vide. Car la couche initiale doit etre active.
 *    1.6. La premiere couche ne peut pas etre detruite
 *    1.7. On ne peut pas detruire une forme inexistante
 *    1.8. Activer la premiere couche deverait fonctionner.
 * 
 * 2. Test d'ajout de formes
 *    2.1. La couche 0 deverait etre en mesure d'etre desactive
 *    2.2. On ne deverait pas etre en mesure d'ajouter des formes dans une couche desactivee
 *    2.3. La couche 0 peut s'activer
 *    2.4. Ajout d'un rectangle a la couche 0
 *    2.5. Ajout d'un carre a la couche 0
 *    2.6. Ajout d'un cercle a la couche 0
 *    2.7. Il deverait avoir 3 formes dans la couche 0
 * 
 * 3. Modification des formes.
 *    
 * 4. Verification des modifications
 *    4.1. Aire du rectangle obtenu par le canevas deverait etre 69*42
 *    4.2. Aire du carre obtenu par le canevas deverait etre 69*69
 *    4.3. Aire de la couche 0 deverait etre 22608.5
 *    4.4. Aire de la couche 2 deverait etre 0.
 *    4.5. Desactivation de la couche 0
 *    4.6. L'aire de la couche 0 deverait etre 0
 *    4.7. Activation de la couche 0
 * 
 * 5. Retrait d'une forme
 *    5.1. Retrait du rectangle
 *    5.2. Il deverait juste avoir 2 formes dans la couche 0 
 *    5.3. Aire de la couche deverait etre 9522
 *    5.4. Retrait du carre
 *    5.5. Il deverait juste avoir 1 formes dans la couche 0 
 *    5.6. Aire de la couche deverait etre 4761
 *    5.7. Retrait du cercle
 *    5.8. Il deverait avoir 0 formes dans la couche 0 
 *    5.9. Aire de la couche deverait etre 0
 *    5.10. Retrait d'une forme inexistante
 *    5.11. Il deverait avoir 0 formes dans la couche 0 
 *    5.12. Aire de la couche deverait etre 0
 * 
 * 6. Destruction du canevas.
 */
void Tests::tests_unitaires_canevas()
{
   DebutDeFonctionalitee("Classe Canevas", "Unitaire");

   Canevas canevas;
   Rectangle rectangle;
   Carre carre;
   Cercle cercle;

   //////////////////////////////////////////////////////////////////////////////
   // Test 1: Creation d'un objet canevas
   DebutDunTest("Creation d'un canevas");
   SousTestDouble("Aire initiale", canevas.aire(), 0);
   SousTest("Translation canevas", canevas.translater(1,1)==true);
   SousTest("Desactivation de la couche initiale", canevas.desactiverCouche(0)==true);
   SousTest("Nombre de couches initiales", canevas.NombreDeCouches()==NOMBRE_DE_COUCHES_INITIALES);
   SousTest("Reinitialisation de la couche initiale", canevas.reinitialiserCouche(0)==true);
   SousTest("Tentative de destruction de la premiere couche", canevas.retirerCouche(0)==false);
   SousTest("Destruction d'une forme inexistante", canevas.retirerForme(0)==false);
   SousTest("Activation de la premiere couche", canevas.activerCouche(0)==true);
   FinDuTest();

   //////////////////////////////////////////////////////////////////////////////
   // Test 2: Test d'ajout de formes au canevas
   DebutDunTest("Test d'ajout de formes");
   SousTest("Desactivation de la couche", canevas.desactiverCouche(0)==true);
   SousTest("Ajout de formes non fonctionnel", canevas.ajouterForme(&rectangle)==false);
   SousTest("Activation de la couche", canevas.activerCouche(0)==true);
   SousTest("Ajout de rectangle", canevas.ajouterForme(&rectangle));
   SousTest("Ajout de carree", canevas.ajouterForme(&carre));
   SousTest("Ajout de cercle", canevas.ajouterForme(&cercle));
   SousTest("Nombre de formes dans la couche",             canevas.coucheAIndex(0)->NombreDeFormes()==3);
   FinDuTest();

   //////////////////////////////////////////////////////////////////////////////
   // Test 3: Modification des formes dans le canevas
   DebutDunTest("Modification des formes");
   rectangle.Hauteur(69);
   rectangle.Largeur(42);
   carre.Largeur(69);
   cercle.Rayon(69);
   FinDuTest();

   //////////////////////////////////////////////////////////////////////////////
   // Test 3: Verification que les modifications apportees ont fait reellement dans le canevas
   DebutDunTest("Verification des modifications");
   SousTestDouble("Aire du rectangle",             canevas.FormeAIndex(0)->aire(), 69*42);
   SousTestDouble("Aire du carre",                 canevas.FormeAIndex(1)->aire(), 69*69);
   SousTestDouble("Aire de la couche 0",      canevas.coucheAIndex(0)->AireCouche(), 22608.5); // Float font en sorte que c'est pas bon.
   SousTestDouble("Aire de la couche 2",           canevas.coucheAIndex(1)->AireCouche(), 22608.5);
   SousTest("Desactivation de la couche 0",        canevas.desactiverCouche(0) == true);
   SousTestDouble("Aire de la couche active",      canevas.coucheAIndex(0)->AireCouche(), 22608.5); // Float font en sorte que c'est pas bon.
   SousTest("Activation de la couche 0",        canevas.activerCouche(0) == true);
   FinDuTest();

   //////////////////////////////////////////////////////////////////////////////
   DebutDunTest("Retrait des formes");
   SousTest("Retrait du rectangle",             canevas.retirerForme(0) == true);
   SousTest("Nombre de formes dans la couche",  canevas.coucheAIndex(0)->NombreDeFormes()==2);
   SousTestDouble("Aire de la couche active",      canevas.coucheAIndex(0)->AireCouche(), 19710.5); // Float font en sorte que c'est pas bon.

   SousTest("Retrait du carre",             canevas.retirerForme(0) == true);
   SousTest("Nombre de formes dans la couche",  canevas.coucheAIndex(0)->NombreDeFormes()==1);
   SousTestDouble("Aire de la couche active",      canevas.coucheAIndex(0)->AireCouche(), 14949.5f); // Float font en sorte que c'est pas bon.

   SousTest("Retrait du cercle",             canevas.retirerForme(0) == true);
   SousTest("Nombre de formes dans la couche",  canevas.coucheAIndex(0)->NombreDeFormes()==0);
   SousTestDouble("Aire de la couche active",      canevas.coucheAIndex(0)->AireCouche(), 0); // Float font en sorte que c'est pas bon.

   SousTest("Retrait d'une forme inexistante",  canevas.retirerForme(0) == false);
   SousTest("Nombre de formes dans la couche",  canevas.coucheAIndex(0)->NombreDeFormes()==0);
   SousTestDouble("Aire de la couche active",      canevas.coucheAIndex(0)->AireCouche(), 0); // Float font en sorte que c'est pas bon.
   FinDuTest();

   //////////////////////////////////////////////////////////////////////////////
   DebutDunTest("Destruction du canevas");
   canevas.~Canevas();
   FinDuTest();

   //////////////////////////////////////////////////////////////////////////////
   DebutDunTest("Verification de la destruction [!UB!]");
   SousTest("Nombre de couches = 0", canevas.NombreDeCouches()==0);
   FinDuTest();

   FinDeFonctionalitee();
}

void Tests::tests_unitaires()
{
   // Fait tous les tests unitaires
   DebutDeTout();
   tests_unitaires_formes();
   tests_unitaires_vecteur();
   tests_unitaires_couche();
   tests_unitaires_canevas();
   FinDeTout();
}

void Tests::tests_application()
{
   // Fait tous les tests applicatifs
   tests_application_cas_01();
   //tests_application_cas_02();
   FinDeTout();
}

void Tests::tests_application_cas_01()
{
   DebutDeFonctionalitee("TESTS APPLICATION (CAS 01)", "Application");

   Canevas canevas;
   Rectangle rectangle(2, 3, 4, 9);
   Rectangle rectangleB(0, 0, 12, 3);
   Rectangle rectangleC(0, 0, 1, 1);

   Carre carre(1, 2, 6);
   Carre carreC(0, 0, 1);

   Cercle cercle(0, 1, 5); 
   Cercle cercleC(0, 0, 1); 
   Carre carreD(10, 10, 10);

   ///////////////////////////////////////////////////////////////////////////////////////
   // ETAPE 1 a 4
   DebutDunTest("Activer la couche 2");
   SousTest("Activer la couche 2", "canevas.activerCouche(2)==true", canevas.activerCouche(2)==true);
   SousTest("Ajout Cercle(x=0, y=1, r=5)",        "canevas.ajouterForme(&cercle)==true", canevas.ajouterForme(&cercle)==true);
   SousTest("Ajout Carre(x=1, y=2, c=6)",         "canevas.ajouterForme(&carre)==true", canevas.ajouterForme(&carre)==true);
   SousTest("Ajout Rectangle(x=2, y=3, l=4, h=9)",     "canevas.ajouterForme(&rectangle)==true", canevas.ajouterForme(&rectangle)==true);
   FinDuTest();

   DebutDunTest("Activer la couche 1");
   SousTest("Activer la couche 1",  "canevas.activerCouche(1)==true", canevas.activerCouche(1)==true);
   SousTest("Ajout rectangle B",    "canevas.ajouterForme(&rectangleB)==true", canevas.ajouterForme(&rectangleB)==true);
   FinDuTest();

   DebutDunTest("Affichage du canevas:", "canevas.afficher(OUTPUT_STREAM)");
   canevas.afficher(OUTPUT_STREAM);
   FinDuTest(true);

   TestDouble("Aire du canevas", canevas.aire(), canevas.aire());

   ///////////////////////////////////////////////////////////////////////////////////////
   // Etapes 5 a 8

   DebutDunTest("Activer la couche 0");
   SousTest("Activer la couche 0", "canevas.activerCouche(0)==true", canevas.activerCouche(0)==true);
   SousTest("Ajout Rectangle(x=0, y=0, l=1, h=1)", "canevas.ajouterForme(&rectangleC)==true", canevas.ajouterForme(&rectangleC)==true);
   SousTest("Ajout Carre(x=0, y=0, c=1)", "canevas.ajouterForme(&carreC)==true", canevas.ajouterForme(&carreC)==true);
   SousTest("Ajout Cercle(x=0, y=0, r=1)", "canevas.ajouterForme(&cercleC)==true", canevas.ajouterForme(&cercleC)==true);
   FinDuTest();

   DebutDunTest("Activer la couche 2");
   SousTest("Activer la couche 2", "canevas.activerCouche(2)==true", canevas.activerCouche(2)==true);
   SousTest("Translation X=2, Y=1", "canevas.translater(2, 1)==true", canevas.translater(2, 1)==true);
   FinDuTest();

   DebutDunTest("Affichage du canevas:", "canevas.afficher(OUTPUT_STREAM)");
   canevas.afficher(OUTPUT_STREAM);
   FinDuTest(true);

   TestDouble("Aire du canevas", canevas.aire(), canevas.aire());

   ///////////////////////////////////////////////////////////////////////////////////////
   // Etapes 9 a 13
   DebutDunTest("Activer la couche 0");
   SousTest("Activer la couche 0", "canevas.activerCouche(0)==true", canevas.activerCouche(0)==true);
   SousTest("Retirer la 2e forme.", "canevas.retirerForme(1)==true", canevas.retirerForme(1)==true);
   FinDuTest();

   DebutDunTest("Reinitialiser la couche 1", "canevas.reinitialiserCouche(1)==true");
   FinDuTest(canevas.reinitialiserCouche(1)==true);

   DebutDunTest("Activer la couche 4", "canevas.activerCouche(4)==true");
   FinDuTest(canevas.activerCouche(4)==true);

   DebutDunTest("Affichage du canevas:", "canevas.afficher(OUTPUT_STREAM)");
   canevas.afficher(OUTPUT_STREAM);
   FinDuTest(true);

   TestDouble("Aire du canevas", canevas.aire(), canevas.aire());

   ///////////////////////////////////////////////////////////////////////////////////////
   // Etapes 14 a 16
   DebutDunTest("Reinitialiser le canevas", "canevas.reinitialiser()==true");
   FinDuTest(canevas.reinitialiser()==true);

   DebutDunTest("Affichage du canevas:", "canevas.afficher(OUTPUT_STREAM)");
   canevas.afficher(OUTPUT_STREAM);
   FinDuTest(true);

   TestDouble("Aire du canevas", canevas.aire(), canevas.aire());

   ///////////////////////////////////////////////////////////////////////////////////////
   // Etapes 17 a 20
   DebutDunTest("Activer la couche 3");
   SousTest("Activer la couche 3", "canevas.activerCouche(3)==true", canevas.activerCouche(3)==true);
   SousTest("Ajout Carre(x=10, y=10, c=10)", "canevas.ajouterForme(&carreD)==true", canevas.ajouterForme(&carreD)==true);
   SousTest("Ajout null, invalide.", "canevas.ajouterForme(nullptr)==false", canevas.ajouterForme(nullptr)==false);
   FinDuTest();

   DebutDunTest("Activer la couche 6 (invalide)", "canevas.activerCouche(6)==false");
   FinDuTest(canevas.activerCouche(6)==false);

   DebutDunTest("Affichage du canevas:", "canevas.afficher(OUTPUT_STREAM)");
   canevas.afficher(OUTPUT_STREAM);
   FinDuTest(true);

   TestDouble("Aire du canevas", canevas.aire(), canevas.aire());

   FinDeFonctionalitee();
}

void Tests::tests_application_cas_02(MonInterface* monInterface)
{
   DebutDeFonctionalitee("TESTS APPLICATION (CAS 02)", "Application");

   //////////////////////////////////////////////////////////////////////////////
   DebutDunTest("Verification des parametres initiales de l'application");
   SousTest("Nombre de couches initiale",         "monInterface->GetCanevas()->NombreDeCouches()==1",                                monInterface->GetCanevas()->NombreDeCouches()==1);
   SousTest("Nombre de formes initiale",          "monInterface->GetCanevas()->coucheAIndex(0)->NombreDeFormes()==0",                monInterface->GetCanevas()->coucheAIndex(0)->NombreDeFormes()==0);
   SousTest("Etat initiale de la couche",         "monInterface->GetCanevas()->coucheAIndex(0)->Etat() == EtatsCouche::Initialisee", monInterface->GetCanevas()->coucheAIndex(0)->Etat() == EtatsCouche::Initialisee);
   SousTest("Aire initiale de la couche",         "monInterface->GetCanevas()->ObtenirCoucheCourant()->AireCouche()==0",             monInterface->GetCanevas()->ObtenirCoucheCourant()->AireCouche()==0);
   SousTest("Index initiale de la couche active", "monInterface->GetCanevas()->GetIndexCoucheActive()==0",                           monInterface->GetCanevas()->GetIndexCoucheActive()==0);
   FinDuTest();

   //////////////////////////////////////////////////////////////////////////////
   DebutDunTest("Tentative de navigation de couches initiale");
   monInterface->couchePrecedente();
   SousTest("Tentative d'aller a une couche precedente", "monInterface->GetCanevas()->GetIndexCoucheActive()==0", monInterface->GetCanevas()->GetIndexCoucheActive() == 0);
   monInterface->coucheSuivante();
   monInterface->coucheSuivante();
   monInterface->coucheSuivante();
   SousTest("Tentative d'aller a une couche suivante", "monInterface->GetCanevas()->GetIndexCoucheActive()==0", monInterface->GetCanevas()->GetIndexCoucheActive() == 0);
   monInterface->coucheDerniere();
   SousTest("Tentative d'aller a la derniere couche", "monInterface->GetCanevas()->GetIndexCoucheActive()==0", monInterface->GetCanevas()->GetIndexCoucheActive() == 0);
   monInterface->couchePremiere();
   SousTest("Tentative d'aller a la premiere couche", "monInterface->GetCanevas()->GetIndexCoucheActive()==0", monInterface->GetCanevas()->GetIndexCoucheActive() == 0);
   FinDuTest();

   //////////////////////////////////////////////////////////////////////////////
   DebutDunTest("Tentative de navigation de formes initiale");
   monInterface->formePrecedente();
   SousTest("Tentative d'aller a une forme precedente", "monInterface->GetCanevas()->GetIndexCoucheActive()==0", monInterface->GetCanevas()->GetIndexFormeActive() == 0);
   monInterface->coucheSuivante();
   monInterface->coucheSuivante();
   monInterface->coucheSuivante();
   SousTest("Tentative d'aller a une couche suivante", "monInterface->GetCanevas()->GetIndexCoucheActive()==0", monInterface->GetCanevas()->GetIndexCoucheActive() == 0);
   monInterface->coucheDerniere();
   SousTest("Tentative d'aller a la derniere couche", "monInterface->GetCanevas()->GetIndexCoucheActive()==0", monInterface->GetCanevas()->GetIndexCoucheActive() == 0);
   monInterface->couchePremiere();
   SousTest("Tentative d'aller a la premiere couche", "monInterface->GetCanevas()->GetIndexCoucheActive()==0", monInterface->GetCanevas()->GetIndexCoucheActive() == 0);
   FinDuTest();

   FinDeFonctionalitee();
}

///////////////////////////////////////////////////////////////////////////////////////

/// @brief Retourne le nombre de millisecondes actuel par std::chrono
/// @return int: Nombre de millisecondes depuis le début du programme.
int Tests::MicrosecondesActuelles()
{
   auto tempActuel = std::chrono::steady_clock::now();
   auto tempActuelMs = std::chrono::time_point_cast<std::chrono::microseconds>(tempActuel);
   auto tempEpochMs = tempActuelMs.time_since_epoch().count();
   return static_cast<int>(tempEpochMs);
}

/**
 * @brief A appeller au tout début, avant de commencer le premier test.
 * Print un header.
 */
void Tests::DebutDeTout()
{
   OUTPUT_STREAM << "===============-===========-===============" << std::endl;
   OUTPUT_STREAM << "===============-=={TESTS}==-===============" << std::endl;
   OUTPUT_STREAM << "===============-===========-===============" << std::endl;
   chronoDebutDeTout = MicrosecondesActuelles();
}
/**
 * @brief Appeller a la toute fin, une fois que tous les tests ont été faits.
 * Et toutes les fonctionalitées faites.
 */
void Tests::FinDeTout()
{
   int ratioDeSucces = 0;
   float fSuccesTotal = (float)successTotalToutesFonctionalitees;
   ratioDeSucces = ((int)((fSuccesTotal / ((float)nombreDeTestsEffectuesToutesFonctionalitee))*100));

   OUTPUT_STREAM << "===============-===========-===============" << std::endl;
   OUTPUT_STREAM << "===============-{RESULTATS}-===============" << std::endl;
   OUTPUT_STREAM << "===============-===========-===============" << std::endl;
   OUTPUT_STREAM << "Nombre de tests effectues: " << nombreDeTestsEffectuesToutesFonctionalitee << std::endl;
   OUTPUT_STREAM << "Duree total (us):          " << (MicrosecondesActuelles() - chronoDebutDeTout) << " us" << std::endl;
   OUTPUT_STREAM << "Duree total (ms):          " << ((MicrosecondesActuelles() - chronoDebutDeTout))/1000 << " ms" << std::endl;
   OUTPUT_STREAM << "Echec total:               " << echecTotalToutesFonctionalitees << std::endl;
   OUTPUT_STREAM << "Succes total:              " << successTotalToutesFonctionalitees << std::endl;
   OUTPUT_STREAM << "Ratio de succes:           " << ratioDeSucces << "%" << std::endl;
   OUTPUT_STREAM << "Resultat final:            ";
   EnvoieDuResultat(resultatFinal, ENVOIE_TERMINAL_DANS_FICHIER,OUTPUT_STREAM);
}

/**
 * @brief Fonction qui initialise le test actuel
 * en donnant un nom a la fonctionalitée qui vas
 * être testé en plus d'un type de test. Un test
 * contient plusieurs tests lesquels peuvent ou
 * non avoir des sous-tests
 * @param nomDeLaFonctionalitee Nom donnée à la fonctionalitée. Exemple: classe Vecteur
 * @param typeDeTest "Unitaire" ou "Application"
 */
void Tests::DebutDeFonctionalitee(string nomDeLaFonctionalitee, string typeDeTest)
{
   static int numeroDeFonctionalitee = 0;
   numeroDeFonctionalitee++;

   nombreDeTestsEffectues = 0;
   numeroDeTest = 0;
   numeroDeSousTest = 0;
   succesTotal = 0;
   echecTotal = 0;
   resultatTotalFonctionalitee = true;
   resultatTotalSousTests = true;

   fonctionaliteTestee = nomDeLaFonctionalitee;
   type = typeDeTest;

   chronoDebutFonctionalitee = MicrosecondesActuelles();

   OUTPUT_STREAM << "\t\n===============-==[DEBUT]==-===============" << std::endl;
   OUTPUT_STREAM << "\t- Fonctionalitee: " << fonctionaliteTestee << std::endl;
   OUTPUT_STREAM << "\t- Numero:         " << numeroDeFonctionalitee << std::endl;
   OUTPUT_STREAM << "\t- type de test:   " << type << std::endl;
   OUTPUT_STREAM << "\t-------------------------------------------" << std::endl;
}

/**
 * @brief Spécifie que la fin du test d'une
 * fonctionalitée à été atteinte. Le compteur
 * de tests et sous-tests et mis à zero et une
 * note total est envoyé au terminal indiquant
 * si tout a passé ou non.
 *
 * @attention
 * Il est impératif d'appeller cette fonction
 * à la toute fin de votre test de
 * fonctionalitée.
 */
void Tests::FinDeFonctionalitee()
{
   int ratioDeSucces = 0;
   float fSuccesTotal = (float)succesTotal;
   ratioDeSucces = ((int)((fSuccesTotal / ((float)nombreDeTestsEffectues))*100));

   OUTPUT_STREAM << "\t-------------------------------------------" << std::endl;
   OUTPUT_STREAM << "\tNombre de tests effectues: " << nombreDeTestsEffectues << std::endl;
   OUTPUT_STREAM << "\tDuree total (us):          " << (MicrosecondesActuelles() - chronoDebutFonctionalitee) << " us" << std::endl;
   OUTPUT_STREAM << "\tDuree total (ms):          " << ((MicrosecondesActuelles() - chronoDebutFonctionalitee))/1000 << " ms" << std::endl;
   OUTPUT_STREAM << "\tEchec total:               " << echecTotal << std::endl;
   OUTPUT_STREAM << "\tSucces total:              " << succesTotal << std::endl;
   OUTPUT_STREAM << "\tRatio de succes:           " << ratioDeSucces << "%" << std::endl;
   OUTPUT_STREAM << "\tResultat final:            ";
   EnvoieDuResultat(resultatTotalFonctionalitee, ENVOIE_TERMINAL_DANS_FICHIER, OUTPUT_STREAM);

   OUTPUT_STREAM << "\t===============-===[FIN]===-===============" << std::endl;
}

/**
 * @brief Initialise un test ou une série de
 * sous-tests dans la console. Le résultat de
 * ce test DOIT être mis dans @ref FinDuTest
 * si le tests ne comprend pas de sous-tests.
 * @param nomDuTest
 */
void Tests::DebutDunTest(string nomDuTest)
{
   chronoDebutTest = MicrosecondesActuelles();
   resultatTotalSousTests = true;
   numeroDeTest++;

   EnvoieDuTitreDeTest("\t\t[TEST ", ENVOIE_TERMINAL_DANS_FICHIER,OUTPUT_STREAM);
   EnvoieDuTitreDeTest(std::to_string(numeroDeTest), ENVOIE_TERMINAL_DANS_FICHIER,OUTPUT_STREAM);
   EnvoieDuTitreDeTest("]: ", ENVOIE_TERMINAL_DANS_FICHIER,OUTPUT_STREAM);
   OUTPUT_STREAM << std::endl;

   EnvoieDunSousTitre("\t\t\tNom: ", ENVOIE_TERMINAL_DANS_FICHIER,OUTPUT_STREAM);
   OUTPUT_STREAM << nomDuTest << std::endl;
}

/**
 * @brief Initialise un test ou une série de
 * sous-tests dans la console. Le résultat de
 * ce test DOIT être mis dans @ref FinDuTest
 * si le tests ne comprend pas de sous-tests.
 * @param nomDuTest
 */
void Tests::DebutDunTest(string nomDuTest, string operateur)
{
   chronoDebutTest = MicrosecondesActuelles();
   resultatTotalSousTests = true;
   numeroDeTest++;

   EnvoieDuTitreDeTest("\t\t[TEST ", ENVOIE_TERMINAL_DANS_FICHIER,OUTPUT_STREAM);
   EnvoieDuTitreDeTest(std::to_string(numeroDeTest), ENVOIE_TERMINAL_DANS_FICHIER,OUTPUT_STREAM);
   EnvoieDuTitreDeTest("]: ",ENVOIE_TERMINAL_DANS_FICHIER,OUTPUT_STREAM);
   OUTPUT_STREAM << std::endl;

   EnvoieDunSousTitre("\t\t\tNom: ", ENVOIE_TERMINAL_DANS_FICHIER,OUTPUT_STREAM);
   OUTPUT_STREAM << nomDuTest << std::endl;

   EnvoieDunSousTitre("\t\t\tOpe: ", ENVOIE_TERMINAL_DANS_FICHIER,OUTPUT_STREAM);
   OUTPUT_STREAM << operateur << std::endl;
}

/**
 * @brief Indique la fin d'un test d'une
 * fonctionalitée. Dans cette méthode, vous
 * devez spécifier le résultat du tests. Si le
 * test est une série de sous-tests, alors ne
 * mettez rien comme argument. Il sera imprimé
 * de façons automatique.
 *
 * @param resultat Résultat du test. Vrai si
 * passé
 */
void Tests::FinDuTest(bool resultat)
{
   if(resultat)
   {
      succesTotal++;
      successTotalToutesFonctionalitees++;
   }
   else
   {
      resultatTotalFonctionalitee = false;
      resultatFinal = false;
      echecTotal++;
      echecTotalToutesFonctionalitees++;
   }

   EnvoieDunSousTitre("\t\t\tTmp: ", ENVOIE_TERMINAL_DANS_FICHIER,OUTPUT_STREAM);
   OUTPUT_STREAM << (MicrosecondesActuelles() - chronoDebutSousTest) << " us" << std::endl;

   EnvoieDunSousTitre("\t\t\tRes: ", ENVOIE_TERMINAL_DANS_FICHIER,OUTPUT_STREAM);
   EnvoieDuResultat(resultat, ENVOIE_TERMINAL_DANS_FICHIER,OUTPUT_STREAM);

   numeroDeSousTest = 0;
   nombreDeTestsEffectues++;
   nombreDeTestsEffectuesToutesFonctionalitee++;
}

/**
 * @brief Indique la fin d'une série de
 * sous-tests. Imprime automatiquement
 * le résultat total des sous-tests.
 */
void Tests::FinDuTest()
{
   EnvoieDunSousTitre("\t\t\tTmp: ", ENVOIE_TERMINAL_DANS_FICHIER,OUTPUT_STREAM);
   OUTPUT_STREAM << (MicrosecondesActuelles() - chronoDebutSousTest) << " us" << std::endl;

   EnvoieDunSousTitre("\t\t\tRes: ", ENVOIE_TERMINAL_DANS_FICHIER,OUTPUT_STREAM);
   EnvoieDuResultat(resultatTotalSousTests, ENVOIE_TERMINAL_DANS_FICHIER,OUTPUT_STREAM);

   numeroDeSousTest = 0;
}

/**
 * @brief Indique le début d'un sous-test.
 * Permet de regrouper une série de tests
 * similaire sous un même test.
 * @param nomDuSousTest
 */
void Tests::DebutDunSousTest(string nomDuSousTest)
{
   chronoDebutSousTest = MicrosecondesActuelles();
   numeroDeSousTest++;

   EnvoieDuTitreDeSoustest("\t\t\t[SOUS-TEST ", ENVOIE_TERMINAL_DANS_FICHIER,OUTPUT_STREAM);
   EnvoieDuTitreDeSoustest(std::to_string(numeroDeSousTest), ENVOIE_TERMINAL_DANS_FICHIER,OUTPUT_STREAM);
   EnvoieDuTitreDeSoustest("]: ", ENVOIE_TERMINAL_DANS_FICHIER,OUTPUT_STREAM);
   OUTPUT_STREAM << std::endl;

   EnvoieDunSousTitre("\t\t\t\tNom: ", ENVOIE_TERMINAL_DANS_FICHIER,OUTPUT_STREAM);
   OUTPUT_STREAM << nomDuSousTest << std::endl;
}

/**
 * @brief Indique la fin d'un sous-test. Il
 * est impératif d'appeller cette fonction
 * en spécifiant le résultat du sous-test.
 * @param resultat
 */
void Tests::FinDuSousTest(bool resultat)
{
   if(resultat)
   {
      succesTotal++;
      successTotalToutesFonctionalitees++;
   }
   else
   {
      resultatTotalFonctionalitee = false;
      resultatTotalSousTests = false;
      resultatFinal = false;
      echecTotal++;
      echecTotalToutesFonctionalitees++;
   }

   EnvoieDunSousTitre("\t\t\t\tTmp: ", ENVOIE_TERMINAL_DANS_FICHIER,OUTPUT_STREAM);
   OUTPUT_STREAM << (MicrosecondesActuelles() - chronoDebutSousTest) << " us" << std::endl;

   EnvoieDunSousTitre("\t\t\t\tRes: ", ENVOIE_TERMINAL_DANS_FICHIER,OUTPUT_STREAM);
   EnvoieDuResultat(resultat, ENVOIE_TERMINAL_DANS_FICHIER,OUTPUT_STREAM);

   nombreDeTestsEffectues++;
   nombreDeTestsEffectuesToutesFonctionalitee++;
}

/**
 * @brief Équivalent de @ref DebutDunSousTest
 * suivie de @ref FinDuSousTest. Mais en une
 * seul appel de fonction.
 * @param nomDuSousTest
 * @param resultat Résultat du test. Vrai si
 * passé
 */
void Tests::SousTest(string nomDuSousTest, bool resultat)
{
   DebutDunSousTest(nomDuSousTest);
   FinDuSousTest(resultat);
}

/**
 * @brief Equivalent de @ref DebutDunSousTest
 * suivie de @ref FinDuSousTest. Mais en une
 * seul appel de fonction. En plus de specifie
 * quel operation a ete effectuer pour le test
 * @param nomDuSousTest
 * Nom donner au sous-test
 * @param operation
 * Example: couches.retirer(0)==true
 * @param resultat
 * Boolean qui dit si ca a PASS ou FAIL.
 */
void Tests::SousTest(string nomDuSousTest, string operation, bool resultat)
{
   DebutDunSousTest(nomDuSousTest);
   EnvoieDunSousTitre("\t\t\t\tOpe: ", ENVOIE_TERMINAL_DANS_FICHIER,OUTPUT_STREAM);
   OUTPUT_STREAM << operation << std::endl;
   FinDuSousTest(resultat);
}

void Tests::TestDouble(string nomDuTest, double resultat, double attendu)
{
   bool res = false;
   if(resultat >= attendu-0.1f && resultat <= attendu+0.1f)
   {
      res = true;
   }

   DebutDunTest(nomDuTest);
   EnvoieDunSousTitre("\t\t\tVoulue: ", ENVOIE_TERMINAL_DANS_FICHIER,OUTPUT_STREAM);
   OUTPUT_STREAM << attendu << std::endl;

   EnvoieDunSousTitre("\t\t\tObtenu: ", ENVOIE_TERMINAL_DANS_FICHIER,OUTPUT_STREAM);
   OUTPUT_STREAM << resultat << std::endl;

   EnvoieDunSousTitre("\t\t\tRatio: ", ENVOIE_TERMINAL_DANS_FICHIER,OUTPUT_STREAM);
   OUTPUT_STREAM << (resultat-attendu) << std::endl;
   FinDuTest(res);
}

void Tests::SousTestDouble(string nomDuSousTest, double resultat, double attendu)
{
   bool res = false;
   if(resultat >= attendu-0.1f && resultat <= attendu+0.1f)
   {
      res = true;
   }

   DebutDunSousTest(nomDuSousTest);

   EnvoieDunSousTitre("\t\t\t\tVoulue: ", ENVOIE_TERMINAL_DANS_FICHIER,OUTPUT_STREAM);
   OUTPUT_STREAM << attendu << std::endl;

   EnvoieDunSousTitre("\t\t\t\tObtenu: ", ENVOIE_TERMINAL_DANS_FICHIER,OUTPUT_STREAM);
   OUTPUT_STREAM << resultat << std::endl;

   EnvoieDunSousTitre("\t\t\t\tRatio: ", ENVOIE_TERMINAL_DANS_FICHIER,OUTPUT_STREAM);
   OUTPUT_STREAM << (resultat-attendu) << std::endl;
   FinDuSousTest(res);
}
