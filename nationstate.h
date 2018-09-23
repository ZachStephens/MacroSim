#ifndef NATIONSTATE_H
#define NATIONSTATE_H

#include <vector>
#include <population.h>
#include "boost/type.hpp"
#include <cstdint>

class NationState
{
public:

    NationState();
    NationState(const char*);
    virtual ~NationState(){}
    uint64_t getGDP(void){return GDP;}
    void addPopulation(Population * P1){citizens.push_back(P1);}
    void printName();
    void Update();
private:
    std::vector<Population *> citizens;
    int64_t GDP; //gross domestic product $$
    int64_t taxRevenue; //tax revenue in $$
    int64_t netExports; //Total $$ of goods exports - total $$ of goods imported
    int64_t finalGoodsConsumed; //$$ if final goods purchased by consumers
    int64_t investment; //$$ used to produce consumer goods
    void calculateGDP(){GDP= taxRevenue + netExports + finalGoodsConsumed + investment;}
    const char * Name;

};

#endif // NATIONSTATE_H
