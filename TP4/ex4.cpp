// By: Gonçalo Leão

#include "exercises.h"

#include <algorithm>

std::vector<std::vector<double>> strassen(const std::vector<std::vector<double>> &X, const std::vector<std::vector<double>> &Y) {
    std::vector<std::vector<double>> res;
    // TODO
    return res;
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP4_Ex4, testStrasssen_square_powerOf2_matrices) {
    // 1x1 times 1x1
    std::vector<std::vector<double>> X = {{-2}};
    std::vector<std::vector<double>> Y = {{4.5}};
    auto Z = strassen(X,Y);
    std::vector<std::vector<double>> correctVal = {{-9}};
    EXPECT_EQ(Z.size(),correctVal.size());
    if(!Z.empty()) {
        EXPECT_EQ(Z[0].size(),correctVal[0].size());
    }
    EXPECT_EQ(Z,correctVal);

    // 4x4 times 4x4
    X = {{1,1,1,1},{2,2,2,2},{3,3,3,3},{2,2,2,2}};
    Z = strassen(X,X);
    correctVal = {{8,8,8,8},{16,16,16,16},{24,24,24,24},{16,16,16,16}};
    EXPECT_EQ(Z.size(),correctVal.size());
    if(!Z.empty()) {
        EXPECT_EQ(Z[0].size(),correctVal[0].size());
    }
    EXPECT_EQ(Z,correctVal);

    // Another 4x4 times 4x4
    X = {{5,2,6,1},{0,6,2,0},{3,8,1,4},{1,8,5,6}};
    Y = {{7,5,8,0},{1,8,2,6},{9,4,3,8},{5,3,7,9}};
    Z = strassen(X,Y);
    correctVal = {{96,68,69,69},{24,56,18,52},{58,95,71,92},{90,107,81,142}};
    EXPECT_EQ(Z.size(),correctVal.size());
    if(!Z.empty()) {
        EXPECT_EQ(Z[0].size(),correctVal[0].size());
    }
    EXPECT_EQ(Z,correctVal);
}

TEST(TP4_Ex4, testStrasssen_square_nonPowerOf2_matrices) {
    // 3x3 times 3x3
    std::vector<std::vector<double>> X = {{1,2,3},{4,5,6},{7,8,9}};
    std::vector<std::vector<double>> Y = {{1,2,1},{2,4,6},{7,2,5}};
    auto Z = strassen(X,Y);
    std::vector<std::vector<double>> correctVal = {{26,16,28},{56,40,64},{86,64,100}};
    EXPECT_EQ(Z.size(),correctVal.size());
    if(!Z.empty()) {
        EXPECT_EQ(Z[0].size(),correctVal[0].size());
    }
    EXPECT_EQ(Z,correctVal);
}

TEST(TP4_Ex4, testStrasssen_non_square_matrices) {
    // 1x3 times 3x1
    std::vector<std::vector<double>> X = {{2,2,2}};
    std::vector<std::vector<double>> Y = {{2},{2},{2}};
    auto Z = strassen(X,Y);
    std::vector<std::vector<double>> correctVal = {{12}};
    EXPECT_EQ(Z.size(),correctVal.size());
    if(!Z.empty()) {
        EXPECT_EQ(Z[0].size(),correctVal[0].size());
    }
    EXPECT_EQ(Z,correctVal);

    // 2x2 times 2x3
    X = {{1,2},{3,4}};
    Y = {{5,6,7},{8,9,10}};
    Z = strassen(X,Y);
    correctVal = {{21,24,27},{47,54,61}};
    EXPECT_EQ(Z.size(),correctVal.size());
    if(!Z.empty()) {
        EXPECT_EQ(Z[0].size(),correctVal[0].size());
    }
    EXPECT_EQ(Z,correctVal);
}