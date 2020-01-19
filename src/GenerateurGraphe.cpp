/*************************************************************************
GenerateurGraphe  -  description
-------------------
début                : 19/01/2020
copyright            : (C) 2020 par Charles Javerliat et Fabien Narboux
e-mail               : charles.javerliat@insa-lyon.fr et fabien.narboux@insa-lyon.fr
*************************************************************************/


//---------- Réalisation de la classe <GenerateurGraphe> (fichier GenerateurGraphe.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel

#include <set>
#include <sstream>

#include "GenerateurGraphe.h"

typedef std::map<std::string, unsigned int> URLToNoeudID;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

static URLToNoeudID::iterator getNoeud(const std::string & noeudURL, URLToNoeudID & noeuds, std::stringstream & ssNoeuds)
{
  URLToNoeudID::iterator noeudIt = noeuds.find(noeudURL);

  //Si le noeud n'existe pas on le crée
  if(noeudIt == noeuds.end()) {
    unsigned int id = noeuds.size();
    ssNoeuds << "\tnode" << id << " [label=\"" << noeudURL << "\"];\n";
    noeudIt = noeuds.insert(noeuds.end(), {noeudURL, id});
  }

  return noeudIt;
}

void GenerateurGraphe::genererGraphe(const URLsToCptAccesURLRelatif & cpt, std::ostream & os)
{
  //Association d'un noeud avec un numéro
  URLToNoeudID noeuds;
  std::stringstream ssNoeuds;
  std::stringstream ssFleches;

  URLsToCptAccesURLRelatif::const_iterator it;

  for(it = cpt.begin(); it != cpt.end(); ++it)
  {
    //Le compteur d'accès relatif depuis une URL d'origine vers une URL cible
    const CompteurAccesURLRelatif cptRel = it->second;

    URLToNoeudID::iterator origine = getNoeud(cptRel.getOrigine(), noeuds, ssNoeuds);
    URLToNoeudID::iterator cible = getNoeud(cptRel.getCible(), noeuds, ssNoeuds);

    unsigned int & origineID = origine->second;
    unsigned int & cibleID = cible->second;

    //Crée le lien entre les deux noeuds
    ssFleches << "\tnode" << origineID << " -> " << "node" << cibleID << " [label=\"" << cptRel.getNbAcces() << "\"];" << std::endl;
  }

  //Remplis le flux
  os << "digraph {" << std::endl;
  os << ssNoeuds.rdbuf();
  os << ssFleches.rdbuf();
  os << "}" << std::endl;
}
