// By: Gonçalo Leão

#include "exercises.h"

#include "TestAux.h"

void DPGraph::bellmanFord(const int &origin) {
    // TODO
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP5_Ex11, test_bellmanFord) {
    DPGraph myGraph = CreateTestGraph();

    myGraph.bellmanFord(3);
    checkAllPaths(myGraph, "1<-3|2<-1|3<-|4<-2|5<-4|6<-3|7<-5|");

    myGraph.bellmanFord(1);
    checkSinglePath(myGraph.getPath(1, 7), "1 2 4 5 7 ");

    myGraph.bellmanFord(5);
    checkSinglePath(myGraph.getPath(5, 6), "5 7 6 ");

    myGraph.bellmanFord(7);
    checkSinglePath(myGraph.getPath(7, 1), "7 6 4 3 1 ");
}