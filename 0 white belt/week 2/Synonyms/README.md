# Desctiption

Two words are called synonyms of each other if they have similar meanings. Implement the following operations on the synonym dictionary:

 - **ADD word1 word2** — add a pair of synonyms to the dictionary (word1, word2).

 - **COUNT word** - find out the number of synonyms of the word word.

 - **CHECK word1 word2** - check if the words word1 and word2 are synonyms. The words word1 and word2 are considered synonyms if among the ADD queries there was at least one query ADD word1 word2 or ADD word2 word1.

## Remark

To simplify, we assume that synonyms do not have transitivity, that is, if A is a synonym of B and B is a synonym of C, then it does NOT follow that A is a synonym of C.

## Input format

First, the number of queries Q is entered, then Q lines with descriptions of queries. It is guaranteed that in each CHECK and ADD query, the words word1 and word2 are different. All words consist only of Latin letters, numbers and underscores.

## Output format
For each request, print the answer to it in the corresponding line:

 - In response to the COUNT word query, output a single integer — the number of synonyms of the word word.

 - In response to the CHECK word1 word2 query, output the string YES if word1 and word2 are synonyms, and NO otherwise.

# Example

## Input
```
8
ADD program code
COUNT cipher
ADD code cipher
COUNT code
COUNT program
CHECK code program
CHECK program cipher
CHECK cpp java
```

## Output

```
0
2
1
YES
NO
NO
```