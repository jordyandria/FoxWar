using namespace std;
#include "coord.hpp"
#include "animal.hpp"

Animal::Animal(Espece esp, int ide, Coord co){
    if(ide==-1){
        throw runtime_error("id incorrecte");
    }
    espece = esp;
    id = ide;
    coord = co;
    faim = 5;
}

int Animal::getId() const{
    return id;
}

Espece Animal::getEspece() const{
    return espece;
}

Coord Animal::getCoord() const{
    return coord;
}

void Animal::setCoord(Coord c){
    coord = c;
}

string Animal::toString() const{
    if(espece==Espece::lapin){
        return "L";
    }
    return "R";
}

int Animal::getFaim() const{
    return faim;
}

bool Animal::SeReproduit() const{
    int k = 0;
    for(int i =0; i<coord.voisines().cardinal(); i++){
        if(coord.voisines().t[i]==-1){
            k=k+1;
        }
    }
    return k>=4;
    
}
