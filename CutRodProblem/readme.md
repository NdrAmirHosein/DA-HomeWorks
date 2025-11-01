# Rod Cutting problem Dynamic Approch

This problem is a very famous problem in CS and one great idea to solve this problem is DP

I have three approch to solve this problem.

## 1- The recursive approche
This is the most straightforward method.
We recursively explore all possible ways to cut the rod and return the maximum revenue.

However, this approach recomputes many subproblems multiple times, leading to an exponential time complexity (~O(2^n)).

## 2-DP Top Down Approch
This approach improves the recursive version by storing results of subproblems in a memoization table.

Whenever a subproblem is solved, its result is saved; if it appears again, we simply reuse the stored value instead of recomputing it.

## 3- DP Bottom Up Approch 
In this approach, we build a DP table iteratively.
We start from smaller subproblems (e.g., rod of length 1) and build up to larger ones.
