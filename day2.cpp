#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <unordered_map>
#include <iterator>
#include <cmath>

using namespace std;

int mod(int a, int n) {
    int q = (int)floor((double)a / n);

	// Return the resultant remainder
	return a - n * q;
}

int pointsFromOutcome(int oppInt, int meInt) {
    int dif = (oppInt - meInt) % 3;
    cout << dif << endl;
    return dif * 3;
    // if ((meInt + 2) % 3 == oppInt) {
    //     return 6;
    // } else if ((oppInt + 2) % 3 == meInt ) {
    //     return 0;
    // }
    // return 3;
}

int getScoreFromOutcome(char opp, char me) {
    int oppInt = (opp - 65) % 23;
    int x = ((me - 65) % 23 + 2) % 3;
    int meInt = (oppInt + x) % 3;
    return pointsFromOutcome(oppInt, meInt) + meInt + 1;
}

int main() {
    int total = 0;
    string line;
    ifstream file;
    file.open("input.txt");
    while (getline(file, line)) {
        char opp = line.at(0);
        char me = line.at(2);
        total += getScoreFromOutcome(opp, me);;
    }
    cout << total << endl;
}