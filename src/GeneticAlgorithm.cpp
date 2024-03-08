#include "GeneticAlgorithm.hpp"
#include <iostream>
#include <algorithm>
#include <random>

GeneticAlgorithm::GeneticAlgorithm() {}

GeneticAlgorithm::~GeneticAlgorithm() {}

std::vector<std::vector<int>> GeneticAlgorithm::initializePopulation(int populationSize, int chromosomeSize) {
    std::vector<std::vector<int>> population(populationSize, std::vector<int>(chromosomeSize));
    for (auto& chromosome : population) {
        for (int i = 0; i < chromosomeSize; ++i) {
            chromosome[i] = rand() % 2;
        }
    }
    return population;
}

std::vector<std::vector<int>> GeneticAlgorithm::selection(std::vector<std::vector<int>>& population, std::vector<int>& fitnessValues, int numParents) {
    std::vector<std::vector<int>> parents(numParents, std::vector<int>(population[0].size()));
    for (int i = 0; i < numParents; ++i) {
        auto maxFitnessIndex = std::max_element(fitnessValues.begin(), fitnessValues.end());
        int index = maxFitnessIndex - fitnessValues.begin();
        parents[i] = population[index];
        fitnessValues[index] = -1;
    }
    return parents;
}

std::vector<std::vector<int>> GeneticAlgorithm::crossover(std::vector<std::vector<int>>& parents, int numOffsprings) {
    std::vector<std::vector<int>> offsprings(numOffsprings, std::vector<int>(parents[0].size()));
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

std::vector<std::vector<int>> GeneticAlgorithm::mutation(std::vector<std::vector<int>>& offsprings, double mutationRate) {
    std::vector<std::vector<int>> mutants = offsprings;
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

std::vector<int> GeneticAlgorithm::optimize(std::vector<std::vector<int>>& population, std::vector<int>& fitnessValues, std::vector<int>& weights, std::vector<int>& values, int knapsackCapacity, int numGenerations) {
    std::vector<int> parameters;
    for (int generation = 0; generation < numGenerations; ++generation) {
        std::vector<std::vector<int>> parents = selection(population, fitnessValues, population.size() / 2);
        std::vector<std::vector<int>> offsprings = crossover(parents, population.size() - parents.size());
        std::vector<std::vector<int>> mutants = mutation(offsprings, 0.15);
        population.clear();
        population.insert(population.end(), parents.begin(), parents.end());
        population.insert(population.end(), mutants.begin(), mutants.end());
        fitnessValues = calculateFitnessValues(population, weights, values, knapsackCapacity);
    }
    auto maxFitnessIndex = std::max_element(fitnessValues.begin(), fitnessValues.end());
    int index = maxFitnessIndex - fitnessValues.begin();
    parameters = population[index];
    return parameters;
}

std::vector<int> GeneticAlgorithm::calculateFitnessValues(std::vector<std::vector<int>>& population, std::vector<int>& weights, std::vector<int>& values, int knapsackCapacity) {
    std::vector<int> fitnessValues(population.size(), 0);
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
