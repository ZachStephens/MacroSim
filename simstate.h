#ifndef SIMSTATE_H
#define SIMSTATE_H
#include <vector>
#include <cstdint>
#include "nationstate.h"

class SimState
{
private:
    std::vector<NationState*> Nations;
    uint64_t simTime = 0;
public:
    SimState();
    virtual ~SimState(){}
    void Update();
    uint64_t getTime(){return simTime;}
    uint16_t getNationQuantity();
    void addParticipant(NationState*);

};

#endif // SIMSTATE_H
