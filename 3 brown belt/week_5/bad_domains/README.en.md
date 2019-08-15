Filter arbitrary domains by a fixed set of forbidden domains.

Namely, if the ya.ru domain is prohibited, then not only he, but all his subdomains should be filtered: ya.ru, m.ya.ru, m.mail.ya.ru, etc.

# Input data

First, the number of forbidden domains and these domains themselves are entered. Then, the domains to be verified are entered in the same format.

# Output

For each domain in the second set, print one line: Bad if you want to filter the domain (that is, it is included in the list of banned domains or is a subdomain of one of them), and Good otherwise.

Example

Input

```
four
ya.ru
maps.me
m.ya.ru
com
7
ya.ru
ya.com
m.maps.me
moscow.m.ya.ru
maps.com
maps.ru
ya.ya
```

Output
```
Bad
Bad
Bad
Bad
Bad
Good
Good
```

# Limitations

It is guaranteed that each domain is a set of lowercase Latin letters separated by dots. A period cannot be the first or last character of a domain. Two points cannot be adjacent characters. (In other words, there is a letter in front of and after each point.)

The length of each domain is not more than 50, in each set no more than 10,000 domains.

The program should run in 3 seconds.

# Wrong solution to the problem

You have been given a solution to this problem, but it has bugs. Correct them or rewrite the code from scratch.

```
domains_bad_wa.cpp
```
