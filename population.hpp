#ifndef POPULATION_HPP
#define POPULATION_HPP
using namespace std;
#include "animal.hpp"
#include<vector>

class Population {
    public :
      vector<Animal> PopA;
      
      Population();
      Animal get(int ide) const;
      Ensemble getIds() const;
      int reserve() const;
      void set(Animal A);
      void supprime(int b);
};

#endif
