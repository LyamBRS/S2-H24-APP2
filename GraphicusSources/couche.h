/********
 * @file: couche.h
 * @author: Francis Gratton, GRAF2102, COUS1912
 * @date: 9 janvier 2024
 * Modifie par : ...
 * @date : ...
 * @brief: Declaration de la classe pour une couche dans un
 *    canevas. La classe Couche gere un vecteur de pointeur de formes
 *    géometriques en accord avec les specifications de Graphicus.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef COUCHE_H
#define COUCHE_H

#include "Vecteur.h"
/**
 * @brief
 * Structure qui détermine les états
 * possible qu'une couche peut avoir.
 */
enum EtatsCouche
{
   /// @brief État initiale mis lorsque la couche est créé ainsi que lorsque réinitialisée. L'air d'une couche dans cette état est 0.
   Initialisee = 0,

   /// @brief Lorsqu'une couche est active, elle peut être modifiée.
   Active = 1,

   /// @brief État mis lorsqu'aucune modification sur la couche ne peut être fait.
   Inactive = 2
};


class Couche
{
   public:
      /// @brief Constructeur par default de Couche
      /// @brief La position de depart est de (0, 0) et l'etat initiale est Initialisee
      Couche();
      /// @brief Destructeur de Couche
      ~Couche();
   
      /// @brief Ajout d'une forme dans la couche
      /// @param x: La forme est ajouter.
      /// @return Retourne vrai si l'ajout a ete fait avec succes
      bool AjoutForme(Forme *f);
   
      /// @brief Retire la forme dans la couche a l'index specifier
      /// @param index: La forme est retire a l'index.
      /// @return Retourne la forme a l'index
      Forme* RetirerForme(int index);

      bool RetirerForme();
   
      /// @brief Dit la forme dans la couche a l'index specifier
      /// @param index: La forme a l'index designé.
      /// @return Retourne la forme a l'index
      Forme* FormeAIndex(int index);
   
      /// @brief Permet d'avoir la somme des aires de la couches
      /// @return Retourne l'aire de la couche
      double AireCouche();

      int GetIndexFormeCourante();
   
      /// @brief Permet de deplacer la couche
      /// @param horizontale: La couche va se deplacer sur l'axe X
      /// @param verticale: La couche va se deplacer sur l'axe Y
      /// @return Retourne si la translation a ete fait avec succes
      bool TranslationCouche(int horizontale, int verticale);
   
      /// @brief Permet de reinitialiser la translation de la couche au point de depart
      /// @return Retourne si la translation a ete fait avec succes
      bool ReinitialisationTranslationCouche();
   
      /// @brief Permet de reinitialiser la couche
      /// @return Retourne si la reinitialiser a ete fait avec succes
      bool ReinitialisationCouche();
   
      /// @brief Permet de changer l'etat de la fonction
      /// @return retourne si le changement a ete un succes
      bool ChangerEtat(EtatsCouche etat);
   
      /// @brief Affiche tous les formes dans la couche
      /// @return retourne si l'affiche est un succes
      bool AfficherCouche(ostream & s);

      bool AfficherCoucheSeulement(ostream& s);
   
      /// @brief Retourne si l'index est valide
      /// @param index
      /// @return
      bool VerifierIndex(int index);
   
      /// @brief Retourne combien de formes sont presentes dans la couche.
      /// @return int: nombre de formes dans le vecteur de la couche.
      int NombreDeFormes();
   
      /// @brief Retourne l'état actuel de la couche.
      /// @return EtatsCouche
      EtatsCouche Etat();

      bool ChoisirForme(int index);
      bool FormePrecedente();
      bool FormeSuivante();
      bool FormeDerniere();
      Forme* ObtenirFormeCourrant();


      //template <typename U>
      friend std::ostream& operator<<(std::ostream& os, const Couche& couche) {
          //std::cout << "COUCHE PRINT" << std::endl;

          os << "L ";

          if (couche._etatCouche == EtatsCouche::Active) os << "a\n";
          if (couche._etatCouche == EtatsCouche::Inactive) os << "x\n";
          if (couche._etatCouche == EtatsCouche::Initialisee) os << "i\n";

          for (int index = 0; index < couche._vecteur.Grosseur(); index++)
          {
              os << *couche._vecteur[index] << std::endl;
              
          }
          return os;
      }

   private:
      /// @brief Vecteur qui permet d'avoir tous les elements de la couche
      Vecteur<Forme*> _vecteur;
   
      /// @brief L'etat de la couche en question
      EtatsCouche _etatCouche;
   
      /// @brief Deplacement de la couche sur l'axe x
      int _translationHorizontale;
      /// @brief Deplacement de la couche sur l'axe y
      int _translationVerticale;
};



#endif
