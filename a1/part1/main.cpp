//
// Created by Kevin Lavery on 2020-12-01.
//
#include <iostream>
#include <set>
#include <vector>
#include <fstream>

const int year = 2020;
int multiSum(const std::vector<int>& expenseReport) {
    size_t result = 0;

    std::set<size_t> processed;
    for (int report : expenseReport) {
        if (processed.find(report) == processed.end())
            processed.insert(report);

        if (processed.find(year - report) != processed.end())
            result = report * (year - report);
    }

    return result;
}

int main(int argc, char** argv) {
    std::vector<int> expenseReport;
    std::string line;

    std::ifstream file("input.txt");
    while (file) {
        std::getline(file, line);
        expenseReport.push_back(stoi(line));
    }

    std::cout << "The two entries that sum to 2020 multiply to: " << multiSum(expenseReport) << "\n";

    return 0;
}