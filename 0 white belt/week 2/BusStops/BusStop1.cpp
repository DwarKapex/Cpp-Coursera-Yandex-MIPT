#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;


int main(){
    map<string, vector<string>> bus_to_stop, stop_to_bus;
    int Q;
    cin >> Q;
    while (Q-- >0){
        string request, bus, bus_stop;
        cin >> request;
        if (request == "NEW_BUS"){
            int stop_count;
            cin >> bus >> stop_count;
            while (stop_count-- >0){
                cin >> bus_stop;
                bus_to_stop[bus].push_back(bus_stop);
                stop_to_bus[bus_stop].push_back(bus);
            }
        }
        else if (request == "BUSES_FOR_STOP"){
            cin >> bus_stop;
            if (stop_to_bus.count(bus_stop) == 0)
                cout << "No stop";
            else{
                for (const auto &item: stop_to_bus[bus_stop])
                    cout << item << " ";
            }
            cout << endl;
        }
        else if (request == "STOPS_FOR_BUS"){
            cin >> bus;
            if (bus_to_stop.count(bus) == 0)
                cout << "No bus\n";
            else{
                for (const auto &item: bus_to_stop[bus]){
                    cout << "Stop " << item << ":";
                    if (stop_to_bus[item].size() == 1)
                        cout << " no interchange";
                    else
                        for (auto &buses: stop_to_bus[item])
                            if (buses != bus)
                                cout << " " << buses;
                    cout << endl;
                }
            }
        }
        else{ // ALL_BUSES
            if (bus_to_stop.empty())
                cout << "No buses\n";
            else
                for (const auto &bus: bus_to_stop){
                    cout << "Bus " << bus.first << ": ";
                    for (auto &stop: bus.second)
                        cout << stop << " ";
                    cout << endl;
                }
        }
    }
    return 0; 
}