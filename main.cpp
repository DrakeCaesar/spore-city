#include <iostream>
#include <vector>
#include <array>
#include <string>

struct Node {
    int id;
    std::vector<int> neighbors; // Use integers to refer to other nodes by their ID
};

class Graph {
public:
    Graph() {
        // Define the connections based on the provided edges
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
        addEdge(5, 7);
        addEdge(7, 8);
        addEdge(8, 9);
        addEdge(9, 10);
        addEdge(10, 11);
    }

    void findHighestProduction() {
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

private:
    std::array<Node, 12> nodes;

    void addEdge(int from, int to) {
        nodes[from].neighbors.push_back(to);
        nodes[to].neighbors.push_back(from);
    }

    void generateStates(std::array<char, 12>&state, int nodeIndex, int&maxProduction, int&maxHappiness,
                        std::array<char, 12>&bestState) {
        if (nodeIndex == 12) {
            // All nodes have been assigned a state
            int production = calculateProduction(state);
            int happiness = calculateHappiness(state);
            if (production > maxProduction && happiness >= 1) {
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

    int calculateHappiness(const std::array<char, 12>&state) {
        int happiness = 0;
        for (int i = 0; i < 12; ++i) {
            if (state[i] == 'G') {
                happiness += 1; // Green building adds to happiness
                for (int neighbor: nodes[i].neighbors) {
                    if (state[neighbor] == 'Y') {
                        happiness += 1; // Green-yellow connection adds to happiness
                    }
                }
            }
            else if (state[i] == 'R') {
                happiness -= 1; // Red building subtracts from happiness
            }
        }
        return happiness;
    }

    int calculateProduction(const std::array<char, 12>&state) {
        int production = 0;
        for (int i = 0; i < 12; ++i) {
            if (state[i] == 'R') {
                for (int neighbor: nodes[i].neighbors) {
                    if (state[neighbor] == 'Y') {
                        production += 12; // Red-yellow connection adds 12 to production
                    }
                }
            }
        }
        return production;
    }

    void printLayout(const std::array<char, 12>&bestState, int happiness, int production) {
        std::string layout = R"(
      ({4})---({2})
      / \   / \
   ({5})   ({3})   ({1})   ({11})
    |\      \ /   \ /
    | ({6})---({0})---({10})
    |/      /    /
   ({7})---({8})---({9})
)";
        for (int i = 0; i < 12; ++i) {
            for (size_t pos = layout.find("{" + std::to_string(i) + "}"); pos != std::string::npos;
                 pos = layout.find("{" + std::to_string(i) + "}")) {
                layout.replace(pos, 3, std::string(1, bestState[i]));
            }
        }
        std::cout << "Layout Production: " << production << "\n";
        std::cout << "Layout Happiness: " << happiness << "\n";
        std::cout << layout;
    }
};

int main() {
    Graph g;
    g.findHighestProduction();
    return 0;
}
