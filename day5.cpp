#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <unordered_map>
#include <iterator>
#include <cmath>
#include <stack>

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

int main() {
    vector<string> stringvec;
    string s1 = "RQGPCF";
    string s2 = "PCTW";
    string s3 = "CMPHB";
    string s4 = "RPMSQTL";
    string s5 = "NGVZJHP";
    string s6 = "JPD";
    string s7 = "RTJFZPGL";
    string s8 = "JTPFCHLN";
    string s9 = "WCTHQZVG";
    stringvec.push_back(s1);
    stringvec.push_back(s2);
    stringvec.push_back(s3);
    stringvec.push_back(s4);
    stringvec.push_back(s5);
    stringvec.push_back(s6);
    stringvec.push_back(s7);
    stringvec.push_back(s8);
    stringvec.push_back(s9);
    vector<stack<string> > vec;
    for (int i = 0; i < 9; i++) {
        stack<string> st;
        string curr = stringvec[i];
        for (int j = curr.length()-1; j >=0; j--) {
            st.push(curr.substr(j, 1));
        }
        vec.push_back(st);
    }

    string line;
    ifstream file;
    file.open("input/day5.txt");
    while (getline(file, line)) {
        vector<string> linevec = splitstr(line, " ");
        int n = stoi(linevec[1]);
        int from = stoi(linevec[3])-1;
        int to = stoi(linevec[5])-1;
        stack<string> mini;
        for (int i = 0; i < n; i++) {
            string popped = vec[from].top();
            vec[from].pop();
            mini.push(popped);
        }
        for (int i = 0; i < n; i++) {
            string tmp = mini.top();
            mini.pop();
            vec[to].push(tmp);
        }
    }
    for (const auto& l : vec) {
        cout << l.top();
    }
    cout << endl;
}
