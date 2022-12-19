import SIR_xml_config
import os
import matplotlib.pyplot as plt
from datetime import datetime

time_step = []
num_susceptible = []
num_infected = []
num_recovered = []
rem = 1000           # remaining lines to be read after no more bots are infected

def read(fname):
    count = 0
    with open(fname) as f:
        for line in f.readlines():
            data = line.strip().split(',')
            if data[0] == '<cur_step>':
                continue
            time_step.append(int(data[0])/SIR_xml_config.TPS)  # also converting from steps to seconds
            num_susceptible.append(int(data[1]))
            num_infected.append(int(data[2]))
            num_recovered.append(int(data[3]))

            # if no more infected, done reading file
            if data[2] == '0':
                count += 1
                if count == rem:
                    return

def plot(plt_fname):

    plt.plot(time_step, num_susceptible, color='g', label='Susceptible')
    plt.plot(time_step, num_infected, color='r', label='Infected')
    plt.plot(time_step, num_recovered, color='y', label='Recovered')

    plt.xlabel("Simulation Time (seconds)")
    plt.ylabel("Number of Robots")
    plt.title("ARGoS Simulation of SIR Model")

    plt.legend()

    plt.savefig(plt_fname)
    plt.show()

def getFilenames():

    # now = datetime.now()
    # return "./results/raw/SIR_data_"+str(now)+".txt", "./results/plots/SIR_data_plot_"+str(now)+".png"

    # data file identifier (tag) is based on config file parameters, BOT_COUNT and ARENA_SIZE
    tag = str(SIR_xml_config.BOT_COUNT)+"b-"+str(SIR_xml_config.ARENA_SIZE[0])+'x'+str(SIR_xml_config.ARENA_SIZE[1])
    # file paths
    t_path = "./results/raw/SIR_data-"
    p_path = "./results/plots/SIR_data-"
    # file formats
    t_format = ".txt"
    p_format = ".png"
    # concatenate
    t_fname = t_path+tag+t_format
    p_fname = p_path+tag+p_format
    
    return t_fname, p_fname

if __name__ == "__main__":
    txt_fname,plt_fname = getFilenames()

    SIR_xml_config.createXML(txt_fname)
    
    os.system("argos3 -c ./experiments/SIR_sim.xml")

    read(txt_fname)
    plot(plt_fname)