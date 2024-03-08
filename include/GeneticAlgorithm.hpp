#ifndef GENETICALGORITHM_HPP
#define GENETICALGORITHM_HPP
using namespace std;

#include <vector>

class GeneticAlgorithm {
public:
    GeneticAlgorithm();
    ~GeneticAlgorithm();
    vector<vector<int>> initializePopulation(int populationSize, int chromosomeSize);
    vector<vector<int>> selection(vector<vector<int>>& population, vector<int>& fitnessValues, int numParents);
    vector<vector<int>> crossover(vector<vector<int>>& parents, int numOffsprings);
    vector<vector<int>> mutation(vector<vector<int>>& offsprings, double mutationRate);
    vector<int> optimize(vector<vector<int>>& population, vector<int>& fitnessValues, vector<int>& weights, vector<int>& values, int knapsackCapacity, int numGenerations);

private:
    vector<int> calculateFitnessValues(vector<vector<int>>& population, vector<int>& weights, vector<int>& values, int knapsackCapacity);
};

#endif