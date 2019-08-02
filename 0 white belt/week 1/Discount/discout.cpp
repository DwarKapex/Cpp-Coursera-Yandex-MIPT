#include <iostream>

using namespace std;

int main(){
    double n, a, b, x, y;
    cin >> n >> a >> b >> x >> y;
    if (n > a && n <=b)
        cout << n*(1-0.01*x);
    else if (n > b)
        cout << n*(1-0.01*y);
    else
        cout << n;
    cout << endl;
}
