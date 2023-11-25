#include <vector>
#include <string>

#include "Graph.h"

int main() {
    std::vector<std::pair<std::string, std::vector<std::pair<int, int>>>> graphConfigurations;
    graphConfigurations.push_back({
        R"(
      (4)---(2)
      / \   / \
   (5)   (3)   (1)   (B)
    | \     \ /   \ /
    | (6)---(0)---(A)
    | /     /     /
   (7)---(8)---(9)
)",
        {
            {0, 1}, {0, 3}, {0, 6}, {0, 8}, {0, 10}, {1, 2}, {1, 10},
            {2, 3}, {2, 4}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {5, 7},
            {7, 8}, {8, 9}, {9, 10}, {10, 11}
        }

    });

    for (const auto&config: graphConfigurations) {
        Graph graph(config.first, config.second);
        graph.findHighestProduction();
    }
    return 0;
}
