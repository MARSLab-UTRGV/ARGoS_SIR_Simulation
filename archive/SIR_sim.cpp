#include<cstdlib>
#include<iostream>
#include<fstream>
#include<time.h>

#include"SIR_sim.h"

Bots::Bots(){
    type = SUSCEPTIBLE;
};

Bots::Bots(const BotType bot_type): Bots(){
    type = bot_type;
}

BotType Bots::getBotType() const {return type;}

void Bots::changeBotType(BotType type) {this->type = type;}

bool Bots::checkRecoverStatus() const {
    if (type != INFECTIOUS) return false;

    // NEEDS WORK
}

// not sure if needed
int average (int *mass, int n){
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += mass[i];
    }

    return sum / n;
}

bool _check_collision (const Bots *bot1, const Bots *bot2){
    // NEEDS WORK
    return false;
}

Simulation::Simulation(){
    for (int i = 0; i < NUM_BOTS - 1; i++){
        susceptible_bots.push_back(new Bots());
    }

    infectected_bots.push_back(new Bots(INFECTIOUS));
} // NEEDS WORK

Simulation::~Simulation(){
    for (size_t i = 0; i < susceptible_bots.size(); i++){
        delete susceptible_bots[i];
    }
    for (size_t i = 0; i < infectected_bots.size(); i++){
        delete infectected_bots[i];
    }
    for (size_t i = 0; i < recovered_bots.size(); i++){
        delete recovered_bots[i];
    }
} // MAY NEED WORK

bool Simulation::isRun() const {return run;}

void Simulation::oneStepSimulation(){
    if (_isEndOfEpidemic()) run = false;

    const size_t num_of_infected = infectected_bots.size();
    for (size_t i = 0; i < num_of_infected; i++){
        for (size_t j = 0; j < susceptible_bots.size(); j++){
            if (_check_collision(infectected_bots[i], susceptible_bots[j])){
                susceptible_bots[j]->changeBotType(INFECTIOUS);
                infectected_bots.push_back(susceptible_bots[j]);
                susceptible_bots.erase(susceptible_bots.begin() + j);
            }
        }
    }

    // move

    // check period of illness for infected
    for (size_t i = 0; i < infectected_bots.size(); i++){
        if (infectected_bots[i]->checkRecoverStatus()){
            infectected_bots[i]->changeBotType(RECOVERED);
            recovered_bots.push_back(infectected_bots[i]);
            infectected_bots.erase(infectected_bots.begin() + i);
        }
    }

    DataRecord data_record = {susceptible_bots.size(), infectected_bots.size(), recovered_bots.size()};
    stats.push_back(data_record);
    simulation_steps++;
} // NEEDS WORK

void Simulation::writeStatsToFile(const string path){
    ofstream out(path);

    // Need to define STEPS_IN_DAY

    for(int i = 0; i < simulation_steps; i += STEPS_IN_DAY){
        out << stats[i].susceptible << " " << stats[i].infected << " " << stats[i].recovered << " " << endl;
    }

    for (simulation_steps % STEPS_IN_DAY != 0){
        int end = stats.size() - 1;
        out << stats[end].susceptible << " " << stats[end].infected << " " << stats[end].recovered << " " << endl;
    }

    out.close();
} // NEEDS WORK