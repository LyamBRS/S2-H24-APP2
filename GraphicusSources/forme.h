/********
 * @file: forme.h
 * @author: C.-A. Brunet
 * @date: 04 janvier 2024 (creation)
 * @brief: Declaration des classes de formes geometriques. La
 *    classe Forme ne doit pas etre modifiee. Ce fichier fait partie de
 *    la distribution de Graphicus.
********/

#ifndef FORME_H
#define FORME_H

#include <iostream>
#include "coordonnee.h"

using namespace std;

class Forme
{
public:
  Forme(int x = 0, int y = 0);
  virtual ~Forme();
  void translater(int deltaX, int deltaY);
  Coordonnee getAncrage();
  void setAncrage(Coordonnee c);
  virtual double aire() = 0;
  virtual void afficher(std::ostream & s) = 0;
  virtual void graphicusOut(std::ostream& s) = 0;

  friend std::ostream& operator<<(std::ostream& os, Forme& forme) {
	  forme.graphicusOut(os);
	  return os;
  }

  //template <typename U>
  //friend std::ostream& operator<<(std::ostream& os, const Forme& forme);
protected:
  Coordonnee ancrage;
};

#endif
