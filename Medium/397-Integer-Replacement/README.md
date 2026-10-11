# [397. Integer Replacement](https://leetcode.com/problems/integer-replacement/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given a positive integer `n`, you can apply one of the following operations:

- If `n` is even, replace `n` with `n / 2`.

- If `n` is odd, replace `n` with either `n + 1` or `n - 1`.

Return *the minimum number of operations needed for* `n` *to become* `1`.

 

**Example 1:**

```
Input: n = 8
Output: 3
Explanation: 8 -> 4 -> 2 -> 1
```

**Example 2:**

```
Input: n = 7
Output: 4
Explanation: 7 -> 8 -> 4 -> 2 -> 1
or 7 -> 6 -> 3 -> 2 -> 1
```

**Example 3:**

```
Input: n = 4
Output: 2
```

 

**Constraints:**

- `1 <= n <= 231 - 1`

---

## 💡 Solution Explanation

Optimal iterative solution using a single pass to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.py)**

```python
class Solution:
    def integerReplacement(self, n):
        steps = 0
        while n > 1:
            if n % 2 == 0: n //= 2
            elif n == 3 or (n & 2) == 0: n -= 1
            else: n += 1
            steps += 1
        return steps
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
