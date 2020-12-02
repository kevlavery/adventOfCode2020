//
// Created by Kevin Lavery on 2020-12-01.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <set>

const int year = 2020;

int sum3Multi(std::vector<int> &expenseReport) {
    int result = 0;

    for (size_t i = 0; i < expenseReport.size(); ++i) {
        for (size_t j = 0; j < expenseReport.size(); ++j) {
            for (size_t k = 0; k < expenseReport.size(); ++k) {
                if (expenseReport[i] + expenseReport[j] + expenseReport[k] == year)
                    result = expenseReport[i] * expenseReport[j] * expenseReport[k];
            }
        }
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

    std::cout << sum3Multi(expenseReport) << "\n";

    return 0;
}