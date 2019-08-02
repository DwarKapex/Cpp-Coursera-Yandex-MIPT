The input of your program in the standard input contains the real coefficients A, B and C of the equation Ax² + Bx + C = 0. Print all its different real roots in any order. It is guaranteed that at least one of the coefficients is not equal to zero.

Example

stdin           stdout
2 5 2           -0.5 -2
2 4 2               -1
2 1 2               
0 4 10          -2.5
hint

To calculate the square root, use the sqrt function from the cmath library. To connect the library, at the beginning of the program write

```
#include <cmath>
```
