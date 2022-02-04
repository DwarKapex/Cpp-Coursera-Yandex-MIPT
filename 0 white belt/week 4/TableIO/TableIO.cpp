#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){
    ifstream input("input.txt");
    int n=0,m=0, d;
    input >> n >> m;
    cout << right;
    while (n-- >0){
        for (int i = 0; i < m-1; ++i){
            input >> d; input.ignore(1);
            cout << setw(10) << d << " ";
        }
        input >> d; cout << setw(10) << d;
        if (n !=0) cout << endl;
    }
}