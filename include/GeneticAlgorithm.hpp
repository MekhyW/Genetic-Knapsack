#ifndef GENETICALGORITHM_HPP
#define GENETICALGORITHM_HPP

#include <vector>

class GeneticAlgorithm {
public:
    GeneticAlgorithm();
    ~GeneticAlgorithm();
    std::vector<std::vector<int>> initializePopulation(int populationSize, int chromosomeSize);
    std::vector<std::vector<int>> selection(std::vector<std::vector<int>>& population, std::vector<int>& fitnessValues, int numParents);
    std::vector<std::vector<int>> crossover(std::vector<std::vector<int>>& parents, int numOffsprings);
    std::vector<std::vector<int>> mutation(std::vector<std::vector<int>>& offsprings, double mutationRate);
    std::vector<int> optimize(std::vector<std::vector<int>>& population, std::vector<int>& fitnessValues, std::vector<int>& weights, std::vector<int>& values, int knapsackCapacity, int numGenerations);

private:
    std::vector<int> calculateFitnessValues(std::vector<std::vector<int>>& population, std::vector<int>& weights, std::vector<int>& values, int knapsackCapacity);
};

#endif