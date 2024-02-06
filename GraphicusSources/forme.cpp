/********
 * @file: forme.cpp
 * @author: C.-A. Brunet
 * @date: 04 janvier 2024 (creation)
 * @brief: Implementation des methodes des classes decrites dans
 *    forme.h. Les methodes de la classe Forme ne doivent pas etre
 *    modifiees. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "forme.h"

Forme::Forme(int x1, int y1)
{
  ancrage.x = x1;
  ancrage.y = y1;
}

Forme::~Forme()
{
}

void Forme::translater(int deltaX, int deltaY)
{
   ancrage.x += deltaX;
   ancrage.y += deltaY;
}

Coordonnee Forme::getAncrage()
{
   return ancrage;
}

void Forme::setAncrage(Coordonnee c)
{
   ancrage = c;
}
