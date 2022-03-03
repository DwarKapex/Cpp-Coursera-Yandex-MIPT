# Desctiption

Write a **PrintVectorPart** function that takes a vector of integers numbers, searches for the first negative number in it and outputs to standard output all the numbers located to the left of the found one in reverse order. If the vector does not contain negative numbers, print all the numbers in reverse order.

```c++
void PrintVectorPart(const vector<int>& numbers);
```

## Code example

```c++
int main() {
  PrintVectorPart({6, 1, 8, -5, 4});
  cout << endl;
  PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
  cout << endl;
  PrintVectorPart({6, 1, 8, 5, 4});
  cout << endl;
  return 0;
}
```

## Output

```
8 1 6

4 5 8 1 6
```