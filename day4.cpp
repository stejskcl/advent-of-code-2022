#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

vector<string> splitstr(string str, string deli = " ")
{
    int start = 0;
    int end = str.find(deli);
    vector<string> ret;
    while (end != -1) {
        string s = str.substr(start, end - start);
        ret.push_back(s);
        start = end + deli.size();
        end = str.find(deli, start);
    }
    string s = str.substr(start, end - start);
    ret.push_back(s);
    return ret;
}

bool fullcontains(vector<string> x, vector<string> y) {
    return stoi(x[0]) >= stoi(y[0]) && stoi(x[1]) <= stoi(y[1]);
}

bool partcontains(vector<string> x, vector<string> y) {
    return (stoi(x[0]) <= stoi(y[1])) && (stoi(x[1]) >= stoi(y[0]));
}

int main() {
    string l;
    ifstream f;
    f.open("input/day4.txt");
    
    vector<string> xy;
    vector<string> x;
    vector<string> y;
    
    int tot = 0;

    while(getline(f,l)) {
        xy = splitstr(l,",");
        x = splitstr(xy[0],"-");
        y = splitstr(xy[1],"-");

        if (fullcontains(x, y) || fullcontains(y, x)
        || partcontains(x,y) || partcontains(y,x)) {
            tot++;
        }

    }
    std::cout << tot << endl;
}