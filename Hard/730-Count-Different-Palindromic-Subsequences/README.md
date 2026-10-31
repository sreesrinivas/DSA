# [730. Count Different Palindromic Subsequences](https://leetcode.com/problems/count-different-palindromic-subsequences/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given a string s, return *the number of different non-empty palindromic subsequences in* `s`. Since the answer may be very large, return it **modulo** `109 + 7`.

A subsequence of a string is obtained by deleting zero or more characters from the string.

A sequence is palindromic if it is equal to the sequence reversed.

Two sequences `a1, a2, ...` and `b1, b2, ...` are different if there is some `i` for which `ai != bi`.

 

**Example 1:**

```
Input: s = "bccb"
Output: 6
Explanation: The 6 different non-empty palindromic subsequences are 'b', 'c', 'bb', 'cc', 'bcb', 'bccb'.
Note that 'bcb' is counted only once, even though it occurs twice.
```

**Example 2:**

```
Input: s = "abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba"
Output: 104860361
Explanation: There are 3104860382 different non-empty palindromic subsequences, which is 104860361 modulo 109 + 7.
```

 

**Constraints:**

- `1 <= s.length <= 1000`

- `s[i]` is either `'a'`, `'b'`, `'c'`, or `'d'`.

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
    def countPalindromicSubsequences(self, S: str) -> int:
        m = len(S)
        dp = [[1 if j==i else 0 for i in range(m)] for j in range(m)]
        
        for k in range(1,m):
            for i in range(m-k):
                j = i + k
                if S[i] != S[j]:
                    dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1]
                else:
                    l, r = i + 1, j - 1
                    while l <= r and S[l] != S[i]: l += 1
                    while l <= r and S[r] != S[j]: r -= 1
                    dp[i][j] = 2 * dp[i+1][j-1]
                    if l == r:
                        dp[i][j] += 1
                    elif l > r:
                        dp[i][j] += 2
                    else:
                        dp[i][j] -= dp[l+1][r-1]
                        
        return dp[0][m-1] % (10**9 + 7)
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
