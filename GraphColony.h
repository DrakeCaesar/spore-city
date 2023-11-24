//
// Created by domin on 25-Nov-23.
//

#ifndef GRAPHCOLONY_H
#define GRAPHCOLONY_H

#include "Graph.h"

class GraphColony : public Graph {
public:
    GraphColony() {
        layout = R"(
      ({4})---({2})
      / \   / \
   ({5})   ({3})   ({1})   ({11})
    |\      \ /   \ /
    | ({6})---({0})---({10})
    |/      /    /
   ({7})---({8})---({9})
)";
        addEdge(0, 1);
        addEdge(0, 3);
        addEdge(0, 6);
        addEdge(0, 8);
        addEdge(0, 10);
        addEdge(1, 2);
        addEdge(1, 10);
        addEdge(2, 3);
        addEdge(2, 4);
        addEdge(3, 4);
        addEdge(4, 5);
        addEdge(5, 6);
        addEdge(6, 7);
        addEdge(5, 7);
        addEdge(7, 8);
        addEdge(8, 9);
        addEdge(9, 10);
        addEdge(10, 11);
    }
};


#endif //GRAPHCOLONY_H
