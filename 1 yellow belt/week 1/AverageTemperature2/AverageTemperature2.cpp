#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> temp(n);
    int64_t sum = 0;    
    for (auto &t: temp){
        cin >> t;
        sum+=t;
    }
    sum /=n;
    vector<int> result;
    for (size_t idx = 0; idx < n; ++idx)
        if (temp[idx] > sum)
            result.push_back(idx);
    cout << result.size() << endl;
    for (auto &t: result)
        cout << t << " ";
    cout << endl;
}