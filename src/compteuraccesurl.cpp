/*************************************************************************
                           LogData  -  description
                             -------------------
    début                : 16/01/2020
    copyright            : (C) 2020 par Charles Javerliat et Fabien Narboux
    e-mail               : charles.javerliat@insa-lyon.fr et fabien.narboux@insa-lyon.fr
*************************************************************************/


//---------- Réalisation de la classe <CompteurAccesURL> (fichier CompteurAccesURL.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "compteuraccesurl.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CompteurAccesURL::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void CompteurAccesURL::incremente()
// Algorithme :
//
{
    ++hits;
} //----- Fin de incremente


//------------------------------------------------- Surcharge d'opérateurs

bool operator == ( const CompteurAccesURL & cu1, const CompteurAccesURL & cu2 )
// Algorithme :
//
{
    if(cu1.url == cu2.url && cu1.hits == cu2.hits)
    {
        return true;
    }
    return false;
} //----- Fin de operator ==

bool operator < ( const CompteurAccesURL & cu1, const CompteurAccesURL & cu2 )
// Algorithme :
//
{
    if(cu1.hits!=cu2.hits)
    {
        return cu1.hits < cu2.hits;
    } else
    {
        return cu1.url < cu2.url;
    }
} //----- Fin de operator <

bool operator > ( const CompteurAccesURL & cu1, const CompteurAccesURL & cu2 )
// Algorithme :
//
{
    return cu2 < cu1;
} //----- Fin de operator >

ostream & operator << (ostream & os, const CompteurAccesURL & cu )
// Algorithme :
//
{
    os << "/" << cu.url << " (" << cu.hits << " hits)"<< endl;
    return os;
} //----- Fin de operator <<


//-------------------------------------------- Constructeurs - destructeur

CompteurAccesURL::CompteurAccesURL (string URL)
    :url(URL),hits(0)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CompteurAccesURL>" << endl;
#endif
} //----- Fin de CompteurAccesURL

CompteurAccesURL::~CompteurAccesURL ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <CompteurAccesURL>" << endl;
#endif
} //----- Fin de ~CompteurAccesURL


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
