#ifndef ANIMAL_HPP
#define ANIMAL_HPP
using namespace std;
#include "coord.hpp"

enum class Espece {lapin,renard};

class Animal{

  public :
    Animal();
    Animal(Espece esp, int ide, Coord co);
	int getId() const;
	Espece getEspece() const;
	Coord getCoord() const;
	void setCoord(Coord c);
	string toString() const;
    int getFaim() const;
    bool SeReproduit() const;

  private :
	Espece espece;
	int id;
	Coord coord;
	int faim;
};

#endif
