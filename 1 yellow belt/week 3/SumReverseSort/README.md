# Desctiption

You are given a header file sum_reverse_sort.h containing declarations of three functions:

```
sum_reverse_sort.h
```

```c++
#pragma once
#include <string>
#include <vector>

using namespace std;

int Sum(int x, int y);
string Reverse(string s);
void Sort(vector<int>& nums);
```

You need to send a cpp file containing the definitions of these functions. 

The functions should add two numbers, reverse the string, and sort the vector of numbers in ascending order, respectively.

## How will your code be tested
The automated testing system will add your cpp file to the project containing another cpp file with unit tests for all three functions, as well as the sum_reverse_sort.h file. Then it will assemble this project and, if compilation is successful, run the resulting executable file. If it completes successfully (i.e. unit tests will not find errors in your implementation), then your parcel will be counted.