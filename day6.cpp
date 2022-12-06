#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Returns true if every character in a vector is unique
bool isUnique(vector<char> vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec.size(); j++) {
            if (i == j) {  // don't check a char to itself
                break;
            }
            if (vec[i] == vec[j]) {
                return false;
            }
        }
    }
    return true;  // if we make it here, all chars are unique
}

// parses through a string and returns the first position
// of a unique series of characters of given size
int parseInput(string line, int size) {
  vector<char> vec;
  for (int i = 0; i < line.length(); i++) {
    vec.push_back(line.at(i));
    if (vec.size() > size) {
        vec.erase(vec.begin());
    }
    if (vec.size() == size && isUnique(vec)) {
        return i + 1;
    }
  }
  return 0;
}

int main() {
    string line;
    ifstream file;
    file.open("input/day6.txt");
    getline(file, line);
    //int size = 4;  // part 1
    int size = 14;  // part 2
    cout << parseInput(line, size) << endl;
}
