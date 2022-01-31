#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool IsPalindrom(const string& str) {
    size_t n = str.size();
    size_t i = 0;
    while (i < n/2 && str[i] == str[n-i-1]) {
        ++i;
    }
    return i == n/2;
}

vector<string> PalindromFilter(const vector<string>& words, const int minLength) {
    vector<string> res;
    for (const auto& word: words) {
        if (word.length() >= minLength && IsPalindrom(word)) {
            res.push_back(word);
        }
    }
    return res;
}

int main(){
    auto a = PalindromFilter({"weew", "bro", "code"}, 4);
    for (const auto& b: a) {
        cout << b << endl;
    }
    return 0;
}
