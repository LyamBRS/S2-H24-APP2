/**
 * @file Cercle.h
 * @authors COUS1912, GRAF2102 
 * @brief
 * Fichier contenant la définition de la classe
 * de Cercle.
 * @version 0.1
 * @date 2024-01-08
 * @copyright Copyright (c) 2024
 */
#pragma once

#include "forme.h"
#include "coordonnee.h"

/// @brief Definie le rayon en pixel par defaut d'un cercle s'il n'est pas specifié
#define RAYON_CERCLE_PAR_DEFAUT 10

/**
 * @brief
 * Classe permettant de cree des formes de
 * cercle. Cette classe doit être utilise par
 * l'entremise d'instances. Cette classe hérite
 * des fonctionalitées de la classe générale
 * d'une @ref Forme. Contient un rayon ainsi que
 * des coordonées cartésiennes.
 */
class Cercle : public Forme
{
    public:
        /// @brief Constructeur de base. Tous les attribues seront à 0.
        Cercle();

        /// @brief Constructeur permettant de spécifié les coordonnées du cercle.
        /// @param x: La coordonnée X, en pixel, du point inférieur gauche du cercle.
        /// @param y: La coordonnée Y, en pixel, du point inférieur gauche du cercle.
        Cercle(int x, int y);

        /// @brief Constructeur permettant de spécifié les coordonnées et dimensions du cercle.
        /// @param x: La coordonnée X, en pixel, du point inférieur gauche du cercle.
        /// @param y: La coordonnée Y, en pixel, du point inférieur gauche du cercle.
        /// @param largeur: La largeur du cercle en pixels.
        Cercle(int x, int y, int rayon);

        /// @brief Destructeur de base
        ~Cercle();

        /// @brief Retourne le rayon du cercle en pixels (get).
        /// @return int: rayon du cercle en pixels.
        int Rayon();

        /// @brief Permet de spécifier un nouveau rayon en pixels au cercle.
        /// @param hauteur: Nouveau rayon du cercle.
        void Rayon(int rayon);

        /// @brief Retourne l'aire du cercle en fesant pi*rayon^2.
        /// @return: aire en pixel du cercle
        double aire();

        /// @brief Affiche l'information du cercle dans un output de text spécifié.
        /// @param s: Genre std::cout
        void afficher(ostream & s);

        void graphicusOut(std::ostream& s);

        //template <typename U>
        friend std::ostream& operator<<(std::ostream& os, const Cercle& cercle);

    private:
        /// @brief le rayon du cercle en pixel.
        int _rayon = 0;
};
