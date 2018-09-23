#ifndef POPULATION_H
#define POPULATION_H
#include <vector>
#include "individual.h"

class Population
{
private:
    std::vector<Individual* > individuals;
public:
    void addIndividual(Individual * P1){individuals.push_back(P1);}
    Population();


};

#endif // POPULATION_H
