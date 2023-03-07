#include "exercises.h"

void GreedyGraph::edmondsKarp(int source, int target) {
    for (Vertex* v : vertexSet){
        for (Edge* e : v->getAdj())
            e->setFlow(0);
    }

    Vertex* src = findVertex(source);
    Vertex* sink = findVertex(target);

    // BFS
    while (true){
        for (Vertex* v : vertexSet)
            v->setPath(nullptr);

        std::queue<Vertex*> q;
        q.push(src);

        while (!q.empty()){
            Vertex* curr = q.front();
            q.pop();

            if (curr->getId() == target) break; // target found

            // edges
            for (Edge* e : curr->getAdj()){
                Vertex* next = e->getDest();
                if (next->getPath() != nullptr || e->getFlow() >= e->getWeight() || next->getId() == source)
                    continue;

                q.push(next);
                next->setPath(e);
            }

            // reverse edges
            for (Edge* e : curr->getIncoming()){
                Vertex* next = e->getOrig();
                if (next->getPath() != nullptr || e->getFlow() <= 0 || next->getId() == source)
                    continue;

                q.push(next);
                next->setPath(e);
            }
        }

        if (sink->getPath() == nullptr) break;

        // augment path
        double pathFlow = INF;

        Vertex* currSink = sink;
        for (Edge* e = currSink->getPath(); e != nullptr; e = currSink->getPath()){
            if (e->getDest() == currSink){
                pathFlow = std::min(pathFlow, e->getWeight() - e->getFlow());
                currSink = e->getOrig();

                continue;
            }

            pathFlow = std::min(pathFlow, e->getFlow());
            currSink = e->getDest();
        }

        currSink = sink;
        for (Edge* e = currSink->getPath(); e != nullptr; e = currSink->getPath()){
            if (e->getDest() == currSink){
                e->setFlow(e->getFlow() + pathFlow); currSink = e->getOrig();

                continue;
            }

            e->setFlow(e->getFlow() - pathFlow); currSink = e->getDest();
        }
    }
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP3_Ex7, test_edmondsKarp) {
    GreedyGraph myGraph;

    for(int i = 1; i <= 6; i++)
        myGraph.addVertex(i);

    myGraph.addEdge(1, 2, 3);
    myGraph.addEdge(1, 3, 2);
    myGraph.addEdge(2, 5, 4);
    myGraph.addEdge(2, 4, 3);
    myGraph.addEdge(2, 3, 1);
    myGraph.addEdge(3, 5, 2);
    myGraph.addEdge(4, 6, 2);
    myGraph.addEdge(5, 6, 3);

    myGraph.edmondsKarp(1, 6);

    std::stringstream ss;
    for(auto v : myGraph.getVertexSet()) {
        ss << v->getId() << "-> (";
        for (const auto e : v->getAdj())
            ss << (e->getDest())->getId() << "[Flow: " << e->getFlow() << "] ";
        ss << ") || ";
    }

    std::cout << ss.str() << std::endl << std::endl;

    EXPECT_EQ("1-> (2[Flow: 3] 3[Flow: 2] ) || 2-> (5[Flow: 1] 4[Flow: 2] 3[Flow: 0] ) || 3-> (5[Flow: 2] ) || 4-> (6[Flow: 2] ) || 5-> (6[Flow: 3] ) || 6-> () || ", ss.str());
}
