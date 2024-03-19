using namespace std;
#include "jeu.hpp"
#include<ostream>
#include<iostream>

Jeu::Jeu(){
    srand(time(NULL));
    Grille g = Grille();
    Population P = Population();
    for(int i =0; i<MAXCARD; i++){
        int n = rand()%(100);
        if(n<7){
            g.setCase(Coord(i),P.reserve()); //id dans la grille
            Animal r = Animal(Espece::renard,P.reserve(),Coord(i));
            P.set(r); //animal stocké dans la population
        }
        if(n>=7 and n<=27){
            g.setCase(Coord(i),P.reserve());
            Animal l = Animal(Espece::lapin,P.reserve(),Coord(i));
            P.set(l);
        }
    }
    carte = g;
    Pj = P;
}

Population Jeu::getP() const{
    return Pj;
}

Grille Jeu::getG() const{
    return carte;
}

void Jeu::ajouteAnimal(Espece e, Coord c){
    if(not(carte.caseVide(c))){
        throw runtime_error("il y a deja un animal dans cette case");
    }
    Animal b = Animal(e,Pj.reserve(),c);// l'identifiant de a n'a pas d'importance car il est attribué par Population::reserve
    carte.setCase(c,Pj.reserve());//id dans la grille
    Pj.set(b); //animal 
}

bool Jeu::verifieGrille() const{
    for(int i =0; i<MAXCARD; i++){
        if(not(carte.caseVide(Coord(i)))){
            if(i != Pj.get(carte.getCase(Coord(i))).getCoord().toInt()){
                return false;
            }
        }
    }
    return true;
}

void Jeu::deplace(Animal d){
    Ensemble s = carte.voisinsVides(d.getCoord());
    int n = s.tire();
    carte.setCase(Coord(n),d.getId());
    Animal A = d;
    A.setCoord(Coord(n));
    Pj.supprime(d.getId());
    Pj.set(A);
    carte.videCase(d.getCoord());
}

void Jeu::afficheCarte() const{
    for(int i =0; i<MAXCARD; i++){
        if(not(carte.caseVide(Coord(i)))){
            cout << Pj.get(carte.getCase(Coord(i))).toString() <<" ";
        }else{
            cout << "0" <<" ";
        }
        if(i%TAILLEGRILLE==0){
                cout << endl;
                cout << endl;
        }
    }
}
