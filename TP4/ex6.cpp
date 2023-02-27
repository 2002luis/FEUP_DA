#include "exercises.h"

#include <limits>
#include <thread>
#include <algorithm>
#include <cmath>

/**
 * Defines the number of threads to be used.
 */
static int numThreads = 1;
void setNumThreads(int num) {
    numThreads = num;
}

Result nearestPointsDC(std::vector<Point> &vp) {
    Result res;
    // TODO
    return res;
}

Result nearestPointsDC_MT(std::vector<Point> &vp) {
    Result res;
    // TODO
    return res;
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP4_Ex6, testNP_DC) {
    testNearestPoints(nearestPointsDC, "Divide and conquer");
}

TEST(TP4_Ex6, testNP_DC_2Threads) {
    setNumThreads(2);
    testNearestPoints(nearestPointsDC_MT, "Divide and conquer with 2 threads");
}

TEST(TP4_Ex6, testNP_DC_4Threads) {
    setNumThreads(4);
    testNearestPoints(nearestPointsDC_MT, "Divide and conquer with 4 threads");
}

TEST(TP4_Ex6, testNP_DC_8Threads) {
    setNumThreads(8);
    testNearestPoints(nearestPointsDC_MT, "Divide and conquer with 8 threads");
}