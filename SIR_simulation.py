import SIR_xml_config
import os
import matplotlib.pyplot as plt
from datetime import datetime

cur_step = []
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
            cur_step.append(int(data[0]))
            num_susceptible.append(int(data[1]))
            num_infected.append(int(data[2]))
            num_recovered.append(int(data[3]))

            # if no more infected, done reading file
            if data[2] == '0':
                count += 1
                if count == rem:
                    return

def plot(plt_fname):
    plt.plot(cur_step, num_susceptible, color='g', label='susceptible')
    plt.plot(cur_step, num_infected, color='r', label='infected')
    plt.plot(cur_step, num_recovered, color='y', label='recovered')

    plt.xlabel("Simulation Steps")
    plt.ylabel("Number of Bots")
    plt.title("SIR Diffusion Simulation Plot")

    plt.legend()

    plt.savefig(plt_fname)
    plt.show()

def getFilenames():
    now = datetime.now()
    return "./results/raw/SIR_data_"+str(now)+".txt", "./results/plots/SIR_data_plot_"+str(now)+".png"

if __name__ == "__main__":
    txt_fname,plt_fname = getFilenames()
    # try:
    #     SIR_xml_config.createXML(fname)
    # except:
    #     print("Something went wrong creating the XML file...")

    SIR_xml_config.createXML(txt_fname)
    
    os.system("argos3 -c ./experiments/SIR_sim.xml")

    read(txt_fname)
    plot(plt_fname)