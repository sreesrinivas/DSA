# [600. Non-negative Integers without Consecutive Ones](https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given a positive integer `n`, return the number of the integers in the range `[0, n]` whose binary representations **do not** contain consecutive ones.

 

**Example 1:**

```
Input: n = 5
Output: 5
Explanation:
Here are the non-negative integers <= 5 with their corresponding binary representations:
0 : 0
1 : 1
2 : 10
3 : 11
4 : 100
5 : 101
Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule.
```

**Example 2:**

```
Input: n = 1
Output: 2
```

**Example 3:**

```
Input: n = 2
Output: 3
```

 

**Constraints:**

- `1 <= n <= 109`

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
    def findIntegers(self, n: int) -> int:
        dp = [0] * 32

        dp[0] = 1
        dp[1] = 2

        for i in range(2, 32):
            dp[i] = dp[i - 1] + dp[i - 2]

        ans = 0
        prev_bit = 0

        for i in range(30, -1, -1):
            if n & (1 << i):
                # Put 0 instead of 1 at this position.
                # The remaining i bits have dp[i] valid combinations.
                ans += dp[i]

                # n contains consecutive 1s, so n itself is invalid.
                if prev_bit == 1:
                    return ans

                prev_bit = 1
            else:
                prev_bit = 0

        # n itself is valid.
        return ans + 1
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
