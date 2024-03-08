#ifndef VISUALIZATION_HPP
#define VISUALIZATION_HPP

#include <vector>
#include "gnuplot-iostream.h"

class Visualization {
public:
    Visualization();
    ~Visualization();
    void plotFitnessHistory(const std::vector<double>& fitnessHistoryMean, const std::vector<double>& fitnessHistoryMax);

private:
    Gnuplot gp;
};

#endif
