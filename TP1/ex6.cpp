// By: Gonçalo Leão

#include "exercises.h"

#include "TestAux.h"

std::vector<std::vector<int>> IntroGraph::computeSCCs() const {
    std::vector<std::vector<int>> sccs;
    // TODO
    return sccs;
}

/// TESTS ///
#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(TP1_Ex6, test_SCC) {
    IntroGraph graph;
    createNetwork(graph);
    std::vector<std::vector<int>> sccs = graph.computeSCCs();

    EXPECT_EQ(sccs.size(), 3);
    EXPECT_THAT(sccs,  ::testing::UnorderedElementsAre(::testing::UnorderedElementsAre(1,2,3,5,6), ::testing::UnorderedElementsAre(4), ::testing::UnorderedElementsAre(7)));

    IntroGraph graph2;
    for(unsigned int i = 1; i <= 5; i++) {
        graph2.addVertex(i);
    }
    graph2.addEdge(1,3,0);
    graph2.addEdge(1,4,0);
    graph2.addEdge(2,1,0);
    graph2.addEdge(3,2,0);
    graph2.addEdge(4,5,0);
    sccs = graph2.computeSCCs();

    EXPECT_EQ(sccs.size(), 3);
    EXPECT_THAT(sccs,  ::testing::UnorderedElementsAre(::testing::UnorderedElementsAre(1,2,3), ::testing::UnorderedElementsAre(4), ::testing::UnorderedElementsAre(5)));
}