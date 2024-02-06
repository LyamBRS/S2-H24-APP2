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

#include "resultatCouleur.h"

#ifdef _WIN32
    #include "Windows.h"
#endif
#include <iostream>

void EnvoieDuResultat(bool resultat, bool utilisePasLaCouleur, std::ostream & s)
{
   std::string resultatTotal = "Echec";
   std::string colour = RED;
   if(resultat)
   {
      resultatTotal = "Succes";
      colour = GREEN;
   }

   if(utilisePasLaCouleur)
   {
      s << resultatTotal << std::endl;
      return;
   }

   #ifdef _WIN32
      HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
      if(colour == GREEN)
      {
         SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
      }
      else
      {
         SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
      }

      s << resultatTotal << std::endl;
      SetConsoleTextAttribute(hConsole, 7);
   #else
      s << colour << resultatTotal << RESET << std::endl;
   #endif
}

void EnvoieDuTitreDeTest(std::string titreDuTest, bool utilisePasLaCouleur, std::ostream & s)
{
   if(utilisePasLaCouleur)
   {
      s << titreDuTest;
      return;
   }

   #ifdef _WIN32
      HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
      SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);

      s << titreDuTest;
      SetConsoleTextAttribute(hConsole, 7);
   #else
      s << CYAN << titreDuTest << RESET;
   #endif
}

void EnvoieDuTitreDeSoustest(std::string nomDuSousTest, bool utilisePasLaCouleur, std::ostream & s)
{
   if(utilisePasLaCouleur)
   {
      s << nomDuSousTest;
      return;
   }

   #ifdef _WIN32
      HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
      SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);

      s << nomDuSousTest;
      SetConsoleTextAttribute(hConsole, 7);
   #else
      s << BLUE << nomDuSousTest << RESET;
   #endif
}

void EnvoieDunSousTitre(std::string sousTitre, bool utilisePasLaCouleur, std::ostream & s)
{
   if(utilisePasLaCouleur)
   {
      s << sousTitre;
      return;
   }

   #ifdef _WIN32
      HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
      SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
      SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
      SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
      SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);

      s << sousTitre;
      SetConsoleTextAttribute(hConsole, 7);
   #else
      s << sousTitre;
   #endif
}
