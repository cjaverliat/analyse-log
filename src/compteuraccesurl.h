/*************************************************************************
                           CompteurAccesURL  -  description
                             -------------------
    début                : 16/01/2020
    copyright            : (C) 2020 par Charles Javerliat et Fabien Narboux
    e-mail               : charles.javerliat@insa-lyon.fr et fabien.narboux@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <CompteurAccesURL> (fichier CompteurAccesURL.h) ----------------
#if ! defined ( COMPTEUR_ACCES_URL )
#define COMPTEUR_ACCES_URL

//--------------------------------------------------- Interfaces utilisées
#include<iostream>
#include<fstream>

using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <CompteurAccesURL>
//
//
//------------------------------------------------------------------------

class CompteurAccesURL
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void incremente();
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    friend bool operator == ( const CompteurAccesURL & cu1, const CompteurAccesURL & cu2 );
    // Mode d'emploi :
    //
    // Contrat :
    //

    friend bool operator < ( const CompteurAccesURL & cu1, const CompteurAccesURL & cu2 );
    // Mode d'emploi :
    //
    // Contrat :
    //

    friend bool operator > ( const CompteurAccesURL & cu1, const CompteurAccesURL & cu2 );
    // Mode d'emploi :
    //
    // Contrat :
    //

    friend ostream & operator << ( ostream & os, const CompteurAccesURL & cu );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    //CompteurAccesURL ( const CompteurAccesURL & unCompteurAccesURL );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CompteurAccesURL (string URL);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CompteurAccesURL ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    string url;
    unsigned int hits;

};

//-------------------------------- Autres définitions dépendantes de <CompteurAccesURL>

#endif // COMPTEUR_ACCES_URL

