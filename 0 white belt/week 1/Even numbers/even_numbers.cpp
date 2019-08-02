#include <iostream>

using namespace std;

int main(){
    int a=0,b=0;
    cin >> a >> b;
    if (a%2) ++a;
    for (; a<=b; a+=2)
        cout << a << " ";
    cout << endl;
}
