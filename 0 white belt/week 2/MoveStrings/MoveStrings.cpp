#include <iostream>
#include <vector>
#include <string>
using namespace std;

void MoveStrings(vector<string>& s, vector<string>& d) {
    for (const auto& ss: s) {
        d.push_back(ss);
    }
    s.clear();
}

int main(){}
