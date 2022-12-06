#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

/*
* Returns the score from one turn given the characters
* of that turn.
* If fromOutcome = false, it returns points based on
* X = rock, Y = paper, Z = scissors
* If fromOutcome = true, it returns points based on
* X = lose, Y = draw, Z = win
*/
int getScore(char op, char me, bool fromOutcome) {
    int opNum = (op - 65) % 23;
    int meNum = (me - 65) % 23;

    if (fromOutcome) {
        meNum = (meNum + 2) % 3;
        meNum = (meNum + opNum) % 3;
    }
    
    int choicePts = meNum + 1;
    int shift = (2 * opNum + 1) % 3;
    int shiftMeNum = (shift + meNum) % 3;
    int outcomePts = shiftMeNum * 3;
    return choicePts + outcomePts;
}

int main() {
    int total = 0;
    string line;
    ifstream file;
    file.open("input/day2.txt");
    while (getline(file, line)) {
        //total += getScore(line.at(0), line.at(2), false);  // part 1
        total += getScore(line.at(0), line.at(2), true);  // part 2
    }
    cout << total << endl;
}