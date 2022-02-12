#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int Q=0, current_month=0;
    const vector<int> months={31,28,31,30,31,30,31,31,30,31,30,31};
    vector<vector<string>> duties(months[current_month]);
    cin >> Q;
    string req;
    while (Q-- > 0){
        cin >> req;
        if (req == "ADD"){
            int day;
            string duty;
            cin >> day >> duty;
            duties[day-1].push_back(duty);
        }
        else if (req == "NEXT"){
            int next_month = (current_month+1) % 12;
            int current = months[current_month], next = months[next_month];
            if (next > current){
                for (int idx = current; idx < next; ++idx)
                    duties[idx].clear();
            }
            else if(next < current){
                 for (int idx=next; idx < current; ++idx){
                        duties[next-1].insert(end(duties[next-1]), 
                                           begin(duties[idx]), end(duties[idx]));
                        duties[idx].clear();
                 }
                 
            }
            current_month = next_month;
            
        }
        else if (req == "DUMP"){
            int day;
            cin >> day;
            cout << duties[day-1].size() << " ";
            for (auto &s: duties[day-1])
                cout << s << " ";
            cout << endl;
        }
    }
    return 0;

}