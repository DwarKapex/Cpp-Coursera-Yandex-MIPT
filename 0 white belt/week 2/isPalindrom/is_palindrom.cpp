#include <iostream>
#include <string>
using namespace std;

bool IsPalindrom(const string& str) {
    size_t n = str.size();
    size_t i = 0;
    while (i < n/2 && str[i] == str[n-i-1]) {
        ++i;
    }
    return i == n/2;
}

int main(){
    string s;
    cin >> s;
    cout << IsPalindrom(s) << endl;
}
