//
// Created by domin on 25-Nov-23.
//

#ifndef GRAPH_H
#define GRAPH_H
#include <array>
#include <string>
#include <vector>


struct Node {
    int id;
    std::vector<int> neighbors; // Use integers to refer to other nodes by their ID
};

class Graph {
public:
    Graph(const std::string&layout, const std::vector<std::pair<int, int>>&edges);

    void findHighestProduction();

private:
    std::string layout;
    std::vector<std::pair<int, int>> edges;
    std::array<Node, 12> nodes;

    void addEdge(int u, int v);

    void generateStates(std::array<char, 12>&state, int nodeIndex, int&maxProduction, int&maxHappiness,
                        std::array<char, 12>&bestState);

    int calculateHappiness(const std::array<char, 12>&state);

    int calculateProduction(const std::array<char, 12>&state);

    void replaceAll(std::string&str, const std::string&from, const std::string&to);

    void printLayout(const std::array<char, 12>&bestState, int happiness, int production);
};


#endif //GRAPH_H
