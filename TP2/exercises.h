// By: Gonçalo Leão

#ifndef DA_TP2_CLASSES_EXERCISES_H
#define DA_TP2_CLASSES_EXERCISES_H

#include <vector>

// Ex 1
bool sum3(unsigned int T, unsigned int nums[3]);

// Ex 2
bool subsetSumBF(unsigned int A[], unsigned int n, unsigned int T, unsigned int subset[], unsigned int &subsetSize);

// Ex 3
int maxSubsequence(int A[], unsigned int n, unsigned int &i, unsigned int &j);

// Ex 4
bool changeMakingBF(unsigned int C[], unsigned int Stock[], unsigned int n, unsigned int T, unsigned int usedCoins[]);

// Ex 5 closest pair
#include "../running_examples/closest_point_pair/ClosestPointPair.h"
Result nearestPointsBF(std::vector<Point> &vp);

// Ex 6
unsigned int knapsackBF(unsigned int values[], unsigned int weights[], unsigned int n, unsigned int maxWeight, bool usedItems[]);

// Ex 7
unsigned int tspBF(const unsigned int **dists, unsigned int n, unsigned int path[]);

#endif //DA_TP2_CLASSES_EXERCISES_H
