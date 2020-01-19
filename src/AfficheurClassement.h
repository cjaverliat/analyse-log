/*************************************************************************
AfficheurClassement  -  description
-------------------
début                : 19/01/2020
copyright            : (C) 2020 par Charles Javerliat et Fabien Narboux
e-mail               : charles.javerliat@insa-lyon.fr et fabien.narboux@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <AfficheurClassement> (fichier AfficheurClassement.h) ----------------
#if ! defined ( AFFICHEUR_CLASSEMENT_H )
#define AFFICHEUR_CLASSEMENT_H

//--------------------------------------------------- Interfaces utilisées

#include <iostream>
#include <vector>

#include "CompteurAccesURLAbsolu.h"

//------------------------------------------------------------------------
// Rôle de la classe <AfficheurClassement>
//
//
//------------------------------------------------------------------------

class AfficheurClassement
{

  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Méthodes publiques

  static void afficherClassement(std::vector<CompteurAccesURLAbsolu*> & l, const unsigned int n = 10, std::ostream & os = std::cout);

};

#endif // AFFICHEUR_CLASSEMENT_H
