# Desctiption

Words are called *anagrams* of each other if one of them can be obtained by rearranging letters in the other. For example, the word "eat" can be obtained by rearranging the letters of the word "tea", so these words are anagrams of each other. Given pairs of words, check for each of them whether the words of this pair are anagrams of each other.

## Indication

One way to check whether words are anagrams of each other is as follows. For each word, we will use the dictionary to calculate how many times each letter occurs in it. If these dictionaries are equal for both words (and this is checked using the usual == operator), then the words are anagrams of each other, otherwise they are not.

At the same time, it is convenient to put the construction of such a dictionary by word into a separate function BuildCharCounters.

## Input format
First, the number of pairs of words N is given, then N lines contain pairs of words that need to be checked. It is guaranteed that all words consist only of lowercase Latin letters.

## Output format
Print N lines: for each pair of words entered, YES if these words are anagrams, and NO otherwise.

# Example

## Input
```
3
eat tea
find search
master stream
```

## Output

```
YES
NO
YES
```