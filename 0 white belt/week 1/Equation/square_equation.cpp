#include <iostream>
#include <cmath>

using std::cin; using std::cout; using std::endl;

int main(){
    double a,b,c;
    cin >> a >> b >> c;
    if (a == 0.0f){
        if (b != 0.0f)
            cout << -c/b;
    }
    else{
    long double D = b*b-4*a*c;
    if (D == 0)
        cout << -b/2/a;
    else if (D>0){
        cout << (-b +sqrt(D))/2/a << " " << (-b-sqrt(D))/2/a; 
    }
    }
    cout << endl;
}
