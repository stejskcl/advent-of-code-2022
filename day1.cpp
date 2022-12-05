#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <unordered_map>
#include <iterator>
#include <cmath>

using namespace std;

void updateMax(vector<int>& max, int cals) {
    max.push_back(cals);
    sort(max.begin(), max.end(), greater<int>());
    if (max.size() > 3) {
        max.pop_back();
    }    
}

int main() {
    string line;
    ifstream file;
    file.open("input/day1.txt");

    vector<int> max;
    int calories = 0;
    while (getline(file, line)) {
        if (line == "") {
            updateMax(max, calories);
            calories = 0;
        } else {
            calories += stoi(line);
        }
    }
    cout << max[0] + max[1] + max[2] << endl;
}