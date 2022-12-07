#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <unordered_map>
#include <iterator>
#include <cmath>

using namespace std;

// Return the matching character between two strings
char findMatch(string s1, string s2, string s3) {
    for (char m: s1) {
        if (s2.find(m) != -1) {
            if (s3.find(m) != -1) {
                return m;
            }
        }
    }
    return 0;
}

int main() {
    string line;
    string line2;
    string line3;
    ifstream file;
    file.open("input/day3.txt");

    int sum = 0;
    while (getline(file, line)) {
        // Part 1
        // // 1. Split line into left and right halves
        // string left = line.substr(0, line.length()/2);
        // string right = line.substr(line.length()/2);
        // 2. Find common character between each half
        // char m = findMatch(left, right);

        // Part 2
        getline(file, line2);
        getline(file, line3);
        char m = findMatch(line, line2, line3);

        // 3. Convert character to priority value
        sum += (m >= 97) ? m - 96 : m - 38;
    }
    cout << sum << endl;
}
