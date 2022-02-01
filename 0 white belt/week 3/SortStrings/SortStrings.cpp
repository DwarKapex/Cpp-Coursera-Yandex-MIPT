#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    size_t n=0;
    cin >> n;
    vector<string> v(n);
    string data;
    for (size_t i = 0; i < n; ++i) {
        cin >> data;
        v[i] = data;
    }
    sort(begin(v), end(v),
         [](const string& a, const string& b) {
         return lexicographical_compare(
                          a.begin(), a.end(),
                          b.begin(), b.end(),
                          [](char cl, char cr) { 
                              return tolower(cl) < tolower(cr); 
                            }
                );
        }
    );
    for (size_t i = 0; i < n; ++i) {
        cout << v[i] << " ";
    }
    return 0;
}
