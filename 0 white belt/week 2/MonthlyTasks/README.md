# Desctiption

Each of us has recurring monthly tasks, each of which needs to be performed on a specific day of each month: payment of electricity bills, subscription fees for communications, etc. You need to implement work with a list of such cases for a month, namely, to implement a set of the following operations:

 - **ADD i s**
    
    Assign a case with the name s to day i of the current month.

 - **DUMP i**

    Display all the cases scheduled for day I of the current month.

 - **NEXT**

    Go to the to-do list for the new month. When executing this command, instead of the current (old) to-do list for the current month, a (new) to-do list for the next month is created and becomes active: all cases from the old to-do list are copied to the new list. After executing this command, the new to-do list and the next month become current, and work with the old to-do list stops.  When switching to a new month, you need to pay attention to the different number of days in the months:

    - if the next month has more days than the current one, the "extra" days must be left empty (not containing cases);

    - if the next month has fewer days than the current one, the cases from all the "extra" days must be moved to the last day of the next month.

## Remarks

The history of to-do lists does not need to be stored, work is carried out only with the current to-do list of the current month. Moreover, when creating a to-do list for the next month, it "grinds" the previous list.

Note that the number of NEXT commands in the total sequence of commands when working with the to-do list may exceed 11.

The initial current month is January.

The number of days in months corresponds to the Gregorian calendar with the only difference that February always has 28 days.

## Input format

First, the number of operations Q, then the descriptions of operations.

Case names are unique and consist only of Latin letters, numbers and underscores. The numbers of days i are integers and are numbered from 1 to the size of the current month.

## Output format

For each DUMP type operation, in a separate line, print the number of cases on the corresponding day, and then their names, separating them with a space. The order of withdrawal of cases within each operation does not matter.

# Example

## Input
```
12
ADD 5 Salary
ADD 31 Walk
ADD 30 WalkPreparations
NEXT
DUMP 5
DUMP 28
NEXT
DUMP 31
DUMP 30
DUMP 28
ADD 28 Payment
DUMP 28
```

## Output

```
1 Salary
2 WalkPreparations Walk
0
0
2 WalkPreparations Walk
3 WalkPreparations Walk Payment
```