/*************************************************************************
                           LogData  -  description
                             -------------------
    début                : 16/01/2020
    copyright            : (C) 2020 par Charles Javerliat et Fabien Narboux
    e-mail               : charles.javerliat@insa-lyon.fr et fabien.narboux@insa-lyon.fr
*************************************************************************/


//---------- Réalisation de la classe <CompteurAccesURL> (fichier LogData.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "logdata.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur


LogData::LogData (set<CompteurAccesURL> fclassement, map<string,CompteurAccesURL> furlToCompteur, map<pair<string,string>,unsigned int> fcptRefererToCible)
    :classement(fclassement),urlToCompteur(furlToCompteur),cptRefererToCible(fcptRefererToCible)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <LogData>" << endl;
#endif
} //----- Fin de LogData

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
