#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

template<typename K, typename V>
V& GetRefStrict(map<K,V> &m, const K &key);

template<typename K, typename V>
V& GetRefStrict(map<K,V> &m, const K &key) {
  if (m.count(key) == 0) {
    throw runtime_error("Mo such key in the map");
  }
  return m.at(key);
}

int main(){
  map<int, string> m = {{0, "value"}};
  string& item = GetRefStrict(m, 0);
  item = "newvalue";
  cout << m[0] << endl; // выведет newvalue 
}