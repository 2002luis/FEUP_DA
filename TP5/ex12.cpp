// By: Gonçalo Leão

#include "exercises.h"

#include "TestAux.h"

void DPGraph::floydWarshall() {
    // TODO
}

std::vector<int> DPGraph::getFloydWarshallPath(const int &origin, const int &dest) const{
    std::vector<int> res;
    // TODO
    return res;
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP5_Ex12, test_floydWarshall) {
    DPGraph myGraph = CreateTestGraph();
    myGraph.floydWarshall();
    checkSinglePath(myGraph.getFloydWarshallPath(1, 7), "1 2 4 5 7 ");
    checkSinglePath(myGraph.getFloydWarshallPath(5, 6), "5 7 6 ");
    checkSinglePath(myGraph.getFloydWarshallPath(7, 1), "7 6 4 3 1 ");
}