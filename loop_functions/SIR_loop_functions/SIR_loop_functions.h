#ifndef SIR_LOOP_FUNCTIONS_H
#define SIR_LOOP_FUNCTIONS_H

#include <argos3/core/simulator/loop_functions.h>
#include <argos3/plugins/robots/foot-bot/simulator/footbot_entity.h>
#include <argos3/core/simulator/entity/floor_entity.h>
#include <controllers/SIR_diffusion/SIR_diffusion.h>
#include <random>
#include <sstream>
#include <time.h>
#include <vector>

using namespace argos;
using namespace std;

class SIR_loop_functions : public CLoopFunctions
{

    friend class SIR_diffusion;

    public:

        /* Derived */
        SIR_loop_functions();

        void Init(TConfigurationNode& t_tree);
        //void Reset(){}
        void PreStep();
        void PostStep();
        // bool isExperimentFinished();
        void PostExperiment();
        //CColor GetFloorColor(const CVector2& c_pos_on_floor){}

    protected:

        size_t num_robots;
        size_t num_susceptible;
        size_t num_infected;
        size_t num_recovered;
        size_t num_init_infected;   // number of initially infected bots
        unsigned int cur_step;
        ofstream outData;
        string filename;

    private:



};


#endif