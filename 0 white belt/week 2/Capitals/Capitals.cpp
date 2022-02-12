#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    int Q;
    cin >> Q;
    map<string, string> world;
    while(Q-- >0){
        string req;
        cin >> req;
        if (req == "CHANGE_CAPITAL"){
            string country, new_capital;
            cin >> country >> new_capital;
            if (world.count(country)){
                if (new_capital != world.at(country)){
                    cout << "Country " << country << " has changed its capital from " 
                        << world.at(country) << " to " << new_capital;
                    world[country] = new_capital;
                }
                else{
                    cout << "Country " << country << " hasn't changed its capital";
                }
            }
            else{
                world[country] = new_capital;
                cout << "Introduce new country " << country 
                     << " with capital " << new_capital;
            }
                
        }
        else if (req == "RENAME"){
            string old_country_name, new_country_name;
            cin >> old_country_name >> new_country_name;
            if (world.count(old_country_name) && !world.count(new_country_name) 
                    && old_country_name != new_country_name){
                cout << "Country " << old_country_name 
                     << " with capital " << world[old_country_name] 
                     << " has been renamed to " << new_country_name;
                world[new_country_name] = world[old_country_name];
                world.erase(old_country_name);
            }
            else{
                cout << "Incorrect rename, skip";
            }
        }
        else if (req == "ABOUT"){
            string country;
            cin >> country;
            if (world.count(country))
                cout << "Country " << country << " has capital " 
                    << world[country];
            else
                cout << "Country " << country << " doesn't exist";

        }
        else
            if (world.empty())
                cout << "There are no countries in the world";
            else
                for (auto &item: world)
                    cout << item.first << "/" << item.second << " ";

        
        cout << endl;
    }
    return 0;
}