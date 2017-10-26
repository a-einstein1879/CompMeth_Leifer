#!/bin/bash

g++ main.cpp table.cpp cell.cpp variable.cpp -o simulator
chmod 777 simulator
./simulator
