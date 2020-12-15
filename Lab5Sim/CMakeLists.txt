cmake_minimum_required(VERSION 3.17)
project(Lab5Sim C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")

add_executable(Lab5Sim main.c SerialPort.c SerialPort.h UserInput.c UserInput.h GUI.c GUI.h Shared.h Simulator.c Simulator.h)