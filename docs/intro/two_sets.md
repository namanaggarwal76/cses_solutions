# Two Sets

## Problem Link

[https://cses.fi/problemset/task/1092](https://cses.fi/problemset/task/1092)

## Approach

If n is even and n/2 is also even, then we have something like

```bash
1 2 3 4 ... n
```
and there are n/2 even numbers, and n/2 odd numbers. Total sum is even. So me pair first and last elements in alternate sets. For example -->

```bash
1 2 3 4 
1 and 4 in set 1
2 and 3 in set 2
```

Now when n is even but n/2 is odd, we have odd count of odd numbers, so overall their sum will be odd, and total sum will be odd, so no solution.

3rd Case, when n is odd and