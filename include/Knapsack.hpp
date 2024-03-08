#ifndef KNAPSACK_HPP
#define KNAPSACK_HPP
using namespace std;

#include <vector>

class Knapsack {
public:
    Knapsack();
    ~Knapsack();
    void generateItems(int itemCount);
    int calculateFitness(vector<int>& population, int capacity);
    vector<int> selectItems(vector<int>& itemNumbers, vector<int>& population);
    int calculateTotalWeight(vector<int>& selectedItems, vector<int>& weights);
    void printSelectedItems(vector<int>& selectedItems);

private:
    vector<int> itemNumbers;
    vector<int> weights;
    vector<int> values;
};

#endif
