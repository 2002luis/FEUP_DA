// By: Gonçalo Leão

#include "exercises.h"

bool IntroGraph::isDAG() const {
    // TODO
    return false;
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP1_Ex5, test_isDAG) {
    IntroGraph myGraph;

    for(unsigned int i = 0; i < 6; i++) {
        myGraph.addVertex(i);
    }

    myGraph.addEdge(1, 2, 0);
    myGraph.addEdge(2, 5, 0);
    myGraph.addEdge(5, 4, 0);
    myGraph.addEdge(3, 1, 0);
    myGraph.addEdge(0, 4, 0);

    EXPECT_EQ(myGraph.isDAG(), true);

    myGraph.addEdge(4, 1, 0);

    EXPECT_EQ(myGraph.isDAG(), false);
}