/**
 * @file resultatCouleur.h
 * @author COUS1912, GRAF2102
 * @brief
 * Permet de print un résultat en couleur sur
 * Linux et sur Windows
 * @version 0.1
 * @date 2024-01-10
 * @copyright Copyright (c) 2024
 */

#pragma once

#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define PURPLE  "\033[35m"
#define CYAN    "\033[36m"

void EnvoieDuResultat(bool resultat, bool utilisePasLaCouleur, std::ostream & s);

void EnvoieDuTitreDeTest(std::string titreDuTest, bool utilisePasLaCouleur, std::ostream & s);
void EnvoieDuTitreDeSoustest(std::string nomDuSousTest, bool utilisePasLaCouleur, std::ostream & s);
void EnvoieDunSousTitre(std::string sousTitre, bool utilisePasLaCouleur, std::ostream & s);
