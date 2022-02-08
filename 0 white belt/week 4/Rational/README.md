# Desctiption

In this task, you need to develop a class for representing rational numbers and implement it into the type system of the C++ language so that it can be used naturally. The task consists of several parts. Attached to each part is a file with a program template, which has the following structure

```c++
#include <iostream>
using namespace std;

// Комментарии, которые говорят, что именно нужно реализовать в этой программе

int main() {
    // Набор юнит-тестов для вашей реализации
    cout << "OK" << endl;
    return 0;
}
```

You need to implement what is suggested in the comments without changing the body of the main function, so that your program displays the OK message on the screen. The main function contains a number of unit tests that check the correctness of your implementation. If these tests find an error in your implementation, then instead of OK, the program will output a hint about what exactly is working incorrectly.

When your program starts to output OK, you can send your file for verification. Your implementation will be tested on a different, more complete set of tests. That is, if your program outputs OK, then this does not guarantee that your implementation will be accepted by the testing system. In case of an unsuccessful shipment, the testing system will also give you a hint about which part of the implementation is working incorrectly.

Carefully study the set of unit tests for each blank solution. Tests describe the requirements for your implementation, which may not be specified in the task condition

You can send the entire file with your implementation for verification: you do not need to delete the main function from it.

# Part 1

In the first part, you need to implement the Rational class, which is a rational number of the form p/q, where p is an integer and q is a natural and the ranges of possible values of p, q are such that they can be represented by the int type. At the same time, the Rational class should have the following interface:

```c++
class Rational {
public:
  Rational();
  Rational(int numerator, int denominator);

  int Numerator() const;
  int Denominator() const;
};
```

The Rational class must ensure that p/q is an irreducible fraction. For example, the code

```c++
Rational r(4, 6);
cout << r.Numerator() << '/' << r.Denominator();
```

it should output "2/3" — that's why we make Rational a class, not a structure. The structure would allow breaking this invariant:

```c++
struct Rational {
    int numerator, denominator;
};

Rational r{2, 3};
r.numerator = 6; // The irreducibility invariant is violated
```

List of requirements for implementing the Rational class interface:

 - The default constructor should create a fraction with a numerator of 0 and a denominator of 1.

 - When constructing an object of the Rational class with the parameters p and q, the fraction p/q must be reduced (here you may need a solution to the "Greatest common divisor" problem).

 - If the fraction p/q is negative, then the Rational(p, q) object must have a negative numerator and a positive denominator.

 - If the fraction p/q is positive, then the Rational(p, q) object must have a positive numerator and denominator (note the case of Rational(-2, -3)).

 - If the numerator of the fraction is zero, then the denominator must be 1.

 - It is guaranteed that none of the tests on which your implementation will be tested will have a denominator equal to zero.

## Remark:
In the C++17 language standard, there is a standard gcd function for computing nodes. It is acceptable to use this function to reduce fractions. More information about this function and its limitations can be found at the link: https://en.cppreference.com/w/cpp/numeric/gcd


# Part 2

Implement the ==, + and - operators for the Rational class so that operations with fractions can be written naturally. For example, the following code must be valid:

```c++
const Rational r = Rational(1, 2) + Rational(1, 3) - Rational(1, 4);
if (r == Rational(7, 12)) {
  cout << "equal";
}
```

It is guaranteed that in all tests on which your implementation will be tested, the numerators and denominators of ALL fractions (both initial and resulting from the corresponding arithmetic operations) will fit into the int type range.

# Part 3
Similarly to the previous part, implement the * and / operators. For example, the following code must be valid:

```c++
const Rational r = Rational(1, 2) * Rational(1, 3) / Rational(1, 4);
if (r == Rational(2, 3)) {
  cout << "equal";
}
```

As in the previous case, it is guaranteed that in all tests on which your implementation will be tested, the numerators and denominators of ALL fractions (both initial and resulting from the corresponding arithmetic operations) will fit into the int type range.

In addition, it is guaranteed that no division by zero will be performed in any of the tests on which your implementation will be tested.

# Part 4

In this part, you need to implement input and output operators for the Rational class. As a result, you should have, for example, the following code

```c++
Rational r;
cin >> r;
cout << r;
```

# Part 5

Finally, you need to implement the ability to use Rational class objects as set container elements and keys in the map container. Example:

```c++
set<Rational> rationals;
rationals.insert(Rational(1, 2));
rationals.insert(Rational(1, 3));

map<Rational, string> name;
name[Rational(1, 2)] = "one second";
```