#include <iostream>

using namespace std;

int main(){
    int a = 0, b = 0;
    cin >> a >> b;
    while (a!=0 && b!=0){
        b = b % a;
        swap(a,b);
    }
    cout << a + b << endl;
}
