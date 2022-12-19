# ARGoS SIR Model Simulation
SIR (Susceptible Infected and Recovered) model simulation in ARGoS

This is a simple SIR model simulation in ARGoS using FootBots with simple obstacle avoidance (Diffusion).

CURRENT ISSUE:
    Experiment is only terminating based on the length of time specified (configurable in 'SIR_xml_config.py'.

**INSTALLATION**

-PYTHON-

This simulation uses python, so make sure python3 is installed on your machine.

Please check that the following python packages are installed.

- matplotlib
- xml
- math
- os
- datetime

More than likely the only one you should have to install is 'matplotlib' (if you don't have it
already).

-ARGoS-

If you don't have ARGoS installed, refer to https://www.argos-sim.info/core.php
to download and install ARGoS for your machine.

**COMPILATION**

$ mkdir build
$ cd build

To produce debuggable code (slow), type:

$ cmake -DCMAKE_BUILD_TYPE=Debug ..

To produce fast but not debuggable code, type:

$ cmake -DCMAKE_BUILD_TYPE=Release ..

Finally, launch the compilation with the command:

$ make

If you find no error, you're ready to go to the next phase. 

**TROUBLESHOOTING**

When you launch one of the two 'cmake' commands, you might get an
error like 'package argos3_simulator' not found. This error has two
possible causes:

1.  You haven't installed ARGoS3 system-wide. Refer to https://www.argos-sim.info/core.php
    to download and install ARGoS for your machine.

2. You have installed ARGoS in a non-standard location. The standard
   locations are /usr and /usr/local. If you did not install ARGoS
   there, CMake won't be able to find the file ARGoSConfig.cmake at
   PREFIX/share/argos3/cmake. The solution in this case is to run
   
   $ cmake -DCMAKE_MODULE_PATH=/path/to/argos3/share/cmake
   
   Make sure that the folder /path/to/argos3/share/cmake contains the
   file ARGoSConfig.cmake.

**RUNNING THE EXPERIMENT**

$ python3 SIR_simulation.py

Depending on which python version you have installed you may only have to type 'python'.

After running the experiment, the results can be found in the '/results' directory. There will be
subdirectories '/plots' (holds the ploted data in png format) and '/raw' a text file of the raw data.

**CONFIGURATION**

There are limited paramters that can be adjusted in the 'SIR_xml_config.py' under where it says
"CONFIGURATION".

