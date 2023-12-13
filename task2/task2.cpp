#pragma once
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

std::vector<std::vector<int>> parseGraph(const std::string& csv, int& maxNode) {
    std::vector<std::vector<int>> graph;
    std::stringstream ss(csv);
    std::string line;
    maxNode = 0;

    while (std::getline(ss, line)) {
        std::stringstream lineStream(line);
        int parent, child;
        lineStream >> parent;
        lineStream.ignore(1);
        lineStream >> child;

        maxNode = std::max(maxNode, std::max(parent, child));

        while (graph.size() <= maxNode) {
            graph.push_back(std::vector<int>());
        }

        graph[parent].push_back(child);
    }
    return graph;
}

std::vector<std::vector<int>> computeParents(const std::vector<std::vector<int>>& graph, int maxNode) {
    std::vector<std::vector<int>> parents(maxNode + 1);

    for (int i = 0; i < graph.size(); ++i) {
        for (int child : graph[i]) {
            parents[child].push_back(i);
        }
    }

    return parents;
}

std::string task(const std::string &csv)
{
    int maxNode;
    auto graph = parseGraph(csv, maxNode);
    auto parents = computeParents(graph, maxNode);

    std::vec
    for (int i = 0; i < maxNode; i += 1)
    {

    }
}