// By: Gonçalo Leão

#include "exercises.h"

#include "../data_structures/Heap.h"

int kthSmallest(unsigned int k, std::vector<int> v) {
    // TODO
    return 0;
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP1_Ex9, test_kthSmallest) {
    auto A = {1, 2, 3, 4};
    EXPECT_EQ(kthSmallest(1,A), 1);
    EXPECT_EQ(kthSmallest(2,A), 2);
    EXPECT_EQ(kthSmallest(3,A), 3);
    EXPECT_EQ(kthSmallest(4,A), 4);

    A = {2, -1, -3, 4};
    EXPECT_EQ(kthSmallest(1,A), -3);
    EXPECT_EQ(kthSmallest(2,A), -1);
    EXPECT_EQ(kthSmallest(3,A), 2);
    EXPECT_EQ(kthSmallest(4,A), 4);

    A ={2, -1, 3, 4};
    EXPECT_EQ(kthSmallest(1,A), -1);
    EXPECT_EQ(kthSmallest(2,A), 2);
    EXPECT_EQ(kthSmallest(3,A), 3);
    EXPECT_EQ(kthSmallest(4,A), 4);

    A ={-2, 1, -3, 4, -1, 2, 1, -5, 4};
    EXPECT_EQ(kthSmallest(1,A), -5);
    EXPECT_EQ(kthSmallest(2,A), -3);
    EXPECT_EQ(kthSmallest(3,A), -2);
    EXPECT_EQ(kthSmallest(4,A), -1);
    EXPECT_EQ(kthSmallest(5,A),  1);
    EXPECT_EQ(kthSmallest(6,A),  1);
    EXPECT_EQ(kthSmallest(7,A),  2);
    EXPECT_EQ(kthSmallest(8,A),  4);
    EXPECT_EQ(kthSmallest(9,A),  4);
}