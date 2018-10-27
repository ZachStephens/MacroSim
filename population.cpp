#include "population.h"
#include "simstate.h"
#include "math.h"


const uint32_t steps_per_year = 24;
const uint32_t  years_per_generation = 15;

/*Population growth scale per generation*/
const double POP_GROWTH_RATE = 1.2;

double GrowthExpectationPerIndividual(double growthrate,int population,int steps_per_generation);

Population::Population()
{
    population_growth_rate = SimState::get_rand_norm(POP_GROWTH_RATE,.2);
    std::cout<< population_growth_rate << std::endl;
    addIndividual(new Individual());


}


void Population::Update(){

    uint32_t growth = 0;
    uint32_t steps_per_generation = steps_per_year*years_per_generation;
    capacity_scalar = (carrying_capacity - individuals.size());
    capacity_scalar /= (double)carrying_capacity;

    boost::mt19937 rn(SimState::getseed());
    boost::random::uniform_real_distribution<> ud(0,1.0);
    boost::variate_generator<boost::mt19937&,boost::random::uniform_real_distribution<>> var_uni(rn,ud);


    double tmp = GrowthExpectationPerIndividual(1+capacity_scalar *(population_growth_rate-1),
                                               individuals.size(),
                                               steps_per_generation);

    for(auto I: individuals){

        I->Update();

        if(var_uni() < tmp ){

            growth++;
        }
        //std::cout << "Rand: " << tmp*growthrate << std::endl;

    }
    std::cout << " Capacity: " << individuals.size();
    if(growth > 0){
        for(uint32_t i = 0; i < growth; i++){
            if(individuals.size() < carrying_capacity){
                addIndividual(new Individual());
            }
        }

    }

}


/*produce the */
double GrowthExpectationPerIndividual(double growthrate,int population,int steps_per_generation){
    /*math.h log is natural (base e) logarithm */
    double growthrate_per_step = log(growthrate) / steps_per_generation;
    //std::cout << growthrate << std::endl;
    /**/

    return growthrate_per_step / population;
}

