//
// Created by Kevin Lavery on 2020-12-02.
//
#include <fstream>
#include <iostream>
#include <sstream>

int main(int argc, char** argv) {
    size_t validPass{}, first{}, second{}, count{};
    std::string line{}, temp{};
    char criteria{};
    bool foundCriteria = false;
    std::ifstream file("input.txt");

    while (file) {
        // get line of pass and criteria
        std::getline(file, line);
        // turn line into stream
        std::stringstream lStream(line);
        // get lower character limit
        getline(lStream, temp, '-');
        first = stoi(temp);
        // get upper character limit
        getline(lStream, temp, ' ');
        second = stoi(temp);
        // get character required in password
        criteria = lStream.get();
        lStream.get();
        lStream.get();
        // check password for number of specified character
        while (lStream) {
            count++;
            if (lStream.get() == criteria && (count == first || count == second)) {
                if (!foundCriteria) {
                    validPass++;
                    foundCriteria = true;
                } else {
                    validPass--;
                }
            }
        }
        foundCriteria = false;
        count = 0;
    }

    std::cout << validPass << "\n";

    return 0;
}