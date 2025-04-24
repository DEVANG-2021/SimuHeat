// heat_simulation.h
#ifndef HEAT_SIMULATION_H
#define HEAT_SIMULATION_H

#include <vector>

void initialize(std::vector<std::vector<double>>& grid);
void save_to_file(const std::vector<std::vector<double>>& grid, int step);
void simulate();

#endif // HEAT_SIMULATION_H
