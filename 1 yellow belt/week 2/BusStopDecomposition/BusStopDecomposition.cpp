#include <string>
#include <iostream>
#include <cassert>
#include <map>
#include <vector>
using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
    string type;
    is >> type;
    if ("NEW_BUS" == type) {
        q.type = QueryType::NewBus;
        is >> q.bus;
        int stop_count;
        is >> stop_count;
        q.stops.resize(stop_count);
        for (string& stop : q.stops) {
            is >> stop;
        }
    } else if ("BUSES_FOR_STOP" == type) {
        q.type = QueryType::BusesForStop;
        is >> q.stop;
    } else if ("STOPS_FOR_BUS" == type) {
        q.type = QueryType::StopsForBus;
        is >> q.bus;
    } else if ("ALL_BUSES" == type){
        q.type = QueryType::AllBuses;
    }
    return is;
}

struct BusesForStopResponse {
    string response;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
    os << r.response;
    return os;
}

struct StopsForBusResponse {
    string response;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
    os << r.response;
    return os;
}

struct AllBusesResponse {
    string response;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
    os << r.response;
    return os;
}

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops) {
      buses_to_stops[bus] = stops;
      for (const string& stop : stops) {
        stops_to_buses[stop].push_back(bus);
      }
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
      BusesForStopResponse r;
      if (stops_to_buses.count(stop) == 0) {
          r.response = "No stop";
      } else {
        for (const string& bus : stops_to_buses.at(stop)) {
            r.response += (bus + " ");
        }
      }
      return r;
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
    StopsForBusResponse r;
    if (buses_to_stops.count(bus) == 0) {
        r.response = "No bus";
    } else {
        for (const string& stop : buses_to_stops.at(bus)) {
            r.response += ("Stop " + stop + ": ");
            if (stops_to_buses.at(stop).size() == 1) {
                r.response += "no interchange";
            } else {
            for (const string& other_bus : stops_to_buses.at(stop)) {
                    if (bus != other_bus) {
                        r.response += (other_bus + " ");
                    }
                }
            }
            r.response += "\n";
        }
        r.response = r.response.substr(0, r.response.size()-1);
    }
    return r;
  }

  AllBusesResponse GetAllBuses() const {
    AllBusesResponse r;
    if (buses_to_stops.empty()) {
       r.response = "No buses";
    } else {
      for (const auto& bus_item : buses_to_stops) {
        r.response += ("Bus " + bus_item.first + ": ");
        for (const string& stop : bus_item.second) {
          r.response += stop + " ";
        }
        r.response+="\n";
      }
      r.response = r.response.substr(0, r.response.size()-1);
    }
    return r;
  }
private:
    map<string, vector<string>> buses_to_stops, stops_to_buses;
};

int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
        case QueryType::NewBus:
            bm.AddBus(q.bus, q.stops);
            break;
        case QueryType::BusesForStop:
            cout << bm.GetBusesForStop(q.stop) << endl;
            break;
        case QueryType::StopsForBus:
            cout << bm.GetStopsForBus(q.bus) << endl;
            break;
        case QueryType::AllBuses:
            cout << bm.GetAllBuses() << endl;
            break;
    }
  }

  return 0;
}