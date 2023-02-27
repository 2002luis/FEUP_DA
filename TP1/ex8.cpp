// By: Gonçalo Leão

#include "exercises.h"

#include "../data_structures/Heap.h"

std::vector<int> heapSort(std::vector<int> v) {
    std::vector<int> res;
    // TODO
    return res;
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP1_Ex8, test_heapSort) {
    auto A = heapSort({1, 2, 3, 4});
    EXPECT_EQ(A.size(), 4);
    if(A.size() == 4) {
        EXPECT_EQ(A[0], 1);
        EXPECT_EQ(A[1], 2);
        EXPECT_EQ(A[2], 3);
        EXPECT_EQ(A[3], 4);
    }

    A = heapSort({2, -1, -3, 4});
    EXPECT_EQ(A.size(), 4);
    if(A.size() == 4) {
        EXPECT_EQ(A[0], -3);
        EXPECT_EQ(A[1], -1);
        EXPECT_EQ(A[2], 2);
        EXPECT_EQ(A[3], 4);
    }

    A = heapSort({2, -1, 3, 4});
    EXPECT_EQ(A.size(), 4);
    if(A.size() == 4) {
        EXPECT_EQ(A[0], -1);
        EXPECT_EQ(A[1], 2);
        EXPECT_EQ(A[2], 3);
        EXPECT_EQ(A[3], 4);
    }

    A = heapSort({-2, 1, -3, 4, -1, 2, 1, -5, 4});
    EXPECT_EQ(A.size(), 9);
    if(A.size() == 9) {
        EXPECT_EQ(A[0], -5);
        EXPECT_EQ(A[1], -3);
        EXPECT_EQ(A[2], -2);
        EXPECT_EQ(A[3], -1);
        EXPECT_EQ(A[4],  1);
        EXPECT_EQ(A[5],  1);
        EXPECT_EQ(A[6],  2);
        EXPECT_EQ(A[7],  4);
        EXPECT_EQ(A[8],  4);
    }
}