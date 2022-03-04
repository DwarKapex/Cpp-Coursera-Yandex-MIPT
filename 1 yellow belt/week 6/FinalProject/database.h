//
//  database.h
//  final_project
//
//  Created by Vladislav Kozlov on 6/27/19.
//  Copyright © 2019 Vladislav Kozlov. All rights reserved.
//

#ifndef database_h
#define database_h

#include <string>
#include <set>
#include <map>
#include <memory>
#include <vector>
#include <algorithm>
#include "date.h"
#include "node.h"


class Database {
public:
    void Add(const Date& date, const std::string& event);

    void Print(std::ostream& out) const;

    std::string Last(const Date& date) const;
    
    std::set<std::string> Find(const Date& date) const;
    
    template <typename Func>
    std::vector<std::string> FindIf(const Func& predicate) const{
        std::vector<std::string> result;
        std::ostringstream out;
        for (const auto& item: storage_vector){
            const Date& date = item.first;
            for (const auto& event: item.second){
                if ( predicate(date,event) ){
                    out << date << " " << event;
                    result.push_back(out.str());
                    out.str("");
                }
            }
        }
        return result;
    }

    template <typename Func>
    int RemoveIf(const Func& predicate){
        int result=0;
        std::vector<Date> erase_dates;
        for (auto& item: storage_vector){
            std::vector<std::string>& events = item.second;
            const Date& d = item.first;
            auto remove_start = std::stable_partition(events.begin(), events.end(),
                                                      [predicate, d](const std::string& s){
                                                          return !predicate(d,s);
                                                      }
                                                      );
            result += events.end()-remove_start;
            for (auto it = remove_start; it!= events.end(); ++it)
                storage_set.at(d).erase(*it);
            if (remove_start == events.begin())
                erase_dates.push_back(d);
            events.erase(remove_start, events.end());
        }

        for (const auto& it: erase_dates)
            DeleteDate(it);
        return result;
    }

    
    
    bool DeleteEvent(const Date& date, const std::string& event);
    
    int DeleteDate(const Date& date);
    
private:
    std::map<Date, std::vector<std::string>> storage_vector;
    std::map<Date, std::set<std::string>> storage_set;
};



#endif /* database_h */
