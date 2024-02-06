/**
 * @file Carre.h
 * @authors COUS1912, GRAF2102 
 * @brief
 * Fichier contenant la définition de la classe
 * de carre.
 * @version 0.1
 * @date 2024-01-08
 * @copyright Copyright (c) 2024
 */
#pragma once

#include "forme.h"
#include "coordonnee.h"

/// @brief Definie la largeur horizontale en pixel par defaut d'un carré s'il n'est pas specifie
#define LARGEUR_CARRE_PAR_DEFAUT 10

/**
 * @brief
 * Classe permettant de cree des formes de
 * carree. Cette classe doit etre utilise par
 * l'entremise d'instances. Cette classe herite
 * des fonctionalitees de la classe generale
 * d'une @ref Forme. Contient une largeur ainsi
 * que des coordonées cartésiennes.
 */
class Carre : public Forme
{
    public:
        /// @brief Constructeur de base. Tous les attribues seront à 0.
        Carre();

        /// @brief Constructeur permettant de spécifié les coordonnées du carré.
        /// @param x: La coordonnée X du point inférieur gauche du carré.
        /// @param y: La coordonnée Y du point inférieur gauche du carré.
        Carre(int x, int y);

        /// @brief Constructeur permettant de spécifié les coordonnées et dimensions du carré.
        /// @param x: La coordonnée X, en pixel, du point inférieur gauche du carré.
        /// @param y: La coordonnée Y, en pixel, du point inférieur gauche du carré.
        /// @param largeur: La largeur du carré en pixels.
        Carre(int x, int y, int largeur);

        /// @brief Destructeur de base
        ~Carre();

        /// @brief Retourne la largeur du carré en pixels (get).
        /// @return int: largeur du carré en pixels.
        int Largeur();

        /// @brief Permet de spécifier une nouvelle largeur en pixels au carré.
        /// @param hauteur: Nouvelle largeur du carré.
        void Largeur(int largeur);

        /// @brief Retourne l'aire du carré en multipliant la largeur avec elle-même.
        /// @return: aire en pixel du carré
        double aire();

        /// @brief Affiche l'information du carré dans un output de text spécifié.
        /// @param s: Genre std::cout
        void afficher(ostream & s);

    private:
        /// @brief la largeur du carré en pixel.
        int _largeur = 0;
};
