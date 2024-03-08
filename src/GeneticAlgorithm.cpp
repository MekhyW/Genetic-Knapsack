#include "GeneticAlgorithm.hpp"
#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

GeneticAlgorithm::GeneticAlgorithm() {}

GeneticAlgorithm::~GeneticAlgorithm() {}

vector<vector<int>> GeneticAlgorithm::initializePopulation(int populationSize, int chromosomeSize) {
    vector<vector<int>> population(populationSize, vector<int>(chromosomeSize));
    for (auto& chromosome : population) {
        for (int i = 0; i < chromosomeSize; ++i) {
            chromosome[i] = rand() % 2;
        }
    }
    return population;
}

vector<vector<int>> GeneticAlgorithm::selection(vector<vector<int>>& population, vector<int>& fitnessValues, int numParents) {
    vector<vector<int>> parents(numParents, vector<int>(population[0].size()));
    for (int i = 0; i < numParents; ++i) {
        auto maxFitnessIndex = max_element(fitnessValues.begin(), fitnessValues.end());
        int index = maxFitnessIndex - fitnessValues.begin();
        parents[i] = population[index];
        fitnessValues[index] = -1;
    }
    return parents;
}

vector<vector<int>> GeneticAlgorithm::crossover(vector<vector<int>>& parents, int numOffsprings) {
    vector<vector<int>> offsprings(numOffsprings, vector<int>(parents[0].size()));
    int crossoverPoint = parents[0].size() / 2;
    for (int i = 0; i < numOffsprings; ++i) {
        int parent1Index = i % parents.size();
        int parent2Index = (i + 1) % parents.size();
        for (int j = 0; j < crossoverPoint; ++j) {
            offsprings[i][j] = parents[parent1Index][j];
        }
        for (int j = crossoverPoint; j < parents[0].size(); ++j) {
            offsprings[i][j] = parents[parent2Index][j];
        }
    }
    return offsprings;
}

vector<vector<int>> GeneticAlgorithm::mutation(vector<vector<int>>& offsprings, double mutationRate) {
    vector<vector<int>> mutants = offsprings;
    for (auto& chromosome : mutants) {
        for (int i = 0; i < chromosome.size(); ++i) {
            double randomValue = (double)rand() / RAND_MAX;
            if (randomValue < mutationRate) {
                chromosome[i] = 1 - chromosome[i]; // Flip the bit
            }
        }
    }
    return mutants;
}

vector<int> GeneticAlgorithm::optimize(vector<vector<int>>& population, vector<int>& fitnessValues, vector<int>& weights, vector<int>& values, int knapsackCapacity, int numGenerations) {
    vector<int> parameters;
    for (int generation = 0; generation < numGenerations; ++generation) {
        vector<vector<int>> parents = selection(population, fitnessValues, population.size() / 2);
        vector<vector<int>> offsprings = crossover(parents, population.size() - parents.size());
        vector<vector<int>> mutants = mutation(offsprings, 0.15);
        population.clear();
        population.insert(population.end(), parents.begin(), parents.end());
        population.insert(population.end(), mutants.begin(), mutants.end());
        fitnessValues = calculateFitnessValues(population, weights, values, knapsackCapacity);
    }
    auto maxFitnessIndex = max_element(fitnessValues.begin(), fitnessValues.end());
    int index = maxFitnessIndex - fitnessValues.begin();
    parameters = population[index];
    return parameters;
}

vector<int> GeneticAlgorithm::calculateFitnessValues(vector<vector<int>>& population, vector<int>& weights, vector<int>& values, int knapsackCapacity) {
    vector<int> fitnessValues(population.size(), 0);
    for (size_t i = 0; i < population.size(); ++i) {
        int totalWeight = 0;
        int totalValue = 0;
        for (size_t j = 0; j < population[i].size(); ++j) {
            if (population[i][j] == 1) {
                totalWeight += weights[j];
                totalValue += values[j];
            }
        }
        if (totalWeight <= knapsackCapacity) {
            fitnessValues[i] = totalValue;
        }
    }
    return fitnessValues;
}
