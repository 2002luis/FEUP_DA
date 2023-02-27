// By: Gonçalo Leão

#include "exercises.h"

#include "TestAux.h"

bool DPGraph::relax(Edge *edge) {
    // TODO
    return false;
}

void DPGraph::dijkstra(const int &origin) {
    // TODO
}

std::vector<int> DPGraph::getPath(const int &origin, const int &dest) const{
    std::vector<int> res;
    // TODO
    return res;
}

/// TESTS ///
#include <gtest/gtest.h>
#include <chrono>

void testPerformanceDijkstra() {
    //Change these const parameters as needed
    for (int n = 10; n <= 100; n += 10) {
        DPGraph g;
        std::cout << "Dijkstra generating grid " << n << " x " << n << " ..." << std::endl;
        generateRandomGridGraph(n, g);
        std:: cout << "Dijkstra processing grid " << n << " x " << n << " ..." << std::endl;
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                g.dijkstra(i*n + j);
        auto finish = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(finish - start).count();
        std::cout << "Dijkstra processing grid " << n << " x " << n << " average time (micro-seconds)=" << (elapsed / (n*n)) << std::endl;
    }
}

TEST(TP5_Ex10, test_dijkstra) {
    DPGraph myGraph = CreateTestGraph();

    myGraph.dijkstra(3);
    checkAllPaths(myGraph, "1<-3|2<-1|3<-|4<-2|5<-4|6<-3|7<-5|");

    myGraph.dijkstra(1);
    checkAllPaths(myGraph, "1<-|2<-1|3<-4|4<-2|5<-4|6<-4|7<-5|");
    checkSinglePath(myGraph.getPath(1, 7), "1 2 4 5 7 ");

    myGraph.dijkstra(5);
    checkSinglePath(myGraph.getPath(5, 6), "5 7 6 ");

    myGraph.dijkstra(7);
    checkSinglePath(myGraph.getPath(7, 1), "7 6 4 3 1 ");

    // Uncomment the next line to perform the execution time tests
    //testPerformanceDijkstra();
}