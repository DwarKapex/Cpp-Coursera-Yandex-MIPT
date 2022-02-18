# Desctiption

The Rational class is a rational number and has the following interface

```c++
class Rational {
public:
  Rational();
  Rational(int numerator, int denominator);

  int Numerator() const;
  int Denominator() const;
};
```
List of requirements for implementing the Rational class interface:

The default constructor should create a fraction with a numerator of 0 and a denominator of 1.

When constructing an object of the Rational class with parameters p and q, the fraction p/q must be reduced.

If the fraction p/q is negative, then the Rational(p, q) object must have a negative numerator and a positive denominator.

If the fraction p/q is positive, then the Rational(p, q) object must have a positive numerator and denominator (note the case of Rational(-2, -3)).

If the numerator of the fraction is zero, then the denominator must be 1.

  Develop a set of unit tests that will check the correctness of the Rational class implementation. There is no need to test the case when the denominator is zero.

You can get started with a template that contains our unit test framework and a Rational class template (**test_rational.cpp**)
