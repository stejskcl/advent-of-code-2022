#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <unordered_map>
#include <iterator>
#include <cmath>

using namespace std;
using intvec = vector<int>;
using intgrid = vector<vector<int>>;

// Returns the visibility score for the specified row and column
int isVisible(int row, int col, intgrid grid) {
    int tree = grid[row][col];
    intvec ret = {0,0,0,0};
    for (int i = col-1; i >=0; i--) {
        ret[0]++;
        if (grid[row][i] >= tree) { break; }
    }
    for (int i = col+1; i < grid[row].size(); i++) {
        ret[1]++;
        if (grid[row][i] >= tree) { break; }
    }
    for (int i = row-1; i >= 0; i--) {
        ret[2]++;
        if (grid[i][col] >= tree) { break; }
    }
    for (int i = row+1; i < grid.size(); i++) {
        ret[3]++;
        if (grid[i][col] >= tree) { break; }
    }
    return ret[0] * ret[1] * ret[2] * ret[3];
}

// Finds the max visibility score in grid
int procGrid(intgrid grid) {
    int max = 0;
    for (size_t row = 0; row < grid.size(); row++) {
        for (size_t col = 0; col < grid[row].size(); col++) {
            int s = (isVisible(row, col, grid));
            max = std::max(s, max);
        }
    }
    return max;
}

int main() {
    string line;
    ifstream file;
    file.open("input/day8.txt");
    intgrid grid;
    while (getline(file, line)) {
        vector<int> v;
        for (size_t i = 0; i < line.length(); i++) {
            int c = stoi(line.substr(i,1));
            v.push_back(c);
        }
        grid.push_back(v);
    }
    int ret = procGrid(grid);
    cout << ret << endl;
}
