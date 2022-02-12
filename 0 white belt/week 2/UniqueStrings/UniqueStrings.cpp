#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(){
    set<string> unique;
    int n = 0;
    cin >> n;
    string str;
    while(n-- > 0) {
        cin >> str;
        unique.insert(str);
    }
    cout << unique.size() << endl;
    return 0;
}