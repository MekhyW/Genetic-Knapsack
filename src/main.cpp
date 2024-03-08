#include "Knapsack.hpp"
#include "GeneticAlgorithm.hpp"
#include "Visualization.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> weights = { /* Fill with weights */ };
    vector<int> values = { /* Fill with values */ };
    int knapsackCapacity = /* Set knapsack capacity */;
    int numGenerations = /* Set number of generations */;
    int populationSize = /* Set population size */;

    Knapsack knapsack(weights, values, knapsackCapacity);

    GeneticAlgorithm ga;
    vector<vector<int>> initialPopulation = ga.initializePopulation(populationSize, weights.size());

    vector<int> solution = ga.optimize(initialPopulation, weights.size(), numGenerations, knapsackCapacity);

    Visualization visualization;
    visualization.plotSolution(solution, weights, values);

    return 0;
}
