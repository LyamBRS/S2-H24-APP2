/********
 * @file: couche.cpp
 * @author: Francis Gratton, GRAF2102, COUS1912
 * @date: 9 janvier 2024
 * Modifie par : ...
 * @date : ...
 * @brief: Implementation des methodes des classes decrites dans
 *    couche.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "forme.h"
#include "Vecteur.h"
#include "couche.h"

/// @brief Constructeur par default de Couche
/// @brief La position de depart est de (0, 0) et l'etat initiale est Initialisee
Couche::Couche()
{
	
   _translationHorizontale = 0;
   _translationVerticale = 0;
   _etatCouche = EtatsCouche::Initialisee;
}

/// @brief Destructeur de Couche
Couche::~Couche()
{
_vecteur.~Vecteur();
	
}

/// @brief Ajout d'une forme dans la couche
/// @param x: La forme est ajouter.
/// @return Retourne vrai si l'ajout a ete fait avec succes
bool Couche::AjoutForme(Forme *f)
{
    if(_etatCouche != Active)
        return NULL;

    return _vecteur.Ajouter(f);
}

/// @brief Retire la forme dans la couche a l'index specifier
/// @param index: La forme est retire a l'index.
/// @return Retourne la forme a l'index
Forme* Couche::RetirerForme(int index)
{
    if(_etatCouche != Active)
        return NULL;

    Forme** val = _vecteur.DonnePointeurAIndex(index);
	
    if(_vecteur.Retirer(index))
    {
      return *val;
    }
    else
    {
      return NULL;
    }
}

bool Couche::RetirerForme()
{
    _vecteur.Retirer(_vecteur.GetIndexItemCourant());
    return true;
}


/// @brief Dit la forme dans la couche a l'index specifier
/// @param index: La forme a l'index designé.
/// @return Retourne la forme a l'index
Forme* Couche::FormeAIndex(int index)
{
    return *_vecteur.DonnePointeurAIndex(index);
}

/// @brief Retourne combien de formes sont presentes dans la couche.
/// @return int: nombre de formes dans le vecteur de la couche.
int Couche::NombreDeFormes()
{
    return _vecteur.Grosseur();
}


/// @brief Permet d'avoir la somme des aires de la couches
/// @return Retourne l'aire de la couche
double Couche::AireCouche()
{
    
    double sommationAire = 0;
    for(int i = 0; i < _vecteur.Grosseur(); i++)
    {
      Forme** val = _vecteur.DonnePointeurAIndex(i);

      sommationAire += (*val)->aire();
    }
    return sommationAire;
}

/// @brief Retourne l'état actuel de la couche.
/// @return EtatsCouche
EtatsCouche Couche::Etat()
{
    return _etatCouche;
}

/// @brief Retourne si l'index est valide
/// @param index
/// @return
bool Couche::VerifierIndex(int index)
{
    return _vecteur.VerifierIndex(index);
}

/// @brief Permet de deplacer la couche
/// @param horizontale: La couche va se deplacer sur l'axe X
/// @param verticale: La couche va se deplacer sur l'axe Y
/// @return Retourne si la translation a ete fait avec succes
bool Couche::TranslationCouche(int horizontale, int verticale)
{
    if(_etatCouche != EtatsCouche::Active)
        return false;

    for(int i = 0; i < _vecteur.Grosseur(); i++)
    {
        Forme** val = _vecteur.DonnePointeurAIndex(i);
        (*val)->translater(horizontale, verticale);
    }

    _translationHorizontale += horizontale;
    _translationVerticale += verticale;
    return true;
}

/// @brief Permet de reinitialiser la couche au point de depart
/// @return Retourne si la translation a ete fait avec succes
bool Couche::ReinitialisationTranslationCouche()
{
    if(_etatCouche != Active)
        return false;

    for(int i = 0; i < _vecteur.Grosseur(); i++)
    {
        Forme** val = _vecteur.DonnePointeurAIndex(i);
        (*val)->translater(-_translationHorizontale, -_translationVerticale);
    }

    _translationHorizontale = 0;
    _translationVerticale = 0;
    
    return true;
}

/// @brief Permet de reinitialiser la couche
/// @return Retourne si la reinitialiser a ete fait avec succes
bool Couche::ReinitialisationCouche()
{
    // if(_etatCouche != Active)
    // {
        // std::cout << "\n" << std::endl;
        // std::cout << "bool Couche::ReinitialisationCouche() -> FALSE" << std::endl;
        // std::cout << "\n" << std::endl;
        // return false;
    // }

    for(int i = 0; i < _vecteur.Grosseur(); i++)
    {
    	if(!_vecteur.Retirer(i))
    	{
            // Impossible de retirer la donnee a l'index fournis.
      	    return false;
    	}
    }
    _translationHorizontale = 0;
    _translationVerticale = 0;
    _etatCouche = EtatsCouche::Initialisee;
    return true;
    
}

/// @brief Permet de changer l'etat de la fonction
/// @return retourne si le changement a ete un succes
bool Couche::ChangerEtat(EtatsCouche etat)
{
    if(etat == Initialisee)
        return false;

    _etatCouche = etat;

    return true;
}

/// @brief Affiche tous les formes dans la couche
/// @return retourne si l'affiche est un succes
bool Couche::AfficherCouche(ostream & s)
{
    s << "Etat: ";

    if(_etatCouche == Initialisee)
    {
        s << "initialisee" << endl;
    }
    else if(_etatCouche == Active)
    {
        s << "active" << endl;
    }
    else
    {
        s << "inactive" << endl;
    }

    for(int i = 0; i < _vecteur.Grosseur(); i++)
   {
      Forme** val = _vecteur.DonnePointeurAIndex(i);
      (*val)->afficher(s);
   }
    return true;
}



bool Couche::ChoisirForme(int index)
{
    return _vecteur.SetItemCourant(index);
    

}

bool Couche::FormePrecedente()
{
    return --_vecteur;
}

bool Couche::FormeSuivante()
{
    return ++_vecteur;
}


bool Couche::FormeDerniere()
{
    return _vecteur.SetItemCourant(_vecteur.Grosseur() - 1);
}

Forme* Couche::ObtenirFormeCourrant()
{
    return (_vecteur.GetItemCourant());
}



//template <typename U>
/*
std::ostream& operator<<(std::ostream& os, const Couche& couche) {
    std::cout << "COUCHE PRINT" << std::endl;

    os << "L ";

    if (couche._etatCouche == EtatsCouche::Active) os << "a\n";
    if (couche._etatCouche == EtatsCouche::Inactive) os << "x\n";
    if (couche._etatCouche == EtatsCouche::Initialisee) os << "i\n";

    os << couche._vecteur;
    return os;
}
*/