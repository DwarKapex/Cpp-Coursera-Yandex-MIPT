# Desctiption

## Part 1
Implement the construction of an arithmetic expression according to the following scheme:

initially there is an expression consisting of some integer x;

at each step, some operation is applied to the current expression: adding a number, subtracting a number, multiplying by a number or dividing by a number; before applying the operation, the expression must always be enclosed in brackets.

## Example
Initially there is a number 8, the corresponding expression:

```
8
```

Now we add multiply by 3:

```
(8) * 3
```

Then substruct 6:

```
((8) * 3) - 6
```

And finally devide by 1:

```
(((8) * 3) - 6) / 1
```

## Input format

The first line contains the original integer x. The second line contains a non-negative integer N— the number of operations. Each of the following N lines contains the next operation:  

 - adding the number a: + a;
 - subtracting the number b: - b;
 - multiplication by the number c: * c;
 - division by the number d: / d.

The number of operations can be zero — in this case it is necessary to output the original number.

## Output format

Output a single line - the constructed arithmetic expression.

Pay attention to the placement of spaces around the characters:

 - each binary operation character (+, -, * or /) must be surrounded by exactly one space on each side: (8) * 3;

 - unary minus symbol (for negative numbers) does not need an additional space: -5;

 - brackets and numbers do not need additional spaces.

## Hint

To convert a number to a string, use the to_string function from the <string> library.

## Example
### Input

```
8
3
* 3
- 6
/ 1
```

### Output

```
(((8) * 3) - 6) / 1
```

# Part 2. Without extra brackets

Modify the solution of the previous part so that the previous expression is framed with brackets only if necessary, that is, only if the next operation has a higher priority than the previous one.

## Example
### Input

```
8
3
* 3
- 6
/ 1
```

### Output

```
(8 * 3 - 6) / 1
```
