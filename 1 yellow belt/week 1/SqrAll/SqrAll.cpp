#include <iostream>
#include <vector>
#include <utility>
#include <map>

using namespace std;

template<typename T>
T Sqr(const T &);

template<typename T>
vector<T> operator*(const vector<T> &a, const vector<T> &b);

template<typename K, typename V>
map<K, V> operator*(const map<K,V> &a, const map<K,V> &b);

template<typename F, typename S>
pair<F, S> operator*(const pair<F,S> &a, const pair<F,S> &b);

template<typename F, typename S>
pair<F, S> operator*(const pair<F,S> &a, const pair<F,S> &b) {
    return {a.first*b.first, a.second*b.second};
}

template<typename K, typename V>
map<K, V> operator*(const map<K,V> &a, const map<K,V> &b){
    if (a.size() != b.size()) {
        throw invalid_argument("Maps should be of the same size");
    }
    map<K,V> result;
    for (const auto &[k,v] : a) {
        if (b.count(k) == 0) {
            throw invalid_argument("Maps must have the same set of keys");
        }
        result[k] = v*b.at(k);
    } 
    return result;
}

template<typename T>
vector<T> operator*(const vector<T> &a, const vector<T> &b) {
    if (a.size() != b.size()) {
        throw invalid_argument("Vectors must be of the same size");
    }
    vector<T> result(a.size());
    for (size_t i = 0; i < a.size(); ++i) {
        result[i] = a[i]*b[i];
    }
    return result;
}

template<typename T>
T Sqr(const T & x) {
    return x*x;
}

int main(){
 
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;
    
    map<int, pair<int, int>> map_of_pairs = {
        {4, {2, 2}},
        {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
    vector<map<int, vector<double>>> it = { { {2, { 3, 4,5,6.8 }}}, { {5, {6, 7,0.01}} } };
    Sqr(it);
    const map<int, int> maps{ {1,2},{2,3} };
	auto res = Sqr(maps);
    int a = 10;
    Sqr(a);
}