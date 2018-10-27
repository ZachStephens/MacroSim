#include "simstate.h"
#include <cstdint>
#include <boost/random.hpp>

uint32_t SimState::seed = time(0);
uint64_t SimState::simTime = 0;
uint32_t SimState::simResolution = 1000;

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
    static uint32_t frame_count = 0;

    if(++frame_count == SimState::simResolution){

        frame_count = 0;

        simTime++;
        std::cout << '\r';

        for(auto CurrentNation : Nations){
            CurrentNation->Update();
        }

    }
}

double SimState::get_rand_norm(double mean,double sigma){
     boost::mt19937 rn(getseed());
     boost::random::normal_distribution<> ud(mean,sigma);
     boost::variate_generator<boost::mt19937&,boost::random::normal_distribution<>> var_norm(rn,ud);
     return var_norm();
 }
