/********
 * @file: graphicus-01.cpp
 * @author: C.-A. Brunet, COUS1912, GRAF2102 
 * @date: 04 janvier 2024 (creation)
 * Modifie par : ...
 * @date : ...
 * @brief: gestionnaire de tests pour l'application Graphicus. Ce
 *    fichier fait partie de la distribution de Graphicus.
********/
#include <iostream>
#include <fstream>
#include "tests.h"

using namespace std;



int main()
{
   Tests tests;
   
   cout << "DÉBUT DE L'APPLICATION" << endl;

   tests.tests_unitaires();
   tests.tests_application();
   return 0;
}

