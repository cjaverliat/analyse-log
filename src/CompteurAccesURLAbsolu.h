/*************************************************************************
CompteurAccesURLAbsolu  -  description
-------------------
début                : 16/01/2020
copyright            : (C) 2020 par Charles Javerliat et Fabien Narboux
e-mail               : charles.javerliat@insa-lyon.fr et fabien.narboux@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <CompteurAccesURLAbsolu> (fichier CompteurAccesURLAbsolu.h) ----------------
#if ! defined ( COMPTEUR_ACCES_URL_ABSOLU_H )
#define COMPTEUR_ACCES_URL_ABSOLU_H

//--------------------------------------------------- Interfaces utilisées

#include <iostream>
#include <string>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <CompteurAccesURLAbsolu>
//
//
//------------------------------------------------------------------------

class CompteurAccesURLAbsolu
{
  //----------------------------------------------------------------- PUBLIC

public:

  //----------------------------------------------------- Méthodes publiques

  void incrementer();
  // Mode d'emploi :
  //
  // Contrat :
  //

  //------------------------------------------------- Surcharge d'opérateurs

  friend std::ostream & operator<<( std::ostream & os, const CompteurAccesURLAbsolu & cpt );
  // Mode d'emploi :
  //
  // Contrat :
  //

  static bool comparer(const CompteurAccesURLAbsolu* c1, const CompteurAccesURLAbsolu* c2);

  //-------------------------------------------- Constructeurs - destructeur
  //CompteurAccesURLAbsolu ( const CompteurAccesURLAbsolu & unCompteurAccesURLAbsolu );
  // Mode d'emploi (constructeur de copie) :
  //
  // Contrat :
  //

  CompteurAccesURLAbsolu (const std::string & URL);
  // Mode d'emploi :
  //
  // Contrat :
  //

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées

  //----------------------------------------------------- Attributs protégés

  std::string url;

  unsigned int nbAcces;

};

//-------------------------------- Autres définitions dépendantes de <CompteurAccesURLAbsolu>

#endif // COMPTEUR_ACCES_URL_ABSOLU_H
