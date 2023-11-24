//
// Created by domin on 25-Nov-23.
//

#include "Graph.h"

#include <iostream>


Graph::Graph() {
}

void Graph::findHighestProduction() {
    std::array<char, 12> state;
    state.fill('Y'); // Initial state is all yellow
    state[0] = 'Y'; // Center node is always yellow

    int maxProduction = 0;
    int maxHappiness = 0;
    std::array<char, 12> bestState;

    // Call recursive function to generate all states and calculate production
    generateStates(state, 1, maxProduction, maxHappiness, bestState);

    // Output the best state found and print the layout
    // std::cout << "Max Production: " << maxProduction << "\n";
    // std::cout << "Max Happiness: " << maxHappiness << "\n";
    printLayout(bestState, maxHappiness, maxProduction);
}


std::array<Node, 12> nodes;

void Graph::addEdge(int from, int to) {
    nodes[from].neighbors.push_back(to);
    nodes[to].neighbors.push_back(from);
}

void Graph::generateStates(std::array<char, 12>&state, int nodeIndex, int&maxProduction, int&maxHappiness,
                           std::array<char, 12>&bestState) {
    if (nodeIndex == 12) {
        // All nodes have been assigned a state
        int production = calculateProduction(state);
        int happiness = calculateHappiness(state);
        if (production > maxProduction && happiness >= 2) {
            maxProduction = production;
            maxHappiness = happiness;
            bestState = state;
        }
        return;
    }

    if (nodeIndex == 0) {
        // Skip the center node
        generateStates(state, nodeIndex + 1, maxProduction, maxHappiness, bestState);
    }
    else {
        // Generate states for this node
        const char types[3] = {'G', 'R', 'Y'};
        for (char type: types) {
            state[nodeIndex] = type;
            generateStates(state, nodeIndex + 1, maxProduction, maxHappiness, bestState);
        }
    }
}

int Graph::calculateHappiness(const std::array<char, 12>&state) {
    int happiness = 0;
    for (int i = 0; i < 12; ++i) {
        if (state[i] == 'G') {
            happiness += 1; // Green building adds to happiness
            for (int neighbor: nodes[i].neighbors) {
                if (state[neighbor] == 'Y') {
                    happiness += 1; // Green-yellow connection adds to happiness
                }
                if (state[neighbor] == 'R') {
                    happiness -= 1; // Red-green connection subtracts from happiness
                }
            }
        }
        else if (state[i] == 'R') {
            happiness -= 1; // Red building subtracts from happiness
            for (int neighbor: nodes[i].neighbors) {
                if (state[neighbor] == 'G') {
                    happiness -= 1; // Red-green connection subtracts from happiness
                }
            }
        }
    }
    return happiness;
}


int Graph::calculateProduction(const std::array<char, 12>&state) {
    int production = 0;
    for (int i = 0; i < 12; ++i) {
        if (state[i] == 'R') {
            for (int neighbor: nodes[i].neighbors) {
                if (state[neighbor] == 'Y') {
                    production += 18; // Red-yellow connection adds 12 to production
                }
            }
        }
    }
    return production;
}

void Graph::replaceAll(std::string&str, const std::string&from, const std::string&to) {
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
}


void Graph::printLayout(const std::array<char, 12>&bestState, int happiness, int production) {
    // ANSI color codes
    const std::string red("\033[31m"), green("\033[32m"), yellow("\033[33m"), reset("\033[0m");

    replaceAll(layout, "A", "10");
    replaceAll(layout, "B", "11");

    for (int i = 0; i < 12; ++i) {
        std::string colorCode;
        switch (bestState[i]) {
            case 'R': colorCode = red;
                break;
            case 'G': colorCode = green;
                break;
            case 'Y': colorCode = reset;
                break;
            default: colorCode = reset;
                break;
        }
        std::string coloredLetter = colorCode + (i == 0 ? 'C' : bestState[i]) + reset;
        std::string placeholder = "(" + std::to_string(i) + ")";
        size_t placeholderLength = placeholder.length();
        for (size_t pos = layout.find(placeholder); pos != std::string::npos; pos = layout.find(placeholder, pos)) {
            layout.replace(pos, placeholderLength, "(" + coloredLetter + ")");
        }
    }
    replaceAll(layout, "Y", "H");
    replaceAll(layout, "R", "F");
    replaceAll(layout, "G", "E");
    std::cout << "Layout Happiness: " << happiness << "\n";
    std::cout << "Layout Production: " << production << "\n";
    std::cout << layout;
}
