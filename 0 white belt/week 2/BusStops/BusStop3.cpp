#include <iostream>
#include <set>
#include <vector>

using namespace std;

int is_new_bus(vector<set<string>>& buses, const set<string>& stops){
    for (int i = 0; i < buses.size(); ++i)
        if (buses[i] == stops)
            return i+1;
    buses.push_back(stops);
    return -1;
}


int main(){
    int Q, count;
    cin >> Q;
    vector<set<string>> buses;
    set<string> stops;
    string stop;
    while(Q-- >0){
        cin >> count;
        while (count-- >0){
            cin >> stop;
            stops.insert(stop);
        }
        int bus = is_new_bus(buses, stops);
        if (bus == -1)
            cout << "New bus " << buses.size();
        else
            cout << "Already exists for " << bus;
                
        stops.clear();
        cout << endl;
    }

    return 0;
}