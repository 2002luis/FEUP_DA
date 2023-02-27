// By: Gonçalo Leão

#ifndef DA_TP1_CLASSES_EXERCISES_H
#define DA_TP1_CLASSES_EXERCISES_H

#include "../data_structures/Graph.h"

#include <stack>

class IntroGraph: public Graph {
public:
    // Ex 1
    bool removeEdge(const int &source, const int &dest);
    bool removeVertex(const int &id);

    // Ex 2
    std::vector<int> dfs(const int & source) const;

    // Ex 3
    std::vector<int> bfs(const int & source) const;

    // Ex 4
    std::vector<int> topsort() const;

    // Ex 5
    bool isDAG() const;

    // Ex 6
    std::vector<std::vector<int>> computeSCCs() const;
protected:
    // TODO: Add auxiliary methods if needed
};

// Ex 8
std::vector<int> heapSort(std::vector<int> v);

// Ex 9
int kthSmallest(unsigned int k, std::vector<int> v);

#endif //DA_TP1_CLASSES_EXERCISES_H
