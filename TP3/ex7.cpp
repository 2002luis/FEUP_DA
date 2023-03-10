#include "exercises.h"

void GreedyGraph::edmondsKarp(int source, int target) {
    for (Vertex* v : vertexSet){
        for (Edge* e : v->getAdj())
            e->setFlow(0);
    }

    Vertex* src = findVertex(source);
    Vertex* sink = findVertex(target);


    // BFS
    do {
        for (Vertex* v : vertexSet) v->setPath(nullptr);

        std::queue<Vertex*> q;
        q.push(src);

        while(!q.empty() && q.front()->getId()!=target){
            Vertex* cur = q.front();
            q.pop();

            for(Edge* i : cur->getAdj()){
                Vertex* next = i->getDest();
                if(next->getPath() == nullptr && i->getFlow()<i->getWeight() && next->getId()!=source){
                    q.push(next);
                    next->setPath(i);
                }
            }

            for(Edge* i : cur->getIncoming()){
                Vertex* next = i->getDest();
                if(next->getPath() == nullptr && i->getFlow()>0 && next->getId() != source){
                    q.push(next);
                    next->setPath(i);
                }
            }
        }

        if(sink->getPath() != nullptr){
            double flow = INF;

            Vertex* currSink = sink;
            for(Edge* e = currSink->getPath(); e != nullptr; e = currSink->getPath()){
                if(e->getDest() == currSink){
                    flow = std::min(flow,e->getWeight() - e->getFlow());
                    currSink = e->getOrig();
                }
                else{
                    flow=std::min(flow,e->getFlow());
                    currSink = e->getDest();
                }
            }

            for(Edge* e = currSink->getPath(); e != nullptr; e = currSink->getPath()){
                if(e->getDest() == currSink) {
                    e->setFlow(e->getFlow() + flow);
                    currSink = e->getOrig();
                }
                else {
                    e->setFlow(e->getFlow()-flow);
                    currSink = e->getDest();
                }
            }
        }
    } while (sink->getPath() != nullptr);
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
