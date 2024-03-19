#include <stdexcept>
#include <iostream>
#include <vector>

using namespace std;
#include "doctest.h"
#include "coord.hpp"


Coord::Coord(int lig, int col) : x{lig}, y{col} {
    if(0>lig or 0>col or lig>TAILLEGRILLE or col>TAILLEGRILLE){
        throw runtime_error("coordonnées inapproprié");
    }
    y = col;
    x = lig;    
    
}

int Coord::getY() const{
    return y;
}

int Coord::getX() const{
    return x;
}

ostream &operator<<(ostream &out, Coord c){
    out<<"("<<c.getX()<<","<<c.getY()<<")"<<endl;
    return out;
}

bool operator==(Coord a, Coord b){
    return (a.getX() == b.getX()) and (a.getY() == b.getY());
}

int Coord::toInt() const{
    return x * TAILLEGRILLE + y;
}

Coord::Coord(int n){
    x = n / TAILLEGRILLE;
    y = n % TAILLEGRILLE;
}

int Ensemble::getCard() const{
    return card;
}

array<int, MAXCARD> Ensemble::get_T() {
    return t;
}

std::ostream &operator<<(std::ostream &out, Ensemble e) {
    if(e.getCard() !=0){
        out << "{" << e.get_T.at(0);
	for(int i=1; i<e.getCard; i++){
		out <<","<< e.get_T.at(i);
	}
	out << "}";
	return out;
    }
    out <<"{}";
    return out;
}

Ensemble::Ensemble(){
	array<int,MAXCARD> u;
    for(int i =0; i<MAXCARD; i++){
        u[i] = -1;
    }
	t = u;
	card = 0;
}

bool Ensemble::estVide() const{
	return card == 0;
}

int Ensemble::cardinal() const{
	return card;
}

void Ensemble::ajoute(int obj){
    if(card==MAXCARD or obj == -1){
	throw runtime_error("MAXCARD atteint, ou ajout de l'entier -1, définit comme l'élément null pour Ensemble");
    }
    for(int i =0; i<MAXCARD; i++){
        if(t[i]==-1){
            t[i] = obj;
            card = card+1;
            return;
        }
    }
}

int Ensemble::tire(){
    srand(time(NULL));
    if(card==0){
	throw runtime_error("ensemble vide");
    }
    int b = rand()%(MAXCARD+1);
    int a = t[b];
    while(a == -1){
        b = rand()%(MAXCARD+1);
        a = t[b];
    }
    t[b] = -1; //Signifie par la suite que cette case est vide
    card = card-1;
    return a;
}


int max(int a, int b){
	if(a>b){
		return a;
	}
	return b;
}

int min(int a, int b){
	if(a<b){
		return a;
	}
	return b;
}

Ensemble Coord::voisines() const{
	Ensemble a = Ensemble();
	int imin = max(x-1,0);
	int imax = min(x+1,TAILLEGRILLE-1);
	int jmin = max(y-1,0);
	int jmax = min(y+1,TAILLEGRILLE-1);
	for(int i=imin; i<imax ;i++){
		for(int j=jmin; j<jmax ;j++){
			if(not(Coord{i,j}==Coord{x,y})){
				a.ajoute(Coord{i,j}.toInt());
			}
		}
	}
    return a;
}



TEST_CASE("Test classe Coord"){
        Coord a {4, 6};
        Coord b {4, 6};
        Coord c {5, 0};
        Coord d {86};
        Coord e {100};
        //constructeur et getters
        CHECK(a.getX() == 4);
        CHECK(a.getY() == 6);
        CHECK(a.getX() == b.getX());
        CHECK_FALSE(b.getX() == c.getY());
        //exception
        CHECK_THROWS(Coord {155, 10}, runtime_error("Coordonnees incorrectes"));
        //surcharges operateurs
        CHECK(a == b);
        CHECK(c == Coord {5, 0});
        CHECK_FALSE(a == c);
        //int to coordonnees et toInt
        CHECK(d == a);
        CHECK(e.getX() == 5);
        CHECK(e.getY() == 0);
        CHECK(a.toInt() == 86);
        CHECK(c.toInt() == 5*TAILLEGRILLE + 0);
    }
