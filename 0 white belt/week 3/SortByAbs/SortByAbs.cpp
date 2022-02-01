#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    size_t n=0;
    cin >> n;
    vector<int> v(n, 0);
    int data;
    for (size_t i = 0; i < n; ++i) {
        cin >> data;
        v[i] = data;
    }
    sort(v.begin(), v.end(), [](const int a, const int b) { return abs(a) < abs(b); });
    for (size_t i = 0; i < n; ++i) {
        cout << v[i] << " ";
    }
    return 0;
}
