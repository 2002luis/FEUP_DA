// By: Gonçalo Leão

#include "exercises.h"

#include <algorithm>
#include <algorithm>

bool sortBy1st(std::pair<float,int> p1, std::pair<float,int> p2){
    return (p1.first>p2.first);
}

double fractionalKnapsackGR(unsigned int values[], unsigned int weights[], unsigned int n, unsigned int maxWeight, double usedItems[]) {
    std::vector<std::pair<float,int>> ratio;
    for(int i = 0; i < n; i++){
        ratio.push_back({(float)values[i]/(float)weights[i],i});
    }
    std::sort(ratio.begin(),ratio.end(), sortBy1st);
    unsigned int bag = 0;
    double value = 0;
    for(auto i : ratio){
        if(maxWeight>=(bag+weights[i.second])){
            usedItems[i.second] = 1;
            bag+=weights[i.second];
            value+=values[i.second];
        }
        else if (maxWeight!=bag){
            double used = (double)values[i.second]*((double)(maxWeight-bag)/(double)weights[i.second]);
            usedItems[i.second] = (double)(maxWeight-bag)/(double)weights[i.second];
            bag = maxWeight;
            value+=used;
        }
        else usedItems[i.second] = 0.0;
    }
    return value;
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP3_Ex4, testFractionalKnapsack_3items) {
    const unsigned int n = 3;
    {
        unsigned int values[n] = {60, 100, 120};
        unsigned int weights[n] = {10, 20, 30};
        double usedItems[n];

        EXPECT_NEAR(fractionalKnapsackGR(values, weights, n, 50, usedItems), 240.0, 0.00001);
        EXPECT_NEAR(usedItems[0], 1.0, 0.00001);
        EXPECT_NEAR(usedItems[1], 1.0, 0.00001);
        EXPECT_NEAR(usedItems[2], 2.0/3.0, 0.00001);
    }
}

TEST(TP3_Ex4, testFractionalKnapsack_7items) {
    const unsigned int n = 7;
    {
        unsigned int values[n] = {10, 5, 15, 7, 6, 18, 3};
        unsigned int weights[n] = {2, 3, 5, 7, 1, 4, 1};
        double usedItems[n];

        EXPECT_NEAR(fractionalKnapsackGR(values, weights, n, 15, usedItems), 52.0 + 10.0/3.0, 0.00001);
        EXPECT_NEAR(usedItems[0], 1.0, 0.00001);
        EXPECT_NEAR(usedItems[1], 2.0/3.0, 0.00001);
        EXPECT_NEAR(usedItems[2], 1.0, 0.00001);
        EXPECT_NEAR(usedItems[3], 0.0, 0.00001);
        EXPECT_NEAR(usedItems[4], 1.0, 0.00001);
        EXPECT_NEAR(usedItems[5], 1.0, 0.00001);
        EXPECT_NEAR(usedItems[6], 1.0, 0.00001);
    }
}