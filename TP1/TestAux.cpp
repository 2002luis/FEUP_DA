#include "TestAux.h"

void createNetwork(IntroGraph &graph) {
    for(unsigned int i = 1; i <= 7; i++) {
        graph.addVertex(i);
    }

    graph.addEdge(1,2,0);
    graph.addEdge(1,3,0);
    graph.addEdge(1,4,0);
    graph.addEdge(2,5,0);
    graph.addEdge(5,6,0);
    graph.addEdge(5,1,0);
    graph.addEdge(3,6,0);
    graph.addEdge(3,7,0);
    graph.addEdge(6,2,0);
}