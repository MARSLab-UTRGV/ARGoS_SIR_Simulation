#include "SIR_loop_functions.h"

SIR_loop_functions::SIR_loop_functions():
    num_robots(0), num_susceptible(0), num_infected(0), num_recovered(0){}

void SIR_loop_functions::Init(TConfigurationNode& t_tree){

    CSpace::TMapPerType& footbots = GetSpace().GetEntitiesByType("foot-bot");
    CSpace::TMapPerType::iterator it;

    num_robots = footbots.size();
    LOG << "Number of robots = " << num_robots << endl;

    int id = rand() % num_robots;
    int i = 0;

    // loop using a pair for simple initialization of infected bot
    for(pair<CSpace::TMapPerType::iterator, int> x(it = footbots.begin(),i = 0); it != footbots.end(); it++, i++){
        CFootBotEntity& footBot = *any_cast<CFootBotEntity*>(x.first->second);
        Cfb_SIR_diffusion_susceptible& c = dynamic_cast<Cfb_SIR_diffusion_susceptible&>(footBot.GetControllableEntity().GetController());

        // set random bot to infected
        if (x.second == id){
            c.setState(1);
        }
    }
}

void SIR_loop_functions::PostStep(){

    // CSpace::TMapPerType& footbots = GetSpace().GetEntitiesByType("foot-bot");
    // CSpace::TMapPerType::iterator it;

    // for(it = footbots.begin(); it != footbots.end(); it++){
        
    //     CFootBotEntity& footBot = *any_cast<CFootBotEntity*>(it->second);
    //     Cfb_SIR_diffusion_susceptible& cSusceptible = dynamic_cast<Cfb_SIR_diffusion_susceptible&>(footBot.GetControllableEntity().GetController());

    // }
}

REGISTER_LOOP_FUNCTIONS(SIR_loop_functions, "SIR_loop_functions")