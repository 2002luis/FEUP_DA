#include "MSTTestAux.h"

#include <random>
#include <map>
#include <set>

GreedyGraph createMSTTestGraph() {
    GreedyGraph myGraph;

    for(int i = 1; i <= 7; i++)
        myGraph.addVertex(i);

    myGraph.addBidirectionalEdge(1, 2, 2);
    myGraph.addBidirectionalEdge(1, 4, 7);
    myGraph.addBidirectionalEdge(2, 4, 3);
    myGraph.addBidirectionalEdge(2, 5, 5);
    myGraph.addBidirectionalEdge(3, 1, 2);
    myGraph.addBidirectionalEdge(3, 6, 5);
    myGraph.addBidirectionalEdge(4, 3, 1);
    myGraph.addBidirectionalEdge(4, 5, 1);
    myGraph.addBidirectionalEdge(4, 7, 4);
    myGraph.addBidirectionalEdge(5, 7, 2);
    myGraph.addBidirectionalEdge(6, 4, 3);
    myGraph.addBidirectionalEdge(7, 6, 4);

    return myGraph;
}

void generateRandomGridGraph(int n, GreedyGraph & g) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g.addVertex(i*n + j);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (i < n-1)
                g.addBidirectionalEdge(i*n + j, (i+1)*n + j, dis(gen));
            if (j < n-1)
                g.addBidirectionalEdge(i*n + j, i*n + (j+1), dis(gen));
        }
}

bool isSpanningTree(const std::vector<Vertex *> &res){
    std::map<int, std::set<int> > adj;
    for(const Vertex *v: res) {
        adj[v->getId()];
        if (v->getPath() != nullptr) {
            Vertex *u = v->getPath()->getOrig();
            adj[u->getId()].emplace(v->getId());
            adj[v->getId()].emplace(u->getId());
        }
    }

    std::queue<int> q;
    std::set<int> visited;
    q.push(res.at(0)->getId());
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(visited.count(u)) continue;
        visited.emplace(u);
        for(const int &v: adj.at(u)){
            q.emplace(v);
        }
    }

    for(const Vertex *v: res)
        if(!visited.count(v->getId())) return false;
    return true;
}

double spanningTreeCost(const std::vector<Vertex *> &res){
    double ret = 0;
    for(const Vertex *v: res){
        if(v->getPath() == nullptr) continue;
        const Vertex *u = v->getPath()->getOrig();
        for(const auto e: u->getAdj()){
            if(e->getDest()->getId() == v->getId()){
                ret += e->getWeight();
                break;
            }
        }
    }
    return ret;
}

