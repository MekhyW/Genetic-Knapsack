#include "Knapsack.hpp"
#include <iostream>
#include <cstdlib>

Knapsack::Knapsack() {}

Knapsack::~Knapsack() {}

void Knapsack::generateItems(int itemCount) {
    itemNumbers.clear();
    weights.clear();
    values.clear();
    for (int i = 0; i < itemCount; ++i) {
        itemNumbers.push_back(i + 1);
        weights.push_back(rand() % 15 + 1);
        values.push_back(rand() % 100 + 1);
    }
}

int Knapsack::calculateFitness(std::vector<int>& population, int capacity) {
    int fitness = 0;
    int totalWeight = 0;
    for (size_t i = 0; i < population.size(); ++i) {
        if (population[i] != 0) {
            fitness += values[i];
            totalWeight += weights[i];
        }
    }
    if (totalWeight > capacity) {
        return 0;
    }
    return fitness;
}

std::vector<int> Knapsack::selectItems(std::vector<int>& itemNumbers, std::vector<int>& population) {
    std::vector<int> selectedItems;
    for (size_t i = 0; i < population.size(); ++i) {
        if (population[i] != 0) {
            selectedItems.push_back(itemNumbers[i]);
        }
    }
    return selectedItems;
}

int Knapsack::calculateTotalWeight(std::vector<int>& selectedItems, std::vector<int>& weights) {
    int totalWeight = 0;
    for (size_t i = 0; i < selectedItems.size(); ++i) {
        totalWeight += weights[selectedItems[i] - 1];
    }
    return totalWeight;
}

void Knapsack::printSelectedItems(std::vector<int>& selectedItems) {
    for (size_t i = 0; i < selectedItems.size(); ++i) {
        std::cout << selectedItems[i] << "\t";
    }
    std::cout << std::endl;
}
