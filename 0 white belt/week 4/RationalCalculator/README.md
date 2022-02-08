# Desctiption

So, now we have a full-fledged type for representing ordinary fractions: the Rational class is integrated into the language using operator overloading and does not allow performing incorrect operations by throwing exceptions. Let's create a simple calculator for ordinary fractions based on the Rational class.

You need to write a program that reads one line from the standard input in the format FRACTION_1 operation FRACTION_2. FRACTION_1 and FRACTION_2 have the format X/Y, where X is an integer and Y is a non—negative integer. the operation is one of the characters '+', '-', '*', '/'.

If FRACTION_1 or FRACTION_2 is an incorrect ordinary fraction, your program should output the message "Invalid argument" to standard output. If the read operation is division by zero, output the message "Division by zero" to standard output. Otherwise, output the result of the operation.

# Example


|stdin|stdout|
|-|-|
|1/2 + 1/3|5/6|
|1/2 + 5/0|Invalid argument|
|4/5 / 0/8|Division by zero|