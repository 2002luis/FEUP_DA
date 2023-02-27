// By: Gonçalo Leão

#include "exercises.h"

std::string hanoiDC(unsigned int n, char src, char dest) {
    // TODO
    return "";
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP4_Ex3, testHanoi_height4) {
    std::string moves = hanoiDC(4, 'A', 'B');
    EXPECT_EQ(std::count(moves.begin(),moves.end(),','),14); // there are 15 moves
    EXPECT_EQ(moves,"A->C,A->B,C->B,A->C,B->A,B->C,A->C,A->B,C->B,C->A,B->A,C->B,A->C,A->B,C->B");
}