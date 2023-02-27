// By: Gonçalo Leão

#include "exercises.h"

int maxSubsequenceDP(int A[], unsigned int n, unsigned int &i, unsigned int &j) {
    // TODO
    return 0;
}

int maxSubsequenceBF(int A[], unsigned int n, unsigned int &i, unsigned int &j) {
    // TODO: Copy your solution from TP2
    return 0;
}

int maxSubsequenceDC(int A[], unsigned int n, int &i, int &j) {
    // TODO: Copy your solution from TP4
    return 0;
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP5_Ex6, testMaxSubsequence) {
    int A1[] = {1, 2, 3, 4};
    unsigned int n1 = 4;
    unsigned int i, j;
    EXPECT_EQ(maxSubsequenceDP(A1,n1,i,j), 10);
    EXPECT_EQ(i, 0);
    EXPECT_EQ(j, 3);

    int A2[] = {2, -1, -3, 4};
    unsigned int n2 = 4;
    EXPECT_EQ(maxSubsequenceDP(A2,n2,i,j), 4);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 3);

    int A3[] = {2, -1, 3, 4};
    unsigned int n3 = 4;
    EXPECT_EQ(maxSubsequenceDP(A3,n3,i,j), 8);
    EXPECT_EQ(i, 0);
    EXPECT_EQ(j, 3);

    int A4[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    unsigned int n4 = 9;
    EXPECT_EQ(maxSubsequenceDP(A4,n4,i,j), 6);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 6);

    // Uncomment the next line to perform the execution time tests
    // testPerformanceMaxSubsequence();
}

#include <iostream>
#include <chrono>

void testPerformanceMaxSubsequence() {
    srand(time(NULL)); //generates random seed
    const unsigned long N_ITERATIONS = 5;
    const unsigned long MIN_SIZE = 0;
    const unsigned long MAX_SIZE = 10000;
    const unsigned long STEP_SIZE = 500;
    int seq[MAX_SIZE];

    std::cout << "n; DP time (s); BF time (s); DC time (s)" << std::endl;
    for(unsigned long size = MIN_SIZE; size <= MAX_SIZE; size += STEP_SIZE) {
        auto elapsedDP = std::chrono::duration<double>::zero();
        auto elapsedBF = std::chrono::duration<double>::zero();
        auto elapsedDC = std::chrono::duration<double>::zero();
        for(unsigned long k = 0; k < N_ITERATIONS; k++) {
            for(unsigned long i = 0; i < size; i++) {
                seq[i] = rand() % (10 * size) - (5 * size);
            }

            unsigned int i, j;
            auto start = std::chrono::high_resolution_clock::now();
            for(unsigned int k = 0; k < N_ITERATIONS; k++) {
                maxSubsequenceDP(seq, size, i, j);
            }
            auto finish = std::chrono::high_resolution_clock::now();
            elapsedDP += finish - start;

            start = std::chrono::high_resolution_clock::now();
            for(unsigned int k = 0; k < N_ITERATIONS; k++) {
                maxSubsequenceBF(seq, size, i, j);
            }
            finish = std::chrono::high_resolution_clock::now();
            elapsedBF += finish - start;

            int i2, j2;
            start = std::chrono::high_resolution_clock::now();
            for(unsigned int k = 0; k < N_ITERATIONS; k++) {
                maxSubsequenceDC(seq, size, i2, j2);
            }
            finish = std::chrono::high_resolution_clock::now();
            elapsedDC += finish - start;
        }
        std::cout << size << ";" << (elapsedDP.count() / N_ITERATIONS) << ";" << (elapsedBF.count() / N_ITERATIONS) << ";" << (elapsedDC.count() / N_ITERATIONS) << std::endl;
    }
}