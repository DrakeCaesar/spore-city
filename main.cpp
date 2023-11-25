#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include "Graph.h"

int main() {
    std::vector<std::tuple<std::string, std::string, std::vector<std::pair<int, int>>>> graphConfigurations;

    graphConfigurations.push_back(std::make_tuple(
        "Space Colony",
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
            {0, 1}, {0, 3}, {0, 6}, {0, 8}, {0, 10}, {1, 2},
            {1, 10}, {2, 3}, {2, 4}, {3, 4}, {4, 5}, {5, 6},
            {6, 7}, {5, 7}, {7, 8}, {8, 9}, {9, 10}, {10, 11}
        }
    ));

    graphConfigurations.push_back(std::make_tuple(
        "Economic 1",
        R"(placeholder)",
        std::vector<std::pair<int, int>>{
            {0, 1}, {0, 3}, {0, 4}, {0, 8}, {0, 9}, {1, 2},
            {1, 3}, {1, 11}, {2, 3}, {4, 5}, {5, 6}, {6, 7},
            {6, 8}, {7, 8}, {8, 9}, {9, 10}
        }
    ));
    graphConfigurations.push_back(std::make_tuple(
        "Economic 2",
        R"(placeholder)",
        std::vector<std::pair<int, int>>{
            {0, 1}, {0, 3}, {0, 5}, {0, 7}, {0, 8}, {0, 10},
            {1, 2}, {1, 3}, {1, 11}, {3, 4}, {4, 5}, {5, 6},
            {6, 7}, {7, 8}, {8, 9}, {8, 10}, {9, 10}
        }
    ));
    graphConfigurations.push_back(std::make_tuple(
        "Economic 3",
        R"(placeholder)",
        std::vector<std::pair<int, int>>{
            {0, 1}, {0, 7}, {0, 8}, {1, 2}, {1, 3}, {1, 11},
            {2, 3}, {3, 4}, {3, 7}, {4, 5}, {5, 6}, {5, 7},
            {6, 7}, {7, 8}, {8, 9}, {8, 10}, {9, 10},
        }
    ));

    graphConfigurations.push_back(std::make_tuple(
        "Military 1",
        R"(placeholder)",
        std::vector<std::pair<int, int>>{
            {0, 1}, {0, 2}, {0, 6}, {0, 7}, {1, 2}, {1, 11},
            {2, 4}, {2, 6}, {3, 4}, {4, 5}, {6, 7}, {7, 8},
            {7, 9}, {8, 9}, {9, 10}
        }
    ));
    graphConfigurations.push_back(std::make_tuple(
        "Military 2",
        R"(placeholder)",
        std::vector<std::pair<int, int>>{
            {0, 1}, {0, 2}, {0, 6}, {0, 9}, {1, 2}, {1, 3},
            {1, 9}, {1, 11}, {2, 4}, {3, 11}, {4, 5}, {5, 6},
            {6, 7}, {7, 8}, {9, 10}
        }
    ));
    graphConfigurations.push_back(std::make_tuple(
        "Military 3",
        R"(placeholder)",
        std::vector<std::pair<int, int>>{
            {0, 7}, {0, 9}, {1, 2}, {1, 11}, {2, 4}, {2, 6},
            {3, 4}, {5, 6}, {5, 7}, {6, 7}, {7, 9}, {8, 9},
            {9, 10}
        }
    ));

    graphConfigurations.push_back(std::make_tuple(
        "Religious 1",
        R"(placeholder)",
        std::vector<std::pair<int, int>>{
            {0, 1}, {0, 6}, {0, 7}, {0, 9}, {1, 2}, {1, 3},
            {1, 11}, {2, 3}, {2, 4}, {2, 6}, {4, 5}, {5, 7},
            {6, 7}, {7, 9}, {8, 9}, {9, 10}
        }
    ));
    graphConfigurations.push_back(std::make_tuple(
        "Religious 2",
        R"(placeholder)",
        std::vector<std::pair<int, int>>{
            {0, 1}, {0, 2}, {0, 5}, {0, 7}, {0, 9}, {1, 2},
            {1, 3}, {1, 11}, {2, 3}, {2, 4}, {2, 5}, {5, 6},
            {5, 7}, {6, 7}, {7, 9}, {8, 9}, {9, 10}
        }
    ));
    graphConfigurations.push_back(std::make_tuple(
        "Religious 3",
        R"(placeholder)",
        std::vector<std::pair<int, int>>{
            {0, 1}, {0, 2}, {0, 5}, {0, 7}, {0, 9}, {1, 2},
            {1, 3}, {1, 11}, {2, 4}, {2, 5}, {3, 4}, {4, 5},
            {5, 6}, {5, 7}, {6, 7}, {7, 8}, {7, 9}, {8, 9},
            {9, 11}
        }
    ));

    std::cout << "Name:\t\tH:\tP:\n";

    for (const auto&config: graphConfigurations) {
        Graph graph(std::get<0>(config), std::get<1>(config), std::get<2>(config));
        graph.findHighestProduction();
    }
    return 0;
}
