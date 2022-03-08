# Desctiption

Solve the "Average temperature" problem in other constraints on the input data.

The temperature values observed for N consecutive days are given. Find the numbers of days (numbered from zero) with a temperature value above the arithmetic mean for all N days.

It is guaranteed that the arithmetic mean of the temperature values is an integer.

## Input format
The number N is entered, then N integers are the temperature values on the 0th, 1st, ... (N−1)th day. It is guaranteed that N does not exceed a million (10^6), and the temperature values measured in millionths of degrees Celsius are in the range from -10^8 to 10^8. There is no need to check compliance with these restrictions: you can focus on them when choosing the most appropriate types for variables.

## Output format
The first number K is the number of days in which the temperature value is higher than the arithmetic mean. Then K integers are the numbers of these days.  

# Example 1
|input|output|
|-|-|
|5|3|
|5 4 1 -2 7|0 1 4|

# Example 2
|input|output|
|-|-|
|5|0|
|2 2 2 2 2 2||