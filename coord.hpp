#ifndef COORD_HPP
#define COORD_HPP
using namespace std;
#include<array>

const int TAILLEGRILLE = 20;
const int MAXCARD = 400;

class Ensemble{
    public:
    //* Constructeur par défaut
    //* @param[out] e : le ensemble vide
    Ensemble ();
    int getCard() const;
    array<int, MAXCARD> get_T();
    bool estVide() const;
	int cardinal() const;
	void ajoute(int obj);

    private:
    array<int, MAXCARD> t;
    int card;
};

class Coord {
    public : 
        Coord();
        Coord(int lig, int col);
        Coord(int n);
        int getY() const;
        int getX() const;
        int toInt() const;
        Ensemble voisines() const;
        
    private :
        int x,y ;
    
};

#endif
