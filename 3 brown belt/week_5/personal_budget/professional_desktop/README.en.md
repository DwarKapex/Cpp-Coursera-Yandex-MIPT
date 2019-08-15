It is necessary to add support for the new request to the home desktop version:

1. Spend from to value: spend the specified amount evenly over the specified date range. Now the net profit in ComputeIncome requests is calculated as the difference between earned (net of taxes) and spent. When calculating tax, the amounts spent are not taken into account.

In addition, in PayTax requests you now need to accept the percentage that you need to pay:

1. PayTax from to percentage: pay the specified tax in the specified range. It is guaranteed that percentage is an integer from 0 to 100.

# Example

Input
```
8
Earn 2000-01-02 2000-01-06 20
ComputeIncome 2000-01-01 2001-01-01
PayTax 2000-01-02 2000-01-03 13
ComputeIncome 2000-01-01 2001-01-01
Spend 2000-12-30 2001-01-02 14
ComputeIncome 2000-01-01 2001-01-01
PayTax 2000-12-30 2000-12-30 13
ComputeIncome 2000-01-01 2001-01-01
```
Output
```
20
18.96
8.46
8.46
```
