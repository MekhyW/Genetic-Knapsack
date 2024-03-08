#ifndef KNAPSACK_HPP
#define KNAPSACK_HPP

#include <vector>

class Knapsack {
public:
    Knapsack();
    ~Knapsack();
    void generateItems(int itemCount);
    int calculateFitness(std::vector<int>& population, int capacity);
    std::vector<int> selectItems(std::vector<int>& itemNumbers, std::vector<int>& population);
    int calculateTotalWeight(std::vector<int>& selectedItems, std::vector<int>& weights);
    void printSelectedItems(std::vector<int>& selectedItems);

private:
    std::vector<int> itemNumbers;
    std::vector<int> weights;
    std::vector<int> values;
};

#endif
