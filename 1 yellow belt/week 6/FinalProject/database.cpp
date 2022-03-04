//
//  database.cpp
//  final_project
//
//  Created by Vladislav Kozlov on 6/27/19.
//  Copyright © 2019 Vladislav Kozlov. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <memory>
#include "date.h"
#include "database.h"
#include "node.h"

void Database::Add(const Date& date, const std::string& event) {
    if (storage_set[date].count(event) == 0){
        storage_set[date].insert(event);
        storage_vector[date].push_back(event);
    }
}

bool Database::DeleteEvent(const Date& date, const std::string& event) {
    if (storage_set.count(date) > 0 && storage_set.at(date).count(event) >0 ) {
        std::vector<std::string>& data = storage_vector.at(date);
        data.erase(std::remove(data.begin(), data.end(), event), data.end());
        storage_set.at(date).erase(event);
        return true;
    }
    return false;
}
    
int Database::DeleteDate(const Date& date) {
    int result = 0;
    if (storage_vector.count(date) != 0) {
        const int event_count = storage_vector.at(date).size();
        storage_vector.erase(date);
        storage_set.erase(date);
        result = event_count;
    }
    return result;
}
    
std::set<std::string> Database::Find(const Date& date) const {
    if (storage_set.count(date) > 0) {
        return storage_set.at(date);
    } else {
        return {};
    }
}
    
void Database::Print(std::ostream& out) const {
    for (const auto& item : storage_vector) {
        for (const std::string& event : item.second) {
            out << item.first << " " << event << std::endl;
        }
    }
}

std::string Database::Last(const Date& date) const{
    std::string result{"No entries"};
    std::ostringstream os;
    auto _last = storage_vector.upper_bound(date);
    if (_last != storage_vector.begin()){
        --_last;
        os << _last->first << " " << *(--(_last->second.end()));
        result = os.str();
    }
    return result;
}

