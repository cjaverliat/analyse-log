/*************************************************************************
                           LogData  -  description
                             -------------------
    début                : 16/01/2020
    copyright            : (C) 2020 par Charles Javerliat et Fabien Narboux
    e-mail               : charles.javerliat@insa-lyon.fr et fabien.narboux@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <LogData> (fichier LogData.h) ----------------
#if ! defined ( LOG_DATA_H )
#define LOG_DATA_H

//--------------------------------------------------- Interfaces utilisées
#include<iostream>
#include<set>
#include<map>
#include "compteuraccesurl.h"

using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <LogData>
//
//
//------------------------------------------------------------------------

class LogData
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
   // LogData & operator = ( const LogData & unLogData );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    LogData ( const LogData & unLogData );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    LogData (set<CompteurAccesURL> fclassement, map<string,CompteurAccesURL> furlToCompteur, map<pair<string,string>,unsigned int> fcptRefererToCible);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //virtual ~LogData ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    set<CompteurAccesURL> classement;
    map<string,CompteurAccesURL> urlToCompteur;
    map<pair<string,string>,unsigned int> cptRefererToCible;

};

//-------------------------------- Autres définitions dépendantes de <LogData>

#endif // LOG_DATA_H

