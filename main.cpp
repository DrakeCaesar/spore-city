#include <vector>
#include <string>
#include <tuple>
#include "Graph.h"

int main() {
    std::vector<std::tuple<std::string, std::string, std::vector<std::pair<int, int>>>> graphConfigurations;

    graphConfigurations.push_back(std::make_tuple(
        "Colony",
        R"(
          (4)---(2)
          / \   / \
       (5)   (3)   (1)   (B)
        | \     \ /   \ /
        | (6)---(0)---(A)
        | /     /     /
       (7)---(8)---(9)
        )",
        std::vector<std::pair<int, int>>{
            {0, 1}, {0, 3}, {0, 6}, {0, 8}, {0, 10}, {1, 2}, {1, 10},
            {2, 3}, {2, 4}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {5, 7},
            {7, 8}, {8, 9}, {9, 10}, {10, 11}
        }
    ));

    // Add more graph configurations as needed...

    for (const auto&config: graphConfigurations) {
        Graph graph(std::get<0>(config), std::get<1>(config), std::get<2>(config));
        graph.findHighestProduction();
    }
    return 0;
}
