/**
 * @file Rectangle.h
 * @authors COUS1912, GRAF2102
 * @brief
 * Fichier contenant la définition de la classe
 * de rectangle.
 * @version 0.1
 * @date 2024-01-08
 * @copyright Copyright (c) 2024
 */
#pragma once

#include "forme.h"
#include "coordonnee.h"

/// @brief Definie la largeur horizontale en pixel par defaut d'un rectangle s'il n'est pas specifie
#define LARGEUR_RECTANGLE_PAR_DEFAUT 10
/// @brief Definie la hauteur verticale en pixel par defaut d'un rectangle s'il n'est pas specifie
#define HAUTEUR_RECTANGLE_PAR_DEFAUT 10

/**
 * @brief
 * Classe permettant de cree des formes de
 * rectangles. Cette classe doit etre utilise par
 * l'entremise d'instances. Cette classe herite
 * des fonctionalitees de la classe generale
 * d'une @ref Forme. Contient une largeur et une
 * hauteur differentes l'une de l'autre ainsi que
 * des coordonées cartésiennes.
 */
class Rectangle : public Forme
{
    public:
        /// @brief Constructeur de base. Tous les attribues seront à 0.
        Rectangle();

        /// @brief Constructeur permettant de spécifié les coordonnées du rectangle.
        /// @param x: La coordonnée X du point inférieur gauche du rectangle.
        /// @param y: La coordonnée Y du point inférieur gauche du rectangle.
        Rectangle(int x, int y);

        /// @brief Constructeur permettant de spécifié les coordonnées et dimensions du rectangle.
        /// @param x: La coordonnée X, en pixel, du point inférieur gauche du rectangle.
        /// @param y: La coordonnée Y, en pixel, du point inférieur gauche du rectangle.
        /// @param largeur: La largeur horizontale du rectangle en pixels.
        /// @param hauteur: La hauteur verticale du rectangle en pixels.
        Rectangle(int x, int y, int largeur, int hauteur);

        /// @brief Destructeur de base
        ~Rectangle();

        /// @brief Retourne la hauteur verticale du rectangle en pixels (get).
        /// @return int: hauteur verticale du rectangle en pixels.
        int Hauteur();

        /// @brief Permet de spécifier une nouvelle hauteur verticale en pixels au rectangle.
        /// @param hauteur: Nouvelle hauteur du rectangle.
        void Hauteur(int hauteur);

        /// @brief Retourne la largeur horizontale du rectangle en pixels (get).
        /// @return int: largeur horizontale du rectangle en pixels.
        int Largeur();

        /// @brief Permet de spécifier une nouvelle largeur horizontale en pixels au rectangle.
        /// @param hauteur: Nouvelle largeur du rectangle.
        void Largeur(int largeur);

        /// @brief Retourne l'aire du rectangle en multipliant la largeur et la hauteur.
        /// @return: aire en pixel du rectangle
        double aire();

        /// @brief Affiche l'information d'un rectangle dans un output de text spécifié.
        /// @param s: Genre std::cout
        void afficher(ostream & s);

        void graphicusOut(std::ostream& s);

        //template <typename U>
        friend std::ostream& operator<<(std::ostream& os, const Rectangle& rectangle);

    private:
        /// @brief La hauteur du rectangle (vertical) en pixel.
        int _hauteur = 0;
        /// @brief la largeur du rectangle (horizontal) en pixel.
        int _largeur = 0;
};
