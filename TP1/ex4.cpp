// By: Gonçalo Leão

#include "exercises.h"

std::vector<int> IntroGraph::topsort() const {
    std::vector<int> res;
    // TODO
    return res;
}

/// TESTS ///
#include <gtest/gtest.h>

void expectTopSort(const IntroGraph graph, std::vector<int> topOrder){
    for(auto u: graph.getVertexSet()) {
        auto itrU = std::find(topOrder.begin(), topOrder.end(), u->getId());
        unsigned int indexU = std::distance(topOrder.begin(), itrU);
        for(auto edge: u->getAdj()) {
            auto v = edge->getDest();
            auto itrV = std::find(topOrder.begin(), topOrder.end(), v->getId());
            unsigned int indexV = std::distance(topOrder.begin(), itrV);
            EXPECT_LT(indexU,indexV);
        }
    }
}

TEST(TP1_Ex4, test_topsort) {
    IntroGraph myGraph;
    myGraph.addVertex(1); myGraph.addVertex(2); myGraph.addVertex(3); myGraph.addVertex(4);
    myGraph.addVertex(5); myGraph.addVertex(6); myGraph.addVertex(7);

    myGraph.addEdge(1, 2, 0);
    myGraph.addEdge(1, 4, 0);
    myGraph.addEdge(1, 3, 0);
    myGraph.addEdge(2, 5, 0);
    myGraph.addEdge(2, 4, 0);
    myGraph.addEdge(3, 6, 0);
    myGraph.addEdge(4, 3, 0);
    myGraph.addEdge(4, 6, 0);
    myGraph.addEdge(4, 7, 0);
    myGraph.addEdge(5, 4, 0);
    myGraph.addEdge(5, 7, 0);
    myGraph.addEdge(7, 6, 0);

    std::vector<int> topOrder = myGraph.topsort();
    EXPECT_EQ(topOrder.size(), 7);
    expectTopSort(myGraph, topOrder); // example of two valid topsorts: "1 2 5 4 3 7 6" and "1 2 5 4 7 3 6"

    // to test including a cycle in the graph
    myGraph.addEdge(3, 1, 0);

    topOrder = myGraph.topsort();
    EXPECT_EQ(topOrder.size(), 0);
}