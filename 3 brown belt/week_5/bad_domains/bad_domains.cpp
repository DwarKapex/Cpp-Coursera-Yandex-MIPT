#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <utility>
#include <set>
using namespace std;


bool
IsSubdomain(string_view subdomain, string_view domain)
{
    int i = subdomain.size() - 1;
    int j = domain.size() - 1;
    while (i >= 0 && j >= 0) {
        if (subdomain[i--] != domain[j--]) {
            return false;
        }
    }
    return (i < 0 && j < 0) || (j < 0 && subdomain[i] == '.');
}

vector<string> ReadDomains() {
    string count_str;
    getline(cin, count_str);
    size_t count = std::stoul(count_str);

    vector<string> domains;
    for (size_t i = 0; i < count; ++i) {
        string domain;
        getline(cin, domain);
        domains.push_back(domain);
    }
    return domains;
}

vector<string_view> GetUniqueBannedDomains(const vector<string>& domains){
    vector<string_view> result(domains.begin(), domains.end());
    sort(result.begin(),
         result.end(), [](const string_view lhs, const string_view rhs){
                            return lexicographical_compare(
                                        lhs.rbegin(), lhs.rend(), rhs.rbegin(), rhs.rend());
             
         });
    
    auto end_uniques =
        unique(result.begin(), result.end(),
           [](const string_view lhs, const string_view rhs) {
               return IsSubdomain(lhs, rhs) || IsSubdomain(rhs, lhs);
           });
    
    result.erase(end_uniques, result.end());
    return result;
    
}

int main() {
    const vector<string> banned_domains = ReadDomains();
    const vector<string> domains_to_check = ReadDomains();
    
    const vector<string_view> unique_banned_domains = GetUniqueBannedDomains(banned_domains);
    
    for (const string_view domain : domains_to_check) {
        const auto it =
        upper_bound(unique_banned_domains.begin(), unique_banned_domains.end(), domain,
                    
                    [](const string_view lhs, const string_view rhs){
                                return lexicographical_compare(lhs.rbegin(), lhs.rend(), rhs.rbegin(), rhs.rend());

                    });
        if ( it != unique_banned_domains.begin() && IsSubdomain(domain, *prev(it))) {
            cout << "Bad" << endl;
        } else
            cout << "Good" << endl;
    
 
    }
       return 0;
}
