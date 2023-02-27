// By: Gonçalo Leão

#include "exercises.h"

bool IntroGraph::removeEdge(const int &source, const int &dest) {
    // TODO
    return false;
}

bool IntroGraph::removeVertex(const int &id) {
    // TODO
    return false;
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP1_Ex1, test_removeEdge) {
    IntroGraph graph;

    graph.addVertex(19);
    graph.addVertex(33);
    graph.addVertex(20);
    graph.addVertex(18);

    EXPECT_EQ(graph.addEdge(19,33,0), true);
    EXPECT_EQ(graph.addEdge(19,20,0), true);
    EXPECT_EQ(graph.addEdge(19,18,0), true);
    EXPECT_EQ(graph.addEdge(33,18,0), true);

    EXPECT_EQ(graph.removeEdge(19,20), true);
    EXPECT_EQ(graph.removeEdge(19,20), false); // try removing the same edge twice

    EXPECT_EQ(graph.removeEdge(19,24), false); // try removing a non-existing edge that connects a vertex that does not exist
    EXPECT_EQ(graph.removeEdge(33,20), false); // try removing a non-existing edge that connects two existing vertices
}

TEST(TP1_Ex1, test_removeVertex_no_edges) {
    IntroGraph graph;

    graph.addVertex(19);
    graph.addVertex(33);
    graph.addVertex(20);
    graph.addVertex(18);

    EXPECT_EQ(graph.getVertexSet().size(), 4);
    EXPECT_EQ(graph.removeVertex(33), true);
    EXPECT_EQ(graph.removeVertex(33), false); // try removing a non-existing vertex
    EXPECT_EQ(graph.getVertexSet().size(), 3);
}

TEST(TP1_Ex1, test_removeVertex_with_edges) {
    {
        IntroGraph graph;

        graph.addVertex(19);
        graph.addVertex(33);
        graph.addVertex(20);
        graph.addVertex(18);

        EXPECT_EQ(true, graph.addEdge(19, 33, 0));
        EXPECT_EQ(true, graph.addEdge(19, 20, 0));
        EXPECT_EQ(true, graph.addEdge(19, 18, 0));
        EXPECT_EQ(true, graph.addEdge(18, 33, 0));

        EXPECT_EQ(graph.getVertexSet().size(), 4);
        EXPECT_EQ(graph.findVertex(18)->getAdj().size(), 1);
        EXPECT_EQ(graph.findVertex(19)->getAdj().size(), 3);
        EXPECT_EQ(graph.removeVertex(33), true);
        EXPECT_EQ(graph.removeVertex(33), false); // try removing a non-existing vertex
        EXPECT_EQ(graph.getVertexSet().size(), 3);
        EXPECT_EQ(graph.findVertex(18)->getAdj().size(), 0);
        EXPECT_EQ(graph.findVertex(19)->getAdj().size(), 2);
    }
    {
        IntroGraph graph;

        graph.addVertex(1);
        graph.addVertex(2);
        graph.addVertex(3);
        graph.addVertex(4);
        graph.addVertex(5);

        EXPECT_EQ(graph.addEdge(1,2,0), true);
        EXPECT_EQ(graph.addEdge(2,3,0), true);
        EXPECT_EQ(graph.addEdge(2,4,0), true);
        EXPECT_EQ(graph.addEdge(2,5,0), true);
        EXPECT_EQ(graph.addEdge(3,2,0), true);
        EXPECT_EQ(graph.addEdge(4,2,0), true);
        EXPECT_EQ(graph.addEdge(5,2,0), true);

        EXPECT_EQ(graph.removeEdge(1,2), true);
    }
}