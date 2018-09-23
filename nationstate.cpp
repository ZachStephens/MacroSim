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
    std::cout << "Population : "<< citizens.size() <<std::endl;
}

void NationState::printName(void){
    std::cout << Name << std::endl;
}


