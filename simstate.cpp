#include "simstate.h"
#include <cstdint>


SimState::  SimState()
{


}

uint16_t SimState::getNationQuantity(){
    return Nations.size();
}


void SimState::addParticipant(NationState* Nation){
    Nations.push_back(Nation);
}

void SimState::Update(){
    for(auto CurrentNation : Nations){
        CurrentNation->Update();
    }
}
