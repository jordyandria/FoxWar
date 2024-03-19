#ifndef GRILLE_HPP
#define GRILLE_HPP
#include "coord.hpp"

using namespace std;

class Grille {
  public :
    Ensemble grid;
    
    Grille();
    bool caseVide(Coord c) const;
    int getCase(Coord ca) const;
    void videCase(Coord cas) ;
    void setCase(Coord caz, int i);
    Ensemble voisinsVides(Coord cible) const;
};

#endif
