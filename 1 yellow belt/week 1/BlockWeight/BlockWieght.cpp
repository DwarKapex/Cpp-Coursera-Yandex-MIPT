#include <iostream>

using namespace std;

int main(){
    uint64_t n = 0, r = 0, w = 0, h = 0, d = 0;
    cin >> n >> r;
    uint64_t sum = 0;
    while (n-- > 0) {
        cin >> w >> h >> d;
        sum = sum + w*h*d*r;
    }
    cout << sum << endl;
}