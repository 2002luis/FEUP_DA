#include "exercises.h"

void GreedyGraph::edmondsKarp(int source, int target) {
    auto src = this->findVertex(source);
    auto dest = this->findVertex(target);
    if(dest == nullptr || src == nullptr) return;

    for(auto &i : this->vertexSet) for(auto &j : i->getAdj()) j->setFlow(0.0);


}

void GreedyGraph::bfs(Vertex* src, Vertex* dest){
    for(auto &i : this->vertexSet)
    {
        i->setVisited(false);
        i->setPath(nullptr);
    }

    std::queue<std::vector<std::pair<Vertex*,Edge*>>> q;
    q.push({{src, nullptr}});
    src->setVisited(true);
    while(!q.empty()){
        auto front = q.front();
        if(front.back().first==dest){
            for(unsigned long int i = 0; i < front.size(); i++){
                front[i].first->setPath(front[i].second);
            }
            return;
        }
        for(auto &i : front.back().first->getAdj()){
            if(!i->getDest()->isVisited()){
                auto temp = front;
                temp.back().second = i;
                temp.push_back({i->getDest(), nullptr});
                q.push(temp);
            }
        }
        q.pop();
    }

    return;
}

double GreedyGraph::findMinResidual(std::vector<Vertex*> path){
    double out = INT_MAX;
    for(auto i : path){
        out = std::min(out,i->getPath()->getWeight()-i->getPath()->getFlow());
    }
    return out;
}

void GreedyGraph::augmentFlow(std::vector<Vertex*> path, double n){
    for (auto &i : path){
        i->getPath()->setFlow(i->getPath()->getFlow()+n);
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
