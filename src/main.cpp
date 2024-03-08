#include "Knapsack.hpp"
#include "GeneticAlgorithm.hpp"
#include "Visualization.hpp"

int main() {
    std::vector<int> weights = { /* Fill with weights */ };
    std::vector<int> values = { /* Fill with values */ };
    int knapsackCapacity = /* Set knapsack capacity */;
    int numGenerations = /* Set number of generations */;
    int populationSize = /* Set population size */;

    Knapsack knapsack(weights, values, knapsackCapacity);

    GeneticAlgorithm ga;
    std::vector<std::vector<int>> initialPopulation = ga.initializePopulation(populationSize, weights.size());

    std::vector<int> solution = ga.optimize(initialPopulation, weights.size(), numGenerations, knapsackCapacity);

    Visualization visualization;
    visualization.plotSolution(solution, weights, values);

    return 0;
}
