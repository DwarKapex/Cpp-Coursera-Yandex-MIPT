#include <iostream>
using namespace std;

int Factorial(int x){
    int result = 1;
    for (int i = 1; i <= x; ++i)
        result *= i;
    return result;
       
}

int main(){
    int n=0;
    cin >> n;
    cout << Factorial(n) << endl;

}
