#ifndef TEST_AUX_H_
#define TEST_AUX_H_

#include <gtest/gtest.h>

#include <sstream>
#include <random>
#include <ctime>
#include <chrono>
#include "../data_structures/Graph.h"

#include "exercises.h"

/**
 * Auxiliary functions to tests...
 *
 */
DPGraph CreateTestGraph();
DPGraph CreateTestGraph2();

template <typename T1, typename T2>
std::basic_ostream<char>& operator<<(std::basic_ostream<char> & strm, const std::pair<T1, T2>& kvPair)
{
    strm << "(" << kvPair.first << ", " << kvPair.second << ")";
    return strm;
}


void generateRandomGridGraph(int n, DPGraph & g);

void checkAllPaths(DPGraph &g, std::string expected);

void checkSinglePath(std::vector<int> path, std::string expected);

#endif /* TEST_AUX_H_ */
