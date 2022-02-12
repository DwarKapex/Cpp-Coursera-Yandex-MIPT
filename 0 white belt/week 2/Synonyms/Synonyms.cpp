#include <iostream>
#include <map>
#include <string>
#include <set>
using namespace std;

int main(){
    int n = 0;
    cin >> n;
    map<string, set<string>> dict;
    while (n-- >0){
        string req, word1, word2;
        cin >> req;
        if (req == "ADD"){
            cin >> word1 >> word2;
            dict[word1].insert(word2);
            dict[word2].insert(word1);
        }
        else if (req == "COUNT"){
            cin >> word1;
            cout << dict[word1].size() << endl;;
        }
        else{ //check
            cin >> word1 >> word2;
            if (dict[word1].count(word2) !=0 || dict[word2].count(word1))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}