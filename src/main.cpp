#include <iostream>
#include <regex>
#include<sstream>
#include<fstream>
#include<iterator>
#include "Types.h"
#include "AfficheurClassement.h"
#include "GenerateurGraphe.h"
#include "LecteurLog.h"


using namespace std;

// Renvoie vrai si nomFic correspond bien à un nom de fichier fichier log ou txt
bool verifNomFicLog(string nomFic);
// Renvoie vrai si nomFic correspond bien à un nom de fichier dot
bool verifNomFicDot(string nomFic);
// Renvoie vrai si les options du -g sont correct, ie un fichier .dot puis un fichier .log ou .txt
bool verifOptionG (string nomFicDot, string nomFicLog);
// Renvoie vrai si snumber est composé exclusivement de chiffres
bool stringComposedOfDigit (string snumber);
// Renvoie vrai si sheure correspond bien à une heure au format 24h
bool verifHeure(string sheure);

int main(int argc, char ** argv)
{
    bool optionE = false; // option -e active si vrai
    short heure = -1; // filtre sur l'heure si différent de -1
    string fichierLog,fichierDot;
    string err("Erreur syntaxe : ./bin/analog [-e] [-t heure] [-g nomGraphe.dot] <fichierLogs.log|fichierLogs.txt>");
    try {
        switch(argc) // En fonction du nombre d'arguments
        {
        case 1: //Aucun argument au programme c'est une erreur
            throw err;
        case 2: //Seulement un fichier de log en argument
            if (!verifNomFicLog(argv[1]))
            {
                throw err;
            }
            fichierLog = argv[1];
            break;
        case 3: //l'option e et le fichier de log en argument
            if (strcmp(argv[1],"-e") != 0 || !verifNomFicLog(argv[2]))
            {
                throw err;
            }
            optionE = true;
            fichierLog = argv[2];
            break;
        case 4: // Soit un filtre sur l'heure, soit l'option de génération de graphe
            if (strcmp(argv[1],"-g") != 0 && strcmp(argv[1],"-t") != 0)
            {
                throw err;
            }
            else
            {
                if (strcmp(argv[1],"-g") == 0)
                {
                    if(!verifOptionG(argv[2],argv[3]))
                    {
                        throw err;
                    } else
                    {
                        fichierDot = argv[2];
                        fichierLog = argv[3];
                    }
                }
                else
                {
                    if(!verifHeure(argv[2]) || !verifNomFicLog(argv[3]))
                    {
                        throw err;
                    }
                    else
                    {
                        heure = atoi(argv[2]);
                        fichierLog = argv[3];
                    }
                }
            }
            break;
        case 5:
            if(strcmp(argv[1],"-e") == 0 && strcmp(argv[2],"-g") == 0 && verifOptionG(argv[3],argv[4])) // option -e + générateur de graphe
            {
               optionE = true;
               fichierDot = argv[3];
               fichierLog = argv[4];
            }
            else if(strcmp(argv[1],"-e") == 0 && strcmp(argv[2],"-t") == 0 && verifHeure(argv[3]) && verifNomFicLog(argv[4])) // option -e + filtre sur l'heure
            {
                optionE = true;
                heure = atoi(argv[3]);
                fichierLog = argv[4];
            }
            else if(strcmp(argv[1],"-t") == 0 && verifHeure(argv[2]) && strcmp(argv[3],"-e") == 0 && verifNomFicLog(argv[4])) // filtre sur l'heure + option -e
            {
                heure = atoi(argv[2]);
                optionE = true;
                fichierLog = argv[4];
            }
            else
            {
                throw err;
            }
            break;
        case 6: // Unique cas possible: filtre sur l'heure et option de génération de graphe
            if(!(strcmp(argv[1],"-t") == 0 && verifHeure(argv[2]) && strcmp(argv[3],"-g") == 0 && verifOptionG(argv[4],argv[5])))
            {
                throw err;
            }
            else
            {
                heure = atoi(argv[2]);
                fichierDot = argv[4];
                fichierLog = argv[5];
            }
            break;
        case 7: // Toutes les options sont activées (2 ordres possibles)
            if(strcmp(argv[1],"-t") == 0 && verifHeure(argv[2]) && strcmp(argv[3],"-e") == 0 && strcmp(argv[4],"-g") == 0 && verifOptionG(argv[5],argv[6]))
            {
                optionE = true;
                heure = atoi(argv[2]);
                fichierDot = argv[5];
                fichierLog = argv[6];
            }
            else if(strcmp(argv[1],"-e") == 0 && strcmp(argv[2],"-t") == 0 && verifHeure(argv[3]) && strcmp(argv[4],"-g") == 0 && verifOptionG(argv[5],argv[6]))
            {
                optionE = true;
                heure = atoi(argv[3]);
                fichierDot = argv[5];
                fichierLog = argv[6];
            }
            else
            {
                throw err;
            }
            break;
        default:
            throw err;
        }

        LogData ld;
        // Lecture du fichier de log avec les options de filtrage
        LecteurLog::lireLogs(fichierLog, ld, optionE, heure);

        //Si l'option de génération de graphe est activée, on génère le graphe
        if(!fichierDot.empty())
        {
            ofstream os(fichierDot);
            if (os.fail())
            {
                throw string("Problème avec le fichier " + fichierDot);
            }
            GenerateurGraphe::genererGraphe(ld.compteurRefererToCible, os);
            os.close();
            cout << "Dot-file " << fichierDot << " generated" << endl;
        }

        // Affichage du top
        AfficheurClassement::afficherClassement(ld.compteursAccesUrl);

    } catch (string & err) {
        cerr << err << endl;
    }
    return 0;
}

bool verifNomFicLog(string nomFic)
{
    regex nomFicLogRegex("^(\/?[A-Za-z0-9_\.]+)+.(txt|log)$");
    if (!regex_match(nomFic,nomFicLogRegex))
    {
        return false;
    }
    return true;
}

bool verifNomFicDot(string nomFic)
{
    regex nomFicLogRegex("^[A-Za-z0-9_]+\.dot$");
    if (!regex_match(nomFic,nomFicLogRegex))
    {
        return false;
    }
    return true;
}

bool verifOptionG (string nomFicDot, string nomFicLog)
{
    if (!verifNomFicLog(nomFicLog) || !verifNomFicDot(nomFicDot))
    {
        return false;
    }
    return true;
}

bool stringComposedOfDigit (string snumber)
{
    string::const_iterator it = snumber.begin();
    while(it != snumber.end() && isdigit(*it)) ++it;
    return it==snumber.end()&&!snumber.empty();
}

bool verifHeure(string sheure)
{
    if(!stringComposedOfDigit(sheure))
    {
       return false;
    }
    int heure = stoi(sheure);
    if(heure < 0 || heure > 23 )
    {
        return false;
    }
    return true;
}
