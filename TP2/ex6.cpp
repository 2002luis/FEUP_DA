// By: Gonçalo Leão

#include "exercises.h"
#include <algorithm>
#include <iostream>

bool sortBy1st(std::pair<float,int> p1, std::pair<float,int> p2){
    return (p1.first>p2.first);
}

unsigned int knapsackBF(unsigned int values[], unsigned int weights[], unsigned int n, unsigned int maxWeight, bool usedItems[]) {
    std::vector<std::pair<float,int>> ratio;
    for(int i = 0; i < n; i++){
        ratio.push_back({(float)values[i]/(float)weights[i],i});
    }
    std::sort(ratio.begin(),ratio.end(), sortBy1st);
    unsigned int bag = 0, value = 0;
    for(auto i : ratio){
        if(maxWeight>=(bag+weights[i.second])){
            usedItems[i.second] = true;
            bag+=weights[i.second];
            value+=values[i.second];
        }
        else usedItems[i.second] = false;
    }
    return value;
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP2_Ex6, testKnapsack_4items) {
    const unsigned int n = 4;
    {
        unsigned int values[n] = {10, 7, 11, 15};
        unsigned int weights[n] = {1, 2, 1, 3};
        bool usedItems[n];

        EXPECT_EQ(knapsackBF(values, weights, n, 5, usedItems), 36);
        EXPECT_EQ(usedItems[0], true);
        EXPECT_EQ(usedItems[1], false);
        EXPECT_EQ(usedItems[2], true);
        EXPECT_EQ(usedItems[3], true);
    }

    {
        unsigned int values[n] = {3, 4, 5, 6};
        unsigned int weights[n] = {2, 3, 4, 5};
        bool usedItems[n];

        EXPECT_EQ(knapsackBF(values, weights, n, 5, usedItems), 7);
        EXPECT_EQ(usedItems[0], true);
        EXPECT_EQ(usedItems[1], true);
        EXPECT_EQ(usedItems[2], false);
        EXPECT_EQ(usedItems[3], false);
    }
}

TEST(TP2_Ex6, testKnapsack_5items) {
    const unsigned int n = 5;
    {
        unsigned int values[n] = {1, 2, 5, 9, 4};
        unsigned int weights[n] = {2, 3, 3, 4, 6};
        bool usedItems[n];

        EXPECT_EQ(knapsackBF(values, weights, n, 10, usedItems), 16);
        EXPECT_EQ(usedItems[0], false);
        EXPECT_EQ(usedItems[1], true);
        EXPECT_EQ(usedItems[2], true);
        EXPECT_EQ(usedItems[3], true);
        EXPECT_EQ(usedItems[4], false);
    }
}