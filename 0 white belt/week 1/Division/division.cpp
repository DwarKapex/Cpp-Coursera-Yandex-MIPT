#include <iostream>
using namespace std;

int main(){
    int a = 0, b= 0;
    cin >> a >> b;
    if (b == 0)
        cout << "Impossible";
    else
        cout << a/b;
}
