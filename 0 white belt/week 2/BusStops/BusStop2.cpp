#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;


int main(){
    map<vector<string>, int> routes;
    int n;
    cin >> n;
    string stop;
    while (n-- >0){
        int k = 0;
        cin >> k;
        vector<string> stops(k);
        while (k-- > 0) {
            cin >> stop;
            stops.push_back(stop);
        }
        if (0 != routes.count(stops)) {
            cout << "Already exists for " << routes.at(stops) << "\n";
        } else {
            int next_route_id = routes.size()+1;
            routes[stops] = next_route_id;
            cout << "New bus " << next_route_id << endl;
        }
    }
    return 0; 
}