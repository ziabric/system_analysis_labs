#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>

std::unordered_map<int, std::vector<int>> children, parents;
std::vector<int> knots = {};
int allParents = 0;
int allChildren = 0;
int parentChildren = 0;


void findParent(int currentKnot)
{
    allParents += parents[currentKnot].size();
    for (auto item : parents[currentKnot])
    {
        findParent(item);
    }
}

void findChildren(int currentKnot)
{
    allChildren += children[currentKnot].size();
    for (auto item : children[currentKnot])
    {
        findChildren(item);
    }
}

std::string processGraphCSV(const std::string& csv) {
    children.clear(); 
    parents.clear();
    knots.clear();

    std::istringstream ss(csv);
    std::string token;
    while (std::getline(ss, token)) {
        std::stringstream lineSS(token);
        std::string parent, child;
        getline(lineSS, parent, ',');
        getline(lineSS, child, '\n');
        int parentID = std::stoi(parent);
        int childID = std::stoi(child);

        children[parentID].push_back(childID);
        parents[childID].push_back(parentID);

        if ( std::find(knots.begin(), knots.end(), parentID) == knots.end() )
        {
            knots.push_back(parentID);
        }
        if ( std::find(knots.begin(), knots.end(), childID) == knots.end() )
        {
            knots.push_back(childID);
        }
    }
    std::sort(knots.begin(), knots.end());

    std::vector<std::vector<int>> result;

    for (const auto& node : knots) 
    {
        int nodeID = node;
        std::vector<int> nodeData;

        nodeData.push_back(children[nodeID].size()); 
        nodeData.push_back(parents[nodeID].size());  

        allChildren = 0;
        allParents = 0;
        parentChildren = 0;

        for (auto item : children[nodeID])
        {
            findChildren(item);
        }
        nodeData.push_back(allChildren);

        for (auto item : parents[nodeID])
        {
            findParent(item);
        }
        nodeData.push_back(allParents);

        for (auto parent : parents[nodeID])
        {
            parentChildren += children[parent].size();
        }
        nodeData.push_back(parentChildren == 0 ? 0 : parentChildren - 1);

        result.push_back(nodeData);
    }

    std::string output = "";

    for (const auto& node : result) 
    {
        for (int val : node) {
            output += std::to_string(val);
            output += ',';
        }
        output[output.size() - 1] = '\n';
    }

    return output; 
}