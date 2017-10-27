#!/bin/bash

echo -en "\033[42m Running simulation compilation process \033[0m\n"
g++ main.cpp table.cpp cell.cpp variable.cpp oscillator.cpp -o simulator -std=c++11
chmod 777 simulator
echo -en "\033[41m Code successfully compiled. Running simulation \033[0m\n"
./simulator
