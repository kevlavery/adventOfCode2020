//
// Created by Kevin Lavery on 2020-12-02.
//
#include <fstream>
#include <iostream>
#include <sstream>

int main(int argc, char** argv) {
    size_t validPass{}, goodChar{}, upper{}, lower{};
    std::string line{}, temp{};
    char current{}, criteria{};
    std::ifstream file("input.txt");

    while (file) {
        // get line of pass and criteria
        std::getline(file, line);
        // turn line into stream
        std::stringstream lStream(line);
        // get lower character limit
        getline(lStream, temp, '-');
        lower = stoi(temp);
        // get upper character limit
        getline(lStream, temp, ' ');
        upper = stoi(temp);
        // get character required in password
        criteria = lStream.get();

        // check password for number of specified character
        while (lStream) {
            if (lStream.get() == criteria) goodChar++;
        }
        if ( goodChar >= lower && goodChar <= upper) validPass++;
        goodChar = 0;
    }

    std::cout << validPass << "\n";

    return 0;
}