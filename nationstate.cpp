#include "nationstate.h"
#include "population.h"
#include <iostream>


NationState::NationState()
{

}


NationState::NationState(const char * name)
{
    Name = name;
}



void NationState::Update(){
    printName();
    for(auto cur_population : citizens){
        cur_population->Update();
    }
}

void NationState::printName(void){
    std::cout << " " <<Name;
}


