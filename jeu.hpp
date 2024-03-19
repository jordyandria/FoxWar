#ifndef JEU_HPP
#define JEU_HPP
using namespace std;
#include "grille.hpp"
#include "population.hpp"

class Jeu {
  private :
    Population Pj;
    Grille carte;
    
  public :
    Jeu();
    Population getP() const;
    Grille getG() const;
    void ajouteAnimal(Espece a, Coord c);
    bool verifieGrille() const;
    void deplace(Animal d); 
    void afficheCarte() const;
};

#endif
