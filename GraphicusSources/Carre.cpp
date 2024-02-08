/**
 * @file Carre.cpp
 * @authors COUS1912, GRAF2102 
 * @brief
 * Fichier contenant les méthodes et membres
 * de la classe Carre.
 * @version 0.1
 * @date 2024-01-08
 * @copyright Copyright (c) 2024
 */
#include "Carre.h"

/// @brief Constructeur de base. Toutes les attribues seront à 0.
Carre::Carre()
{
    ancrage.x = 0;
    ancrage.y = 0;

    _largeur = LARGEUR_CARRE_PAR_DEFAUT;
}

/// @brief Constructeur permettant de spécifié les coordonnées du carré.
/// @param x: La coordonnée X du point inférieur gauche du carré.
/// @param y: La coordonnée Y du point inférieur gauche du carré.
Carre::Carre(int x, int y)
{
    ancrage.x = x;
    ancrage.y = y;

    _largeur = LARGEUR_CARRE_PAR_DEFAUT;
}

/// @brief Constructeur permettant de spécifié les coordonnées et dimensions du carré.
/// @param x: La coordonnée X, en pixel, du point inférieur gauche du carré.
/// @param y: La coordonnée Y, en pixel, du point inférieur gauche du carré.
/// @param largeur: La largeur du carré en pixels.
Carre::Carre(int x, int y, int largeur)
{
    ancrage.x = x;
    ancrage.y = y;

    if(largeur<0) largeur=-largeur;
    _largeur = largeur;
}

/// @brief Destructeur de base
Carre::~Carre()
{

}

/// @brief Retourne la largeur du carré en pixels (get).
/// @return int: largeur horizontale du rectangle en pixels.
int Carre::Largeur()
{
    return _largeur;
}

/// @brief Permet de spécifier une nouvelle largeur en pixels au carré.
/// @param hauteur: Nouvelle largeur du rectangle.
void Carre::Largeur(int largeur)
{
    if(largeur<0) largeur=-largeur;
    _largeur = largeur;
}

/// @brief Retourne l'aire du carré en multipliant la largeur et la hauteur.
/// @return: aire en pixel du rectangle
double Carre::aire()
{
    return _largeur * _largeur;
}

/// @brief Affiche l'information d'un carré dans un output de text spécifié.
/// @param s: Genre std::cout
void Carre::afficher(ostream & s)
{
	//s << "Carre (x=" << ancrage.x << ", y=" << ancrage.y << ", c=" << _largeur << ", aire=" << aire() << ")\n";
    s << "K " << ancrage.x << " " << ancrage.y << " " << _largeur << std::endl;
}


//template <typename U>
std::ostream& operator<<(std::ostream& os, const Carre& carre) {
    os << "K " << carre.ancrage.x << " " << carre.ancrage.y << " " << carre._largeur << std::endl;
    return os;
}