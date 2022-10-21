#include "SIR_loop_functions.h"

SIR_loop_functions::SIR_loop_functions():
    num_robots(0), num_susceptible(0), num_infected(0), num_recovered(0), cur_step(0), filename(""), num_init_infected(0){}

/****************************************/
/****************************************/

void SIR_loop_functions::Init(TConfigurationNode& node){

    TConfigurationNode SIR_node = GetNode(node, "settings");

    GetNodeAttribute(SIR_node, "filename",                  filename);
    GetNodeAttribute(SIR_node, "num_init_infected",         num_init_infected);

    CSpace::TMapPerType& footbots = GetSpace().GetEntitiesByType("foot-bot");
    CSpace::TMapPerType::iterator it;

    // get total number of bots
    num_robots = footbots.size();
    LOG << "Number of robots = " << num_robots << endl;

    // vector to hold a list of random numbers of size = num_init_infected
    vector<int> id;

    // initialize random device
    random_device rd;
    mt19937 mt(rd());

    for(int i = 0; i < num_init_infected; i++){

        // get a random number between zero and the total number of bots
        uniform_int_distribution<int> iDistro(0, num_robots-1);
        id.push_back((int)iDistro(mt));
        LOG << "Rand_Number_"<< i << ": " << id[i] << endl;
    }

    // 2nd iterator for the loop below
    int i = 0;

    // loop using a pair for simple initialization of infected bot
    for(pair<CSpace::TMapPerType::iterator, int> x(it = footbots.begin(),i = 0); x.first != footbots.end(); x.first++, x.second++){
        CFootBotEntity& footBot = *any_cast<CFootBotEntity*>(x.first->second);
        Cfb_SIR_diffusion_susceptible& fb = dynamic_cast<Cfb_SIR_diffusion_susceptible&>(footBot.GetControllableEntity().GetController());

        for(int j : id){
            // set bot to infected if id matches random selction
            if (x.second == j){
                fb.setState(1);
            }
        }
    }

    // open a new rusults file in append mode
    outData.open(filename, ios::app);

    // format of results data appended to the top of file
    string dataFormat = "<cur_step>,<num_susceptible>,<num_infected>,<num_recovered>\n";
    outData << dataFormat;
}

/****************************************/
/****************************************/

void SIR_loop_functions::PreStep(){

    // reset state counters
    num_susceptible=0, num_infected=0, num_recovered=0;
}

/****************************************/
/****************************************/

void SIR_loop_functions::PostStep(){

    CSpace::TMapPerType& footbots = GetSpace().GetEntitiesByType("foot-bot");
    CSpace::TMapPerType::iterator it;

    for(it = footbots.begin(); it != footbots.end(); it++){
        CFootBotEntity& footBot = *any_cast<CFootBotEntity*>(it->second);
        Cfb_SIR_diffusion_susceptible& fb = dynamic_cast<Cfb_SIR_diffusion_susceptible&>(footBot.GetControllableEntity().GetController());

        cur_step = fb.getStep();

        switch(fb.getState()){
            case 0:
                num_susceptible++;
                break;
            case 1:
                num_infected++;
                break;
            case 2:
                num_recovered++;
                break;
            default:
                LOGERR << "ERR: Invalid state given to loop function.." << endl;
                break;
        }
    }

    // write to file
    outData << cur_step << "," << num_susceptible << "," << num_infected << "," << num_recovered << "\n";

}

/****************************************/
/****************************************/

bool SIR_loop_functions::IsExperimentFinished(){

    bool isFinished = false;

    size_t simTime = GetSpace().GetSimulationClock();

    // if there are no more infected bots, the experiment is finished
    if (simTime > 1 && num_infected == 0){
        isFinished = true;
    }

    if(isFinished){
        LOG << "No more infected bots. Experiment complete." << endl;
        PostExperiment();
    }

    return isFinished;

}

/****************************************/
/****************************************/

void SIR_loop_functions::PostExperiment(){

    // close file
    outData.close();
}

/****************************************/
/****************************************/

REGISTER_LOOP_FUNCTIONS(SIR_loop_functions, "SIR_loop_functions")