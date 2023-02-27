// By: Gonçalo Leão

#include "exercises.h"

#include "TestAux.h"

std::vector<int> IntroGraph::bfs(const int & source) const {
    std::vector<int> res;
    // TODO
    return res;
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP1_Ex3, test_bfs) {
    IntroGraph graph;
    createNetwork(graph);
    std::vector<int> vs = graph.bfs(1);

    unsigned int ids[] = {1, 2, 3, 4, 5, 6, 7};
    EXPECT_EQ(vs.size(), 7);
    for (unsigned int i = 0; i < vs.size(); i++) {
        EXPECT_EQ(vs[i], ids[i]);
    }
}