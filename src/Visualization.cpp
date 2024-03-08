#include "Visualization.hpp"

Visualization::Visualization() {}

Visualization::~Visualization() {}

void Visualization::plotFitnessHistory(const std::vector<double>& fitnessHistoryMean, const std::vector<double>& fitnessHistoryMax) {
    // Set plot title and labels
    gp << "set title 'Fitness through the Generations'\n";
    gp << "set xlabel 'Generations'\n";
    gp << "set ylabel 'Fitness'\n";

    // Plot fitness history
    gp << "plot '-' with lines title 'Mean Fitness', '-' with lines title 'Max Fitness'\n";
    gp.send1d(std::make_tuple(fitnessHistoryMean));
    gp.send1d(std::make_tuple(fitnessHistoryMax));

    // Pause to keep the plot window open
    std::cout << "Press enter to exit..." << std::endl;
    std::cin.get();
}
