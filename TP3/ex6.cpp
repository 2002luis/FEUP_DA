// By: Gonçalo Leão

#include "exercises.h"

#include "MSTTestAux.h"
#include "../data_structures/UFDS.h"

std::vector<Vertex *> GreedyGraph::kruskal() {
    // TODO
    return vertexSet;
}

/// TESTS ///
#include <gtest/gtest.h>
#include <chrono>

TEST(TP3_Ex6, test_kruskal) {
    GreedyGraph graph = createMSTTestGraph();
    std::vector<Vertex *> res = graph.kruskal();

    std::stringstream ss;
    for(const auto v : res) {
        ss << v->getId() << "<-";
        if ( v->getPath() != nullptr ) {
            ss << v->getPath()->getOrig()->getId();
        }
        ss << "|";
    }
    std::cout << ss.str() << std::endl;

    EXPECT_TRUE(isSpanningTree(res));
    EXPECT_EQ(spanningTreeCost(res), 11);
}

TEST(TP3_Ex6, test_performance_kruskal) {
    //Change these const parameters as needed
    const int MIN_SIZE = 10;
    const int MAX_SIZE = 30; //Try with 100
    const int STEP_SIZE = 10;
    const int N_REPETITIONS = 50;
    for (int n = MIN_SIZE; n <= MAX_SIZE; n += STEP_SIZE) {
        GreedyGraph g;
        generateRandomGridGraph(n, g);
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 1; i <= N_REPETITIONS; i++)
            g.kruskal();
        auto finish = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
        std::cout << "Processing grid (Kruskal) " << n << " x " << n << " average time (milliseconds)=" << (elapsed / N_REPETITIONS) << std::endl;
    }
}
