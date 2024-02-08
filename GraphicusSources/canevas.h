/********
 * @file: canevas.h
 * @author: C.-A. Brunet, GRAF2102, COUS1912
 * @date: 04 janvier 2024 (creation)
 * @brief: Declaration de la classe Canevas. La classe gere un
 *    tableau de couches en accord avec les specifications de Graphicus.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef CANEVAS_H
#define CANEVAS_H

#include <sstream>
#include <iostream>
#include "forme.h"
#include "couche.h"
#include "Vecteur.h"
#include "../GraphicusSources/forme.h"
#include "../GraphicusSources/Carre.h"
#include "../GraphicusSources/Cercle.h"
#include "../GraphicusSources/Rectangle.h"

const int MAX_COUCHES = 5;

#define NOMBRE_DE_COUCHES_INITIALES 1
#define AUCUNE_COUCHES_ACTIVE -1

using namespace std;

/**
 * @brief
 * Classe permettant de créé des nouveau canevas,
 * c'est-à-dire des nouveaux dessins composés de
 * une ou plusieurs @ref Couches lesquels
 * pourront avoir une ou plusieurs @ref Forme,
 * comme des Rectangles, Carrés et des Cercles.
 */
class Canevas
{
public:
   /**
    * @brief
    * Constructeur permettant de créé un nouveau
    * canevas, c'est-à-dire un nouveau dessin.
    */
   Canevas();

   /// @brief Destructeur typique.
   ~Canevas();

   /**
    * @brief
    * Réinitialise le canevas au grand complet.
    * Toutes les couches sont détruites ainsi que
    * les formes qui les composent.
    * @return true:
    * Réinitialisation faite avec succès
    * @return false:
    * Un problème empèche le canevas d'être
    * réinitialisé.
    */
   bool reinitialiser();

   /**
    * @brief
    * Permet d'avoir le pointeur d'une forme a un
    * index donne. TOUJOURS VERIFIER L'INDEX
    * @param index
    * Index ou se trouve la forme a retourner
    * @return Forme*
    * Pointeur de forme.
    */
   Forme* FormeAIndex(int index);

   /**
    * @brief
    * Permet de réinitialiser une couche du
    * canevas. Toutes les formes seront détruites
    * @param index
    * Le numéro de la couche à réinitialiser.
    * @return true:
    * Couche réinitialisé sans problème.
    * @return false:
    * Un problème empèche la couche d'être
    * réinitialisé. L'indexe fournis est
    * probablement mauvaise.
    */
   bool reinitialiserCouche(int index);

   /**
    * @brief
    * Active une couche spécifié par un index
    * et retourne si cela a été un succès ou non.
    * @attention
    * Désactive tout les autres couches active
    * @param index
    * La couche a activer.
    * @return true:
    * La couche a été activé avec succès.
    * @return false:
    * Un problème empèche la couche d'être
    * activé. L'index est probablement mauvais.
    */
   bool activerCouche(int index);
   /**
    * @brief
    * Désactive une couche spécifié par un index
    * et retourne si cela a été un succès ou non.
    * @param index:
    * La couche a désactiver.
    * @return true:
    * La couche a été désactivé avec succès.
    * @return false:
    * Un problème empèche la couche d'être
    * désactivé.L'index est probablement mauvais.
    */
   bool desactiverCouche(int index);

   /**
    * @brief
    * Retourne un pointeur sur la couche active.
    * @attention
    * Toujours verifier que l'index est valide
    * avant d'appeller cette fonction.
    * @param index 
    * @return Couche* 
    */
   Couche* coucheAIndex(int index);


   /**
    * @brief
    * Permet d'ajouter une forme sur la couche
    * active. La fonction retourne si cela a été
    * un succès ou non.
    * @param p_forme
    * Un objet de type Forme à ajouté sur la
    * couche active.
    * @return true:
    * Forme spécifié ajouté avec succès.
    * @return false:
    * Un problème empèche la forme d'être ajouté
    */
   bool ajouterForme(Forme *p_forme);
   /**
    * @brief
    * Permet de supprimer une forme situé dans la
    * couche active. La fonction retourne si cela
    * a été un succès ou non.
    * @param index:
    * L'index ou se trouve la forme à retirer.
    * @return true:
    * La forme a été retiré avec succès
    * @return false:
    * La forme n'a pas pu être retirer.
    */
   bool retirerForme(int index);

   /**
    * @brief
    * Permet d'ajouter une couche dans le canevas
    * La fonction retourne si cela a été un
    * succès ou non.
    * @param p_couche
    * Un objet de type Couche à ajouté dans le
    * canevas
    * @return true:
    * Couche spécifié ajouté avec succès.
    * @return false:
    * Un problème empèche la couche d'être ajouté
    */
   bool ajouterCouche(Couche *p_couche);
   /**
    * @brief
    * Permet de supprimer une couche situé dans
    * le canevas. La fonction retourne si cela
    * a été un succès ou non.
    * @param index:
    * L'index ou se trouve la couche à retirer.
    * @return true:
    * La couche a été retiré avec succès
    * @return false:
    * La couche n'a pas pu être retirer.
    */
   bool retirerCouche(int index);

   bool retirerCouche();
   bool retirerForme();

   /**
    * @brief
    * Retourne l'aire total du canevas. L'aire du
    * canevas est la somme de toutes les couches
    * qui le compose.
    *
    * @return double
    * Aire total du canevas (somme de toutes les)
    * couches.
    */
   double aire();

   /**
    * @brief
    * Bouge la couche actuellement active sur le
    * plan cartésien par un delta donnée. Si
    * aucune couche n'est active, la fonction ne
    * marchera pas.
    * @param deltaX
    * De combien la couche active doit-elle
    * bouger sur l'axe des X.
    * @param deltaY
    * De combien la couche active doit-elle
    * bouger sur l'axe des Y.
    * @return true:
    * La translation a bien fonctionnée.
    * @return false:
    * La translation n'a pas fonctionnée.
    */
   bool translater(int deltaX, int deltaY);

   /**
    * @brief
    * Imprime dans un terminal toutes les info
    * pertinantes du canevas, ses couches, et
    * les formes étant dedans.
    * @param s
    */
   void afficher(ostream & s);

   /**
    * @brief Retourne le nombre de couches qui
    * sont actuellement présentes dans le canevas
    * Par défaut, 0 couches se trouvent dans le
    * canevas.
    * @return int
    * Nombre de couches dans le canevas. Défault
    * à 0.
    */
   int NombreDeCouches();

   bool ChoisirCouche(int index);
   bool CouchePrecedente();
   bool CoucheSuivante();
   bool CoucheDerniere();
   Couche* ObtenirCoucheCourant();

   bool ChoisirForme(int index);
   bool FormePrecedente();
   bool FormeSuivante();
   bool FormeDerniere();
   Forme* ObtenirFormeCourant();

   int GetIndexCoucheActive();

   friend std::ostream& operator<<(std::ostream& os, const Canevas& canevas) {
       //std::cout << "CANEVAS PRINT" << std::endl;
       for (int i = 0; i < canevas.couches.Grosseur(); i++)
       {
           // Idk, this/friend moment. Cant be asked. Good luck.
           // Also dont know why it would make sense to access private attributes in an overload but only SOME times. Fuck you thats why.
           Couche* couche = canevas.couches[i];

           os << *couche;
       }
       return os;
   }

   friend std::istringstream& operator>>(std::istringstream& os, Canevas& canevas) {
       //std::cout << "CANEVAS PRINT" << std::endl;
        
        
       char letter;
       char letter2 = 'i';
       int num;
       int tabNum[4];
       int index = 0;
       int nbCouche = -1;

       while (os >> letter) {
           index = 0;
           if (letter == 'L')
           {
               if (nbCouche >= 0)
               {
                   if (letter2 == 'a')canevas.couches[nbCouche]->ChangerEtat(EtatsCouche::Active);
                   if (letter2 == 'x')canevas.couches[nbCouche]->ChangerEtat(EtatsCouche::Inactive);
                   
               }
               
               nbCouche++;
               while (os >> letter2)
               {
                   
                   break;
               }
           }
           // Read numbers until the end of the line or a non-integer character
           while (os >> num) {
               tabNum[index] = num;
               index++;
           }
           os.clear();
           
           switch (letter) //premier charactere dit ce que c'est
           {
           case 'L'://couche
               canevas.ajouterCouche(new Couche());
               if(letter2 == 'i')
                   canevas.couches[nbCouche]->ChangerEtat(EtatsCouche::Initialisee);
               else
               canevas.couches[nbCouche]->ChangerEtat(EtatsCouche::Active);
               break;

           case 'K'://carre
               canevas.couches[nbCouche]->AjoutForme(new Carre(tabNum[0], tabNum[1], tabNum[2]));
               break;

           case 'R'://rectangle
               canevas.couches[nbCouche]->AjoutForme(new Rectangle(tabNum[0], tabNum[1], tabNum[2], tabNum[3]));
               break;

           case 'C'://cercle
               canevas.couches[nbCouche]->AjoutForme(new Cercle(tabNum[0], tabNum[1], tabNum[2]));
               break;
           }

       }


       if (letter2 == 'a')canevas.couches[nbCouche]->ChangerEtat(EtatsCouche::Active);
       if (letter2 == 'x')canevas.couches[nbCouche]->ChangerEtat(EtatsCouche::Inactive);
       
       

       
       
       return os;
   }

private:
   /// @brief Vecteur qui permet de stocker dynamiquement un très grand nombre de couches
   Vecteur<Couche*> couches;

   int indexCoucheActive = AUCUNE_COUCHES_ACTIVE;
};

#endif
