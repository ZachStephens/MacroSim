
#include <boost/thread.hpp>
#include <boost/chrono.hpp>
#include <iostream>
#include "simstate.h"

int main()
{

  std::uint64_t step_count = 0;



  NationState N1 = NationState("Canada");
  Population CP1 = Population();
  NationState N2 = NationState("Mexico");
  Population MP1 = Population();

  SimState SimBase = SimState();

  SimBase.addParticipant(&N1);
  SimBase.Nations[0]->addPopulation(&CP1);
  SimBase.addParticipant(&N2);
  SimBase.Nations[1]->addPopulation(&MP1);

  while(1){
    SimBase.Update();
  }

  N1.printName();
}

