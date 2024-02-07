/**
 * @file Cercle.cpp
 * @authors COUS1912, GRAF2102 
 * @brief
 * Fichier contenant les méthodes et membres
 * de la classe Cercle.
 * @version 0.1
 * @date 2024-01-08
 * @copyright Copyright (c) 2024
 */

#include "Cercle.h"

/// @brief Constructeur de base. Toutes les attribues seront à 0.
Cercle::Cercle()
{
    ancrage.x = 0;
    ancrage.y = 0;

    _rayon = RAYON_CERCLE_PAR_DEFAUT;
}

/// @brief Constructeur permettant de spécifié les coordonnées du cercle.
/// @param x: La coordonnée X, en pixel, du point inférieur gauche du cercle.
/// @param y: La coordonnée Y, en pixel, du point inférieur gauche du cercle.
Cercle::Cercle(int x, int y)
{
    ancrage.x = x;
    ancrage.y = y;

    _rayon = RAYON_CERCLE_PAR_DEFAUT;
}

/// @brief Constructeur permettant de spécifié les coordonnées et rayon du cercle.
/// @param x: La coordonnée X, en pixel, du point inférieur gauche du cercle.
/// @param y: La coordonnée Y, en pixel, du point inférieur gauche du cercle.
/// @param rayon: Le rayon du cercle en pixels.
Cercle::Cercle(int x, int y, int rayon)
{
    ancrage.x = x;
    ancrage.y = y;

    if(rayon<0) rayon=0;
    _rayon = rayon;
}

/// @brief Destructeur de base
Cercle::~Cercle()
{

}

/// @brief Retourne le rayon du cercle en pixels (get).
/// @return int: rayon du cercle en pixels.
int Cercle::Rayon()
{
    return _rayon;
}

/// @brief Permet de spécifier un nouveau rayon en pixels au cercle.
/// @param hauteur: Nouveau rayon du cercle.
void Cercle::Rayon(int rayon)
{
    if(rayon<0) rayon=-rayon;
    _rayon = rayon;
}

/// @brief Retourne l'aire du cercle en fesant pi*rayon^2.
/// @return: aire en pixel du cercle
double Cercle::aire()
{
    return 3.14f * (((double)(_rayon)) * ((double)(_rayon)));
}

/// @brief Affiche l'information d'un rectangle dans un output de text spécifié.
/// @param s: Genre std::cout
void Cercle::afficher(ostream & s)
{
	s << "Cercle (x=" << ancrage.x << ", y=" << ancrage.y << ", r=" << _rayon << ", aire=" << aire() << ")\n";
}

//template <typename U>
std::ostream& operator<<(std::ostream& os, const Cercle& cercle) {
    os << "C " << cercle.ancrage.x << " " << cercle.ancrage.y << " " << cercle._rayon << std::endl;
    return os;
}