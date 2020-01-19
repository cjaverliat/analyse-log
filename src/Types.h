#ifndef STRUCT_TYPES_H
#define STRUCT_TYPES_H

#include <string>
#include <map>

#include "CompteurAccesURLAbsolu.h"
#include "CompteurAccesURLRelatif.h"

//Type définissant la relation entre une URL et le compteur d'accès de cette URL
//Permet la recherche rapide d'un compteur d'accès pour une URL depuis son URL
typedef std::map<std::string, CompteurAccesURLAbsolu> URLToCptAccesURLAbsolu;

//Type définissant la relation entre la paire d'URL (origine et cible) et le nombre
//de fois où on est parti de cette origine pour accéder à la cible
typedef std::map<std::pair<std::string, std::string>, CompteurAccesURLRelatif> URLsToCptAccesURLRelatif;

#endif
