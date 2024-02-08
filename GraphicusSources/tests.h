/********
 * @file: tests.h
 * @author: C.-A. Brunet, GRAF2102, COUS1912
 * @date: 08 janvier 2018 (creation)
 * @brief: Declaration de la classe pour les tests de Graphicus.
 *    Ce fichier peut etre adapte a vos besoins de tests. Ce fichier
 *    fait partie de la distribution de Graphicus.
********/

#ifndef TESTS_H
#define TESTS_H

#include <chrono>
#include <iostream>
#include <fstream>
#include "canevas.h"
#include "couche.h"
#include "Vecteur.h"
#include "forme.h"
#include "Cercle.h"
#include "Carre.h"
#include "Rectangle.h"
#include "resultatCouleur.h"
#include "monInterface.h"

using namespace std;

class Tests
{
public:
   // Methodes pour les tests unitaires des classes
   void tests_unitaires_formes();
   void tests_unitaires_vecteur();
   void tests_unitaires_couche();
   void tests_unitaires_canevas();
   void tests_unitaires(); // Appel de tous les tests unitaires

   // Methodes pour les tests unitaires des classes
   void tests_application_cas_01();
   void tests_application_cas_02(MonInterface* monInterface);
   void tests_application(); // Appel de tous les tests applicatifs

private:
   /// @brief Le nom de la fonctionalitée en cours de test. Exemple: classe Vecteur
   string fonctionaliteTestee = "DEFAULT";
   /// @brief le type de test effectué. Exemple: Unitaire, application
   string type = "DEFAULT";
   /// @brief Le titre du test. Exemple: Test de création de classes.
   string titreDuTest = "DEFAULT";
   /// @brief Le titre du sous test. Exemple: Création d'un vecteur int
   string titreDuSousTest = "DEFAULT";

   int numeroDeTest = 0;
   int numeroDeSousTest = 0;

   int succesTotal = 0;
   int echecTotal = 0;
   int nombreDeTestsEffectues = 0;

   int successTotalToutesFonctionalitees = 0;
   int echecTotalToutesFonctionalitees = 0;
   int nombreDeTestsEffectuesToutesFonctionalitee = 0;

   int chronoDebutSousTest = 0;
   int chronoFinSousTest = 0;

   int chronoDebutFonctionalitee = 0;
   int chronoFinFonctinalitee = 0;

   int chronoDebutDeTout = 0;
   int chronoFinDeTout = 0;

   int chronoDebutTest = 0;
   int chronoFinTest = 0;

   /// @brief Est mis a false du moment qu'un sous-test ne réussi pas.
   bool resultatTotalSousTests = false;
   /// @brief Est mis à false du moment qu'un test ou sous-test ne réussi pas.
   bool resultatTotalFonctionalitee = false;

   bool resultatFinal = true;

   /// @brief Retourne le nombre de microsecondes actuel par std::chrono
   /// @return int: Nombre de microsecondes depuis le début du programme.
   int MicrosecondesActuelles();

   /**
    * @brief A appeller au tout début, avant de commencer le premier test.
    * Print un header.
    */
   void DebutDeTout();
   /**
    * @brief Appeller a la toute fin, une fois que tous les tests ont été faits.
    * Et toutes les fonctionalitées faites.
    */
   void FinDeTout();

   /**
    * @brief Fonction qui initialise le test actuel
    * en donnant un nom a la fonctionalitée qui vas
    * être testé en plus d'un type de test. Un test
    * contient plusieurs tests lesquels peuvent ou
    * non avoir des sous-tests
    * @param nomDeLaFonctionalitee Nom donnée à la fonctionalitée. Exemple: classe Vecteur
    * @param typeDeTest "Unitaire" ou "Application"
    */
   void DebutDeFonctionalitee(string nomDeLaFonctionalitee, string typeDeTest);

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
   void FinDeFonctionalitee();

   /**
    * @brief Initialise un test ou une série de
    * sous-tests dans la console. Le résultat de
    * ce test DOIT être mis dans @ref FinDuTest
    * si le tests ne comprend pas de sous-tests.
    * @param nomDuTest
    */
   void DebutDunTest(string nomDuTest);

   /**
    * @brief Initialise un test ou une série de
    * sous-tests dans la console. Le résultat de
    * ce test DOIT être mis dans @ref FinDuTest
    * si le tests ne comprend pas de sous-tests.
    * @param nomDuTest
    */
   void DebutDunTest(string nomDuTest, string operateur);
   
   /**
    * @brief 
    * 
    * fonctionalitée. Dans cette méthode, vous
    * devez spécifier le résultat du tests. Si le
    * test est une série de sous-tests, alors ne
    * mettez rien comme argument. Il sera imprimé
    * de façons automatique.
    *
    * @param resultat Résultat du test. Vrai si
    * passé
    */
   void FinDuTest(bool resultat);


   /**
    * @brief Indique la fin d'une série de
    * sous-tests. Imprime automatiquement
    * le résultat total des sous-tests.
    */
   void FinDuTest();

   /**
    * @brief Équivalent de @ref DebutDunSousTest
    * suivie de @ref FinDuSousTest. Mais en une
    * seul appel de fonction.
    * @param nomDuSousTest
    * @param resultat Résultat du test. Vrai si
    * passé
    */
   void SousTest(string nomDuSousTest, bool resultat);

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
   void SousTest(string nomDuSousTest, string operation, bool resultat);

   void SousTestDouble(string nomDuSousTest, double resultat, double attendu);

   void TestDouble(string nomDuTest, double resultat, double attendu);

   /**
    * @brief Indique le début d'un sous-test.
    * Permet de regrouper une série de tests
    * similaire sous un même test.
    * @param nomDuSousTest
    */
   void DebutDunSousTest(string nomDuSousTest);

   /**
    * @brief Indique la fin d'un sous-test. Il
    * est impératif d'appeller cette fonction
    * en spécifiant le résultat du sous-test.
    * @param resultat Résultat du test. Vrai si
    * passé
    */
   void FinDuSousTest(bool resultat);
};

#endif
