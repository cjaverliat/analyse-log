#include <iostream>

#include "Types.h"

#include "AfficheurClassement.h"
#include "GenerateurGraphe.h"
#include "LecteurLog.h"

int main()
{
  URLToCptAccesURLAbsolu urlToCptAbs;
  URLsToCptAccesURLRelatif urlsToCptRel;
  std::vector<CompteurAccesURLAbsolu*> listeCpt;

  LecteurLog::lireLogs("exemple.log", urlToCptAbs, urlsToCptRel, listeCpt, true, -1);

  AfficheurClassement::afficherClassement(listeCpt);
  GenerateurGraphe::genererGraphe(urlsToCptRel);

  return 0;
}
