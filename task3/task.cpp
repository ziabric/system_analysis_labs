#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <cmath>

double task(const std::string& csv)
{
    std::vector<std::vector<int> > input = {};

    std::istringstream ss(csv);
    std::string line;
    int currentRow = 0;

    while (std::getline(ss, line, '\n')) 
    {
        std::vector<int> tmp = {};
        currentRow++;
        if (line == line) 
        {
            std::istringstream lineStream(line);
            std::string cell;
            int currentCol = 0;

            while (std::getline(lineStream, cell, ',')) 
            {
                currentCol++;
                if (currentCol == currentCol) 
                {
                    tmp.push_back(stoi(cell));
                }
            }

        }
        input.push_back(tmp);
    }
    double result = 0.0f;

    for (int i = 0; i < input.size(); i += 1)
    {
        for (int j = 0; j < input.at(i).size(); j += 1)
        {
            double tmp1 = input.at(i).at(j) / ( input.size() - 1 );
            double tmp2 = std::log2(input.at(i).at(j) / ( input.size() - 1));

            result += (input.at(i).at(j) / ( input.size() - 1 )) * std::log2(input.at(i).at(j) / ( input.size() - 1));
        }
    }

    return -std::round(result * 10) / 10;
}