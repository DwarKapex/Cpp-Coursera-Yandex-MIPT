Implement a personal budget management system. You need to process requests of the following types:

1. ComputeIncome from to: calculate net profit for a given date range.
2. Earn from to value: take into account that for the specified period (evenly by day) the amount value was earned.
3. PayTax from to: pay 13% tax on each day of the specified range. This means a simple multiplication of all profits in the range of 0.87, regardless of whether the tax has already been paid for any of these days. Profit for these days, which will be revealed later, is not taxed from the past.

# Notes

In all from to ranges, both from and to dates are included.

# Input format

The first line introduces the number of Q queries, then in the format described above the queries themselves are entered, one per line.

# Output format

For each ComputeIncome request, in a separate line print a real number - net profit (taxfree profit) for the specified date range.

# Limitations

1. The number of requests Q - a natural number not exceeding 100.
2. All dates are entered in the format YYYY-MM-DD. The dates are correct (taking into account leap years) and belong to the 21st century.
3. value - positive integers not exceeding 1,000,000.
1 second to process all requests.

# Example

Input
```
8
Earn 2000-01-02 2000-01-06 20
ComputeIncome 2000-01-01 2001-01-01
PayTax 2000-01-02 2000-01-03
ComputeIncome 2000-01-01 2001-01-01
Earn 2000-01-03 2000-01-03 10
ComputeIncome 2000-01-01 2001-01-01
PayTax 2000-01-03 2000-01-03
ComputeIncome 2000-01-01 2001-01-01
```
Output
```
20
18.96
28.96
27.2076
```


# Explanation

The total profit for January 3, 2000 is calculated as follows: (4 * 0.87 + 10) * 0.87 = 11.7276.
