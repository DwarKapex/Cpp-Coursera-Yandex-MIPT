# Desctiption

Implement the Sqr template function, which works not only for numbers, but also for containers. The function should return a copy of the original container by modifying it as follows:

 - for vector, the elements need to be squared;

 - for map, you need to square only the values, but not the keys;

 - for a pair, you need to square each element of the pair.

```c++
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
```

The code above should output:

```
vector: 1 4 9
map of pairs:
4 4 4
7 16 9
```

The function should work correctly not only for containers consisting of numbers, but also for composite objects, for example, vectors of dictionaries of pairs of numbers.

For successful delivery of the solution, it is necessary to make a preliminary declaration of template functions before all template functions.

Example of a template function pre-declaration

```c++
template<typename T> T FuncA(T x);
template<typename T> void FuncB(T x);

// Объявляем шаблонные функции
template <typename T>
T FuncA(T x) { /*...*/ }

template <typename T>
void FuncB(T x) { /*...*/ }
```