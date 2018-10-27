#ifndef POPULATION_H
#define POPULATION_H
#include <vector>
#include <iostream>
#include "individual.h"
#include "boost/random.hpp"




class Population
{
private:
    uint32_t carrying_capacity = 500;
    double capacity_scalar;
    double population_growth_rate;
    std::vector<Individual* > individuals;


public:
    void addIndividual(Individual * P1){individuals.push_back(P1);}
    Population();
    void printInfo(){std::cout << "Individual Count: "<<individuals.size() << ", Birthrate: "<< capacity_scalar << std::endl;}
    void Update();

};

#endif // POPULATION_H
