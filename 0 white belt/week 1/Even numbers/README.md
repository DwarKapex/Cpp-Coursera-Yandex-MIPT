# Description

Two integers A and B are given (A <= B, A> = 1, B <= 30000). Print all the even numbers from A to B (inclusive), separated by spaces.

To check the integer x for parity, we use the operation of taking the remainder of division by 2, which in C ++ is executed using the symbol "%". For example,

```
int x;
cin >> x;
if (x% 2 == 0) {
   // x is an even number
   } else {
   // x is an odd number
   }
```

# Example
   
stdin           stdout
1 10              2 4 6 8 10
2 3               2
9 11              10
