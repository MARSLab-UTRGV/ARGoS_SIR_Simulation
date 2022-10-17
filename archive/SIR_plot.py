import matplotlib.pyplot as plt

cur_step = []
num_susceptible = []
num_infected = []
num_recovered = []
count = 0
rem = 1000           # remaining lines to be read after no more bots are infected

def read(fname):
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

def plot():
    plt.plot(cur_step, num_susceptible, color='g', label='susceptible')
    plt.plot(cur_step, num_infected, color='r', label='infected')
    plt.plot(cur_step, num_recovered, color='y', label='recovered')

    plt.xlabel("Simulation Steps")
    plt.ylabel("Number of Bots")
    plt.title("SIR Diffusion Plot (test)")

    plt.legend()

    plt.show()




