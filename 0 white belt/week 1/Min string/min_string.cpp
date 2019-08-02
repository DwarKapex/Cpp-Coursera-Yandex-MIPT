#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main(){
    const int MAX_SIZE = 3;
    vector<string> a(MAX_SIZE);
    for (auto & s: a)
        cin >> s;
    sort(a.begin(), a.end());
    cout << a[0] << endl;
}
