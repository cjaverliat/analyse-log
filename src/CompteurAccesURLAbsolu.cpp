/*************************************************************************
CompteurAccesURLAbsolu  -  description
-------------------
début                : 16/01/2020
copyright            : (C) 2020 par Charles Javerliat et Fabien Narboux
e-mail               : charles.javerliat@insa-lyon.fr et fabien.narboux@insa-lyon.fr
*************************************************************************/


//---------- Réalisation de la classe <CompteurAccesURLAbsolu> (fichier CompteurAccesURLAbsolu.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "CompteurAccesURLAbsolu.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void CompteurAccesURLAbsolu::incrementer()
{
  ++nbAcces;
} //----- Fin de incrementer


std::ostream & operator<<(std::ostream & os, const CompteurAccesURLAbsolu & c )
// Algorithme :
//
{
  os << c.url << " (" << c.nbAcces << " hits)";
  return os;
} //----- Fin de operator <<


bool CompteurAccesURLAbsolu::comparer(const CompteurAccesURLAbsolu* c1, const CompteurAccesURLAbsolu* c2)
{
  //Compare le nombre d'accès à l'URL de c1 et de c2
  //Cf. Types.h

  if(c1->nbAcces == c2->nbAcces) {
    //Tri par ordre alphabétique si égalité
    return c1->url < c2->url;
  } else {
    //Tri par nombre d'accès décroissant
    return c1->nbAcces > c2->nbAcces;
  }
}

//-------------------------------------------- Constructeurs - destructeur

CompteurAccesURLAbsolu::CompteurAccesURLAbsolu (const std::string & URL) : url(URL), nbAcces(0)
// Algorithme :
//
{
  #ifdef MAP
  cout << "Appel au constructeur de <CompteurAccesURL>" << endl;
  #endif
} //----- Fin de CompteurAccesURL

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
