#include <iostream>
#include <string>
using namespace std;

int main(){
    string a;
    cin >> a;
    char const char_2_find = 'f';
    int const NUM_PENETRATIONS = 2;
    int penetration = 0, result = -2;
    for (int i = 0; i < a.size() && result < 0; ++i){
        if (a[i] == char_2_find){
            ++penetration;
            ++result;
        }
        if (penetration == NUM_PENETRATIONS)
            result = i;
    }
    cout << result << endl;

}
