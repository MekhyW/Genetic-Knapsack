#ifndef VISUALIZATION_HPP
#define VISUALIZATION_HPP
using namespace std;

#include <vector>
#include "gnuplot-iostream.h"

class Visualization {
public:
    Visualization();
    ~Visualization();
    void plotFitnessHistory(const vector<double>& fitnessHistoryMean, const vector<double>& fitnessHistoryMax);

private:
    Gnuplot gp;
};

#endif
