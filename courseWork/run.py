import subprocess
import re
import matplotlib.pyplot as plt
import numpy as np

# TODO: this needs rework
output = subprocess.call("g++ main.cpp table.cpp cell.cpp variable.cpp oscillator.cpp -o simulator -std=c++11", shell=True)
print(output)
output = subprocess.call("chmod 777 simulator", shell=True)
print(output)
output = subprocess.call("./simulator", shell=True)
print(output)

# reading data from configuration file
configFile = open('config.txt', 'r')
config = configFile.readline()
numberOfCells = int(re.search(r'\d+', config).group(0))
config = configFile.readline()
cellType = int(re.search(r'\d+', config).group(0))
config = configFile.readline()
modelingTime = int(re.search(r'\d+', config).group(0))
config = configFile.readline()
phaseSpaceDimensionality = int(re.search(r'\d+', config).group(0))
configFile.close()

# reading output, now we know from where to read
data = np.empty([numberOfCells, phaseSpaceDimensionality, modelingTime], dtype = float)
fileNamePrefix = 'output'
fileNamePostfix = '.txt'
for i in range(numberOfCells):
    for j in range(phaseSpaceDimensionality):
        fileName = fileNamePrefix + str(i) + str(j) + fileNamePostfix
        dataFile = open(fileName, 'r')
        tmp = dataFile.read()
        x = tmp.split("\n")
        # TODO: understand why we need -1 and how to fix it
        # -1 here, because there is an empty line at the end for some reason
        for k in range(len(x) - 1):
            data[i][j][k] = x[k]
        dataFile.close()
        
x = np.linspace(1, modelingTime, modelingTime) #makes an evenly spaced array 50 values between 0 and 6
for i in range(numberOfCells):
    for j in range(phaseSpaceDimensionality):
        ll = 'Cell = ' + str(i) + '; dim = ' + str(j)
        plt.plot(x, data[i, j, :], label = ll)
plt.legend(loc='upper right')
plt.show() #show the plot if using interactive mode (otherwise does nothing)
