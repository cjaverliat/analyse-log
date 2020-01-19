/*************************************************************************
LecteurLog  -  description
-------------------
début                : 19/01/2020
copyright            : (C) 2020 par Charles Javerliat et Fabien Narboux
e-mail               : charles.javerliat@insa-lyon.fr et fabien.narboux@insa-lyon.fr
*************************************************************************/


//---------- Réalisation de la classe <LecteurLog> (fichier LecteurLog.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <fstream>
#include <sstream>
#include <limits>
#include <vector>
#include <iterator>
#include <set>

//------------------------------------------------------ Include personnel

#include "LecteurLog.h"

//----------------------------------------------------------------- PUBLIC

//Ensemble des extensions que l'on peut exclure avec -e
static const std::set<std::string> extensionsExclues = {"JPG", "JPEG", "jpg", "jpeg", "bmp", "PNG", "png", "gif", "ico", "css", "js"};

//Adresse locale du serveur
static const std::string ADRESSE_LOCALE = "http://intranet-if.insa-lyon.fr";

//----------------------------------------------------- Méthodes publiques

void nettoyerURL(std::string & url)
//Supprime tout le superflu des URL (", /, ?, ;)
{
  //On retire les " autour de l'URL si ils sont présents
  if(url.find('"') == 0) {
    url = url.substr(1, url.length() - 1);
  }

  if(url.find('"') == url.length() - 1) {
    url = url.substr(0, url.length() - 1);
  }

  //Si l'url commence par l'adresse locale, on la supprime
  if(url.find(ADRESSE_LOCALE) == 0) {
    url = url.substr(ADRESSE_LOCALE.length(), url.length() - 1);
  }

  //Supprime tous les paramètres passés dans l'URL
  url = url.substr(0, url.find("?"));
  url = url.substr(0, url.find(";"));

  //Supprime systématiquement le '/' de fin si présent
  if(url.rfind('/') == url.length() - 1) {
    url = url.substr(0, url.length() - 2);
  }
}

std::string recupererExtension(std::string & url)
//Extrait l'extension du fichier pointé par l'URL
{
  std::size_t extPos = url.rfind('.');

  if(extPos > url.find_last_of('/')) {
    return url.substr(extPos + 1, url.length());
  }

  return "";
}

static CompteurAccesURLAbsolu & getCptAccesURLAbsolu(const std::string & url, URLToCptAccesURLAbsolu & urlToCptAbs, std::vector<CompteurAccesURLAbsolu*> & listeCptAbs)
{
  URLToCptAccesURLAbsolu::iterator cptAbsCibleIt = urlToCptAbs.find(url);

  //Si le compteur absolu n'existe pas, on le rajoute
  if(cptAbsCibleIt == urlToCptAbs.end()) {
    cptAbsCibleIt = urlToCptAbs.insert({url, CompteurAccesURLAbsolu(url)}).first;
    //Rajoute le pointeur vers le compteur dans la liste des compteurs
    listeCptAbs.emplace_back(&cptAbsCibleIt->second);
  }

  return cptAbsCibleIt->second;
}

static CompteurAccesURLRelatif & getCptAccesURLRelatif(const std::string & origineURL, const std::string & cibleURL, URLsToCptAccesURLRelatif & urlsToCptRel)
{
  URLsToCptAccesURLRelatif::iterator cptRelIt = urlsToCptRel.find({origineURL, cibleURL});

  //Si le compteur absolu n'existe pas, on le rajoute
  if(cptRelIt == urlsToCptRel.end()) {
    cptRelIt = urlsToCptRel.insert({{origineURL, cibleURL}, CompteurAccesURLRelatif(origineURL, cibleURL)}).first;
  }

  return cptRelIt->second;
}

void LecteurLog::lireLogs(const std::string & nomFichier,
  URLToCptAccesURLAbsolu & urlToCptAbs,
  URLsToCptAccesURLRelatif & urlsToCptRel,
  std::vector<CompteurAccesURLAbsolu*> & listeCptAbs,
  const bool exclusionMedias,
  const short creneauHoraire)
  {

    std::ifstream is(nomFichier);
    std::string origine;
    std::string cible;

    std::string line;

    if(is.is_open())
    {
      while(getline(is, line))
      {
        std::istringstream iss(line);
        //On split le string à chaque espace
        std::vector<std::string> results(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());

        short heure = std::stoi(results[3].substr(13, 2));

        //Si on a pas de filtre sur le créneau horaire ou si le log passe le filtre
        if(creneauHoraire == -1 || heure == creneauHoraire)
        {
          std::string cibleURL = results[6];
          nettoyerURL(cibleURL);
          std::string extensionCible = recupererExtension(cibleURL);

          //Si on a pas de filtre sur le type de fichier ou si le type de fichier passe le filtre
          if(!exclusionMedias || extensionsExclues.find(extensionCible) == extensionsExclues.end())
          {
            std::string origineURL = results[10];
            nettoyerURL(origineURL);

            CompteurAccesURLAbsolu & cptAbs = getCptAccesURLAbsolu(cibleURL, urlToCptAbs, listeCptAbs);
            CompteurAccesURLRelatif & cptRel = getCptAccesURLRelatif(origineURL, cibleURL, urlsToCptRel);
            cptAbs.incrementer();
            cptRel.incrementer();
          }

        }
      }

      is.close();
    }

  }
