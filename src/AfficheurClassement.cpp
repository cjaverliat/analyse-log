/*************************************************************************
AfficheurClassement  -  description
-------------------
début                : 19/01/2020
copyright            : (C) 2020 par Charles Javerliat et Fabien Narboux
e-mail               : charles.javerliat@insa-lyon.fr et fabien.narboux@insa-lyon.fr
*************************************************************************/


//---------- Réalisation de la classe <AfficheurClassement> (fichier AfficheurClassement.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel


#include <algorithm>

#include "AfficheurClassement.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void AfficheurClassement::afficherClassement(std::vector<CompteurAccesURLAbsolu*> & l, const unsigned int n, std::ostream & os)
{
  //Trie les URL par nombre d'accès à l'URL (deuxième valeur de la pair de cptAccesURLAbsoluT)
  std::sort(l.begin(), l.end(), CompteurAccesURLAbsolu::comparer);

  std::vector<CompteurAccesURLAbsolu*>::const_iterator it;

  //Affiche les n premiers éléments du classement
  for(it = l.begin(); it != l.begin() + n && it != l.end(); ++it)
  {
    const CompteurAccesURLAbsolu* cpt = *it;
    os << (*cpt) << std::endl;
  }
}
