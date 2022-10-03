#ifndef SIR_SIM
#define SIR_SIM

#include <array>
#include <vector>
#include <string>

using namespace std;

// global variables (settings)
const int PI = 3.1415926535;
const int PERIOD_OF_INFECTION = 15;
const int PROBABILITY_OF_INFECTION = 3; // in %
const int NUM_BOTS = 10;

// enumeration of compartments
enum BotType{
    SUSCEPTIBLE = 0,
    INFECTIOUS = 1,
    RECOVERED = 2,
};

// for recording data/statistics of simulation
struct DataRecord {
    size_t susceptible;
    size_t infected;
    size_t recovered;
};

// class for bot operations
class Bots{
    private:
        BotType type;
        int infected_steps = 0;
    public:
        Bots();
        Bots(const BotType bot_type);
        BotType getBotType() const;
        void changeBotType(BotType type);
        bool checkRecoverStatus() const;
};

// main simulation class
class Simulation{
    private:
        bool run = true;

        vector<Bots*> susceptible_bots;
        vector<Bots*> infectected_bots;
        vector<Bots*> recovered_bots;

        vector<DataRecord> stats;

        int simulation_steps = 0;

    public:
        Simulation();
        ~Simulation();
        bool isRun() const;
        void oneStepSimulation();
        void inputProcessing();
        void render();
        void writeStatsToFile(const string path);

    private:
        bool _isEndOfEpidemic() const;
};

#endif