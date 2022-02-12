#include <iostream>
#include <map>

using namespace std;

map<char, int> BuildCharCounter(const string& s){
    map<char, int> result;
    for (auto &c: s)
        ++result[c];
    return result;
}

int main(){
    int n=0;
    cin >> n;
    string a,b;
    while (n-- > 0){
        cin >> a >> b;
        if (BuildCharCounter(a) == BuildCharCounter(b))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}