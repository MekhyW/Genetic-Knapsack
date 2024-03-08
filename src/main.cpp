#include <iostream>
#include "Knapsack.hpp"
#include "GeneticAlgorithm.hpp"
#include "Visualization.hpp"
using namespace std;

int main() {
    int numItems;
    int knapsackCapacity;
    int numGenerations;
    int populationSize;
    cout << "Enter the number of items: ";
    cin >> numItems;
    vector<int> weights(numItems);
    vector<int> values(numItems);
    cout << "Enter the weights of items:\n";
    for (int i = 0; i < numItems; ++i) {
        cout << "Item " << i + 1 << ": ";
        cin >> weights[i];
    }
    cout << "Enter the values of items:\n";
    for (int i = 0; i < numItems; ++i) {
        cout << "Item " << i + 1 << ": ";
        cin >> values[i];
    }
    cout << "Enter the capacity of the knapsack: ";
    cin >> knapsackCapacity;
    cout << "Enter the number of generations: ";
    cin >> numGenerations;
    cout << "Enter the population size: ";
    cin >> populationSize;

    Knapsack knapsack(weights, values, knapsackCapacity);

    GeneticAlgorithm ga;
    vector<vector<int>> initialPopulation = ga.initializePopulation(populationSize, weights.size());

    vector<int> solution = ga.optimize(initialPopulation, weights.size(), numGenerations, knapsackCapacity);

    Visualization visualization;
    visualization.plotSolution(solution, weights, values);

    return 0;
}
