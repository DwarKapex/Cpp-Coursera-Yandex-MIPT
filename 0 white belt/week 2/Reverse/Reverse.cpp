#include <iostream>
#include <vector>
using namespace std;

void Reverse(vector<int>& v) {
    const size_t n = v.size();
    for (size_t i = 0; i < n/2; ++i) {
        swap(v[i], v[n-1-i]);
    }
}

int main(){
    vector<int> v{1,2,3,4,5};
    Reverse(v);
    for (const auto a: v) cout << a << " ";
    cout << endl;
    return 0;
}
