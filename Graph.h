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
    Graph(const std::string&name, const std::string&layout, const std::vector<std::pair<int, int>>&edges);

    void findHighestProduction();

    std::string name;
    std::string layout;
    int maxHappiness = -1000;
    int maxProduction = 0;

    std::array<char, 12> bestState;


    void printLayout(const std::array<char, 12>&bestState, int happiness, int production, bool graph = false);

private:
    std::vector<std::pair<int, int>> edges;
    std::array<Node, 12> nodes;

    void addEdge(int u, int v);

    void generateStates(std::array<char, 12>&state, int nodeIndex, int&maxProduction, int&maxHappiness,
                        std::array<char, 12>&bestState);

    int calculateHappiness(const std::array<char, 12>&state);

    int calculateProduction(const std::array<char, 12>&state);

    void replaceAll(std::string&str, const std::string&from, const std::string&to);
};


#endif //GRAPH_H
