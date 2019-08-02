#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N = 0;
    cin >> N;
    const int base = 2;
    vector<int> binary;
    while (N!=0){
        binary.push_back(N % base);
        N /= base;
    }
    for (int i = binary.size()-1; i >=0; --i)
        cout << binary[i];
    cout << endl;
}
