#include <stdexcept>
#include <iostream>
#include <vector>
#include <array>

using namespace std;
#include "ensemble.hpp"
#include "test.cpp"

Ensemble::Ensemble(){
	array<int,MAXCARD> u;
	t = u;
	card = 0;
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

bool Ensemble::estVide(){
	return card == 0;
}

int Ensemble::cardinal(){
	return card;
}

void Ensemble::ajoute(int obj){
    if(card==MAXCARD){
        throw runtime_error("MAXCARD atteint");
    }
    t[card] = obj;
}

int Ensemble::tire(){
    if(card==0){
        throw runtime_error("ensemble vide");
    }
    int b = rand()%(MAXCARD+1);
    int a = t[b];
    delete t[b];
    return a;
}



