/**
 * @file Rectangle.cpp
 * @authors COUS1912, GRAF2102 
 * @brief
 * Fichier contenant les méthodes et membres
 * de la classe Rectangle.
 * @version 0.1
 * @date 2024-01-08
 * @copyright Copyright (c) 2024
 */

#include "Rectangle.h"

/// @brief Constructeur de base. Toutes les attribues seront à 0.
Rectangle::Rectangle()
{
    ancrage.x = 0;
    ancrage.y = 0;

    _largeur = LARGEUR_RECTANGLE_PAR_DEFAUT;
    _hauteur = HAUTEUR_RECTANGLE_PAR_DEFAUT;
}

/// @brief Constructeur permettant de spécifié les coordonnées du rectangle.
/// @param x: La coordonnée X du point inférieur gauche du rectangle.
/// @param y: La coordonnée Y du point inférieur gauche du rectangle.
Rectangle::Rectangle(int x, int y)
{
    ancrage.x = x;
    ancrage.y = y;

    _largeur = LARGEUR_RECTANGLE_PAR_DEFAUT;
    _hauteur = HAUTEUR_RECTANGLE_PAR_DEFAUT;
}

/// @brief Constructeur permettant de spécifié les coordonnées et dimensions du rectangle.
/// @param x: La coordonnée X, en pixel, du point inférieur gauche du rectangle.
/// @param y: La coordonnée Y, en pixel, du point inférieur gauche du rectangle.
/// @param largeur: La largeur horizontale du rectangle en pixels.
/// @param hauteur: La hauteur verticale du rectangle en pixels.
Rectangle::Rectangle(int x, int y, int largeur, int hauteur)
{
    ancrage.x = x;
    ancrage.y = y;

    if(largeur<0) largeur=-largeur;
    if(hauteur<0) hauteur=-hauteur;

    _largeur = largeur;
    _hauteur = hauteur;
}

/// @brief Destructeur de base
Rectangle::~Rectangle()
{

}

/// @brief Retourne la hauteur verticale du rectangle en pixels (get).
/// @return int: hauteur verticale du rectangle en pixels.
int Rectangle::Hauteur()
{
    return _hauteur;
}

/// @brief Permet de spécifier une nouvelle hauteur verticale en pixels au rectangle.
/// @param hauteur: Nouvelle hauteur du rectangle.
void Rectangle::Hauteur(int hauteur)
{
    if(hauteur<0) hauteur=-hauteur;
    _hauteur = hauteur;
}

/// @brief Retourne la largeur horizontale du rectangle en pixels (get).
/// @return int: largeur horizontale du rectangle en pixels.
int Rectangle::Largeur()
{
    return _largeur;
}

/// @brief Permet de spécifier une nouvelle largeur horizontale en pixels au rectangle.
/// @param hauteur: Nouvelle largeur du rectangle.
void Rectangle::Largeur(int largeur)
{
    if(largeur<0) largeur=-largeur;
    _largeur = largeur;
}

/// @brief Retourne l'aire du rectangle en multipliant la largeur et la hauteur.
/// @return: aire en pixel du rectangle
double Rectangle::aire()
{
    return _largeur * _hauteur;
}

/// @brief Affiche l'information d'un rectangle dans un output de text spécifié.
/// @param s: Genre std::cout
void Rectangle::afficher(ostream & s)
{
	//s << "Rectangle (x=" << ancrage.x << ", y=" << ancrage.y << ", l=" << _largeur << ", h=" << _hauteur << ", aire=" << aire() << ")\n";
    s << "R " << ancrage.x << " " << ancrage.y << " " << _largeur << " " << _hauteur << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Rectangle& rectangle) {
    os << "R " << rectangle.ancrage.x << " " << rectangle.ancrage.y << " " << rectangle._largeur << " " << rectangle._hauteur << std::endl;
    return os;
}

