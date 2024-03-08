#include "Knapsack.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

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

int Knapsack::calculateFitness(vector<int>& population, int capacity) {
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

vector<int> Knapsack::selectItems(vector<int>& itemNumbers, vector<int>& population) {
    vector<int> selectedItems;
    for (size_t i = 0; i < population.size(); ++i) {
        if (population[i] != 0) {
            selectedItems.push_back(itemNumbers[i]);
        }
    }
    return selectedItems;
}

int Knapsack::calculateTotalWeight(vector<int>& selectedItems, vector<int>& weights) {
    int totalWeight = 0;
    for (size_t i = 0; i < selectedItems.size(); ++i) {
        totalWeight += weights[selectedItems[i] - 1];
    }
    return totalWeight;
}

void Knapsack::printSelectedItems(vector<int>& selectedItems) {
    for (size_t i = 0; i < selectedItems.size(); ++i) {
        cout << selectedItems[i] << "\t";
    }
    cout << endl;
}
