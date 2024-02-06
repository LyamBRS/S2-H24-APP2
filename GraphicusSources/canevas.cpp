/********
 * @file: canevas.cpp
 * @author: C.-A. Brunet, GRAF2102, COUS1912
 * @date: 04 janvier 2024 (creation)
 * Modifie par : ...
 * @date : ...
 * @brief: Implementation des methodes des classes decrites dans
 *    canevas.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "canevas.h"

/**
 * @brief
 * Constructeur permettant de créé un nouveau
 * canevas, c'est-à-dire un nouveau dessin.
 */
Canevas::Canevas()
{
   Couche* nouvelleCouche1 = new Couche();
   Couche* nouvelleCouche2 = new Couche();
   Couche* nouvelleCouche3 = new Couche();
   Couche* nouvelleCouche4 = new Couche();
   Couche* nouvelleCouche5 = new Couche();

   nouvelleCouche1->ChangerEtat(EtatsCouche::Active);
   couches.Ajouter(nouvelleCouche1); // Couche 0
   couches.Ajouter(nouvelleCouche2); // Couche 0
   couches.Ajouter(nouvelleCouche3); // Couche 0
   couches.Ajouter(nouvelleCouche4); // Couche 0
   couches.Ajouter(nouvelleCouche5); // Couche 0
   indexCoucheActive = 0;
}

/// @brief Destructeur typique.
Canevas::~Canevas()
{
   couches.~Vecteur();
}

/**
 * @brief
 * Retourne un pointeur sur la couche active.
 * @attention
 * Toujours verifier que l'index est valide
 * avant d'appeller cette fonction.
 * @param index 
 * @return Couche* 
 */
Couche* Canevas::coucheAIndex(int index)
{
   if(!couches.VerifierIndex(index))
   {
      return nullptr;
   }

   return couches.DonneAIndex(index);
}

/**
 * @brief
 * Permet d'avoir le pointeur d'une forme a un
 * index donne. TOUJOURS VERIFIER L'INDEX
 * @param index
 * Index ou se trouve la forme a retourner
 * @return Forme*
 * Pointeur de forme.
 */
Forme* Canevas::FormeAIndex(int index)
{
   if(!couches.DonneAIndex(indexCoucheActive)->VerifierIndex(index))
   {
      return nullptr;
   }
   return couches.DonneAIndex(indexCoucheActive)->FormeAIndex(index);
}

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
bool Canevas::reinitialiser()
{
   // Détruire toute les couches existantes.
   couches.~Vecteur();
   couches = Vecteur<Couche*>();

   // Créé une nouvelle couche 0 et un nouveau vecteur. Cela deverait donné plus de mémoire.
   Couche* nouvelleCouche1 = new Couche();
   Couche* nouvelleCouche2 = new Couche();
   Couche* nouvelleCouche3 = new Couche();
   Couche* nouvelleCouche4 = new Couche();
   Couche* nouvelleCouche5 = new Couche();

   nouvelleCouche1->ChangerEtat(EtatsCouche::Active);
   couches.Ajouter(nouvelleCouche1); // Couche 0
   couches.Ajouter(nouvelleCouche2); // Couche 1
   couches.Ajouter(nouvelleCouche3); // Couche 2
   couches.Ajouter(nouvelleCouche4); // Couche 3
   couches.Ajouter(nouvelleCouche5); // Couche 4
   indexCoucheActive = 0;
   return true;
}

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
bool Canevas::reinitialiserCouche(int index)
{
   if(!couches.VerifierIndex(index))
   {
      // Index spécifié n'est pas valide.
      return false;
   }

   return couches.DonneAIndex(index)->ReinitialisationCouche();
}

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
bool Canevas::activerCouche(int index)
{
   if(!couches.VerifierIndex(index))
   {
      // Index spécifié n'est pas valide.
      return false;
   }

   // Désactiver toutes les couches.
   for(int indexDeCouche=0; indexDeCouche < couches.Grosseur(); indexDeCouche++)
   {
      if(!couches.VerifierIndex(indexDeCouche))
      {
         // Index spécifié n'est pas valide.
         return false;
      }
      couches.DonneAIndex(indexDeCouche)->ChangerEtat(EtatsCouche::Inactive);
   }
   indexCoucheActive = index;
   return couches.DonneAIndex(index)->ChangerEtat(EtatsCouche::Active);
}

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
bool Canevas::desactiverCouche(int index)
{
   if(!couches.VerifierIndex(index))
   {
      // Index spécifié n'est pas valide.
      return false;
   }

   if(indexCoucheActive == index)
   {
      indexCoucheActive = AUCUNE_COUCHES_ACTIVE;
   }

   return couches.DonneAIndex(index)->ChangerEtat(EtatsCouche::Inactive);
}

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
bool Canevas::ajouterForme(Forme *p_forme)
{
   if(!couches.VerifierIndex(indexCoucheActive))
   {
      // Index actif spécifié n'est pas valide.
      return false;
   }

   if(p_forme == nullptr)
   {
      // Pointeur invalide.
      return false;
   }

   return couches.DonneAIndex(indexCoucheActive)->AjoutForme(p_forme);
}

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
bool Canevas::retirerForme(int index)
{
   if(!couches.VerifierIndex(indexCoucheActive))
   {
      // Index actif spécifié n'est pas valide.
      return false;
   }

   return couches.DonneAIndex(indexCoucheActive)->RetirerForme(index);
}

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
bool Canevas::ajouterCouche(Couche *p_couche)
{
   return couches.Ajouter(p_couche);
}

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
bool Canevas::retirerCouche(int index)
{
   if(!couches.VerifierIndex(index))
   {
      return false;
   }

   if(index == 0)
   {
      // Il doit au moin rester une couche...
      return false;
   }

   return couches.Retirer(index);
}

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
double Canevas::aire()
{
   double aireTotale = 0;

   for(int index=0; index<couches.Grosseur(); index++)
   {
      aireTotale = aireTotale + couches.DonneAIndex(index)->AireCouche();
   }

   return aireTotale;
}

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
bool Canevas::translater(int deltaX, int deltaY)
{
   if(!couches.VerifierIndex(indexCoucheActive))
   {
      // Index actif spécifié n'est pas valide.
      return false;
   }

   return couches.DonneAIndex(indexCoucheActive)->TranslationCouche(deltaX, deltaY);;
}

/**
 * @brief
 * Imprime dans un terminal toutes les info
 * pertinantes du canevas, ses couches, et
 * les formes étant dedans.
 * @param s
 */
void Canevas::afficher(ostream & s)
{
   if(couches.Grosseur() == 0)
   {
      s << "Le canevas est vide" << std::endl;
      return;
   }

   for(int index=0; index<couches.Grosseur(); index++)
   {
      s << "----- Couche " << index << " -----" << std::endl;
      couches.DonneAIndex(index)->AfficherCouche(s);
   }
}

/**
 * @brief Retourne le nombre de couches qui
 * sont actuellement présentes dans le canevas
 * Par défaut, 0 couches se trouvent dans le
 * canevas.
 * @return int
 * Nombre de couches dans le canevas. Défault
 * à 0.
 */
int Canevas::NombreDeCouches()
{
   return couches.Grosseur();
}
