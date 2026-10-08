# [279. Perfect Squares](https://leetcode.com/problems/perfect-squares/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given an integer `n`, return *the least number of perfect square numbers that sum to* `n`.

A **perfect square** is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, `1`, `4`, `9`, and `16` are perfect squares while `3` and `11` are not.

 

**Example 1:**

```
Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
```

**Example 2:**

```
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
```

 

**Constraints:**

- `1 <= n <= 104`

---

## 💡 Solution Explanation

Dynamic programming / memoized recursion approach storing overlapping subproblems to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.py)**

```python
class Solution:
    # DP
    # Time: O(n(sqrt(n)))
    # Space O(n)
    def numSquares(self, n: int) -> int:
        # dp[i]: number of perfect square that sum to n
        # The first perfect square is 1
        dp = [i for i in range(n+1)]
        
        # The second perfect square is 4. Which is 2*2.
        # We go from there
        # Array with all perfect squares in the range (4, sqrt(n))
        squares = [i**2 for i in range(2, n) if i**2 <= n]
       
        for square in squares:
            for i in range(square, n+1):
                dp[i] = min(dp[i-square] + 1, dp[i])
            
        return dp[-1]
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
