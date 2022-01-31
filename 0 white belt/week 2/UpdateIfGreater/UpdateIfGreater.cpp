#include <iostream>
using namespace std;

void UpdateIfGreater(const int first, int& second) {
    if (first > second) {
        second = first;
    }
}

int main(){
    int a = 1, b = 2;
    UpdateIfGreater(a,b);
    cout << b << endl;
    return 0;
}
