#ifndef SIMSTATE_H
#define SIMSTATE_H
#include <vector>
#include <cstdint>
#include "boost/random.hpp"
#include "boost/random/normal_distribution.hpp"
#include "nationstate.h"

class SimState
{
private:
    static uint32_t seed;
    static uint64_t simTime;
    static uint32_t simResolution;
    boost::random::normal_distribution<> nd();


public:
    double static get_rand_norm(double,double);
    std::vector<NationState*> Nations;
    SimState();
    virtual ~SimState(){}
    void Update();
    static uint64_t getTime(){return simTime;}
    uint16_t getNationQuantity();
    void addParticipant(NationState*);
    static uint32_t getseed(){return ++SimState::seed;}


};

#endif // SIMSTATE_H
