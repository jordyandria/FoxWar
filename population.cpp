using namespace std;
#include "population.hpp"
#include "animal.hpp"
#include "coord.hpp"
#include<vector>

Population::Population(){
    vector<Animal> u;
    u = vector<Animal>(0);
    PopA = u;
}

Animal Population::get(int ide) const{
    for(int i =0; i<PopA.size(); i++){
        if(ide==PopA[i].getId()){
            return PopA[i];
        }
    }
}

Ensemble Population::getIds() const{
    Ensemble e = Ensemble();
    for(int i =0; i<PopA.size(); i++){
        e.ajoute(PopA[i].getId());
    }
    return e;
}

int Population::reserve() const{
    int m = 0;
    for(int i =0; i<PopA.size(); i++){
        if(m<PopA[i].getId()){
            m = PopA[i].getId();
        }
    }
    return m + 1; //si m est l'id le plus grand, alors il n'y a pas d'autre id au dela de m
    //la place mémoire réservé a l'animal se fera dans Population::set
}

void Population::set(Animal A){
    if(PopA.size()<MAXCARD){
        PopA.push_back(A);
    }
}

void Population::supprime(int b){
    for(int i =0; i<PopA.size(); i++){
        if(b==PopA[i].getId()){
            PopA.erase(PopA.begin() + i);
            return;
        }
    }
    return;
}
