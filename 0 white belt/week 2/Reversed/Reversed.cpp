#include <iostream>
#include <vector>
using namespace std;

vector<int> Reversed(const vector<int>& v) {
    const size_t n = v.size();
    vector<int> res;
    for (size_t i = n; i > 0; --i) {
        res.push_back(v[i-1]);
    }
    return res;
}

int main(){
    vector<int> v{1,2,3,4,5};
    auto a = Reversed(v);
    for (const auto b: a) cout << b << " ";
    cout << endl;
    return 0;
}
