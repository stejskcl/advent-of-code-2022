#!/bin/bash

# opens link in default browser
open "https://adventofcode.com/2022/day/$1"
open "https://adventofcode.com/2022/day/$1/input"

# initialize cpp file
echo "#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <unordered_map>
#include <iterator>
#include <cmath>

using namespace std;

int main() {
    string line;
    ifstream file;
    file.open(\"day$1.txt\");
    while (getline(file, line)) {
        cout << line << endl;
    }
}" >> "day$1.cpp"

# open files in visual studio
touch "input/day$1.txt"
open "input/day$1.txt" -a "Visual Studio Code 2"
open "day$1.cpp" -a "Visual Studio Code 2"

