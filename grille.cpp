using namespace std;
#include "grille.hpp"

Grille::Grille(){
    grid = Ensemble();
}

bool Grille::caseVide(Coord c) const{
    return grid.t[c.toInt()] == -1;
}

int Grille::getCase(Coord ca) const{
    return grid.t[ca.toInt()];
}

void Grille::videCase(Coord cas) {
    grid.t[cas.toInt()] = -1;
}

void Grille::setCase(Coord caz, int i){
    grid.t[caz.toInt()] = i;
}

Ensemble Grille::voisinsVides(Coord cible) const{
    Ensemble b = Ensemble();
    Ensemble t = cible.voisines();
    for(int i =0; i<t.cardinal(); i++){
        if(grid.t[t.t[i]]==-1){
                b.ajoute(t.t[i]);
        }
    }
    return b;
}
