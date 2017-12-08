import subprocess

# TODO: this needs rework
output = subprocess.check_output("g++ main.cpp table.cpp cell.cpp variable.cpp oscillator.cpp -o simulator -std=c++11", shell=True)
print(output)
output = subprocess.check_output("chmod 777 simulator", shell=True)
print(output)
output = subprocess.check_output("./simulator", shell=True)
print(output)
