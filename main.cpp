// heat_simulation.cpp
#include "heat_simulation.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

const int NX = 50;
const int NY = 50;
const int STEPS = 500;
const double ALPHA = 0.01;
const double DT = 0.1;
const double DX = 1.0;

void initialize(std::vector<std::vector<double>>& grid) {
    for (int i = 0; i < NX; ++i) {
        for (int j = 0; j < NY; ++j) {
            if ((i > 20 && i < 30) && (j > 20 && j < 30))
                grid[i][j] = 100.0;
            else
                grid[i][j] = 25.0;
        }
    }
}

void save_to_file(const std::vector<std::vector<double>>& grid, int step) {
    std::ofstream file("output/heat_" + std::to_string(step) + ".dat");
    for (int i = 0; i < NX; ++i) {
        for (int j = 0; j < NY; ++j) {
            file << i << " " << j << " " << std::fixed << std::setprecision(2) << grid[i][j] << "\n";
        }
        file << "\n";
    }
    file.close();
}

void simulate() {
    std::vector<std::vector<double>> current(NX, std::vector<double>(NY));
    std::vector<std::vector<double>> next(NX, std::vector<double>(NY));

    initialize(current);

    for (int step = 0; step <= STEPS; ++step) {
        if (step % 50 == 0) {
            save_to_file(current, step);
            std::cout << "Saved step " << step << "\n";
        }

        for (int i = 1; i < NX - 1; ++i) {
            for (int j = 1; j < NY - 1; ++j) {
                next[i][j] = current[i][j] + ALPHA * DT * (
                    (current[i+1][j] - 2 * current[i][j] + current[i-1][j]) / (DX * DX) +
                    (current[i][j+1] - 2 * current[i][j] + current[i][j-1]) / (DX * DX)
                );
            }
        }
        current.swap(next);
    }
}
