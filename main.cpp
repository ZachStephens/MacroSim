
#include <boost/thread.hpp>
#include <boost/chrono.hpp>
#include <iostream>
#include "simstate.h"

int main()
{

  std::uint64_t step_count = 0;



  NationState N1 = NationState("Canada");

  SimState SimBase = SimState();
  SimBase.addParticipant(&N1);


  while(1){
    step_count++;
    SimBase.Update();
  }

  N1.printName();
}

