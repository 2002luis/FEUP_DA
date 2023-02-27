#ifndef TEST_AUX_H_
#define TEST_AUX_H_

#include "exercises.h"

GreedyGraph createMSTTestGraph();
void generateRandomGridGraph(int n, GreedyGraph & g);
bool isSpanningTree(const std::vector<Vertex *> &res);
double spanningTreeCost(const std::vector<Vertex *> &res);

#endif //TEST_AUX_H_
