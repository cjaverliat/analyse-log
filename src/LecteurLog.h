/*************************************************************************
LecteurLog  -  description
-------------------
début                : 19/01/2020
copyright            : (C) 2020 par Charles Javerliat et Fabien Narboux
e-mail               : charles.javerliat@insa-lyon.fr et fabien.narboux@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <LecteurLog> (fichier LecteurLog.h) ----------------
#if ! defined ( LECTEUR_LOG_H )
#define LECTEUR_LOG_H

//--------------------------------------------------- Interfaces utilisées

#include <fstream>

#include "Types.h"

//------------------------------------------------------------------------
// Rôle de la classe <LecteurLog>
//
//
//------------------------------------------------------------------------

class LecteurLog
{

  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Méthodes publiques

  static void lireLogs(const std::string & nomFichier,
    URLToCptAccesURLAbsolu & urlToCptAbs,
    URLsToCptAccesURLRelatif & urlsToCptRel,
    std::vector<CompteurAccesURLAbsolu*> & listeCptAbs,
    const bool exclusionMedias,
    const short heure);

};

#endif // LECTEUR_LOG_H
