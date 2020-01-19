/*************************************************************************
CompteurAccesURLRelatif  -  description
-------------------
début                : 16/01/2020
copyright            : (C) 2020 par Charles Javerliat et Fabien Narboux
e-mail               : charles.javerliat@insa-lyon.fr et fabien.narboux@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <CompteurAccesURLRelatif> (fichier CompteurAccesURLRelatif.h) ----------------
#if ! defined ( COMPTEUR_ACCES_URL_RELATIF_H )
#define COMPTEUR_ACCES_URL_RELATIF_H

//--------------------------------------------------- Interfaces utilisées

#include <string>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <CompteurAccesURLRelatif>
//
//
//------------------------------------------------------------------------

class CompteurAccesURLRelatif
{
  //----------------------------------------------------------------- PUBLIC

public:

  //----------------------------------------------------- Méthodes publiques

  void incrementer();
  // Mode d'emploi :
  //
  // Contrat :
  //

  unsigned int getNbAcces() const;

  const std::string & getOrigine() const;

  const std::string & getCible() const;

  //-------------------------------------------- Constructeurs - destructeur
  //CompteurAccesURLRelatif ( const CompteurAccesURLRelatif & unCompteurAccesURLRelatif );
  // Mode d'emploi (constructeur de copie) :
  //
  // Contrat :
  //

  CompteurAccesURLRelatif (const std::string & origine, const std::string & cible);
  // Mode d'emploi :
  //
  // Contrat :
  //

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées

  //----------------------------------------------------- Attributs protégés

  std::string origine;

  std::string cible;

  unsigned int nbAcces;

};

//-------------------------------- Autres définitions dépendantes de <CompteurAccesURLRelatif>

#endif // COMPTEUR_ACCES_URL_RELATIF_H
