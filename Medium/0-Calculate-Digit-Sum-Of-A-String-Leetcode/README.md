# [0. Calculate Digit Sum of a String - LeetCode](https://leetcode.com/problems/calculate-digit-sum-of-a-string/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Solve the problem **Calculate Digit Sum of a String - LeetCode** on LeetCode: [Problem Description](https://leetcode.com/problems/calculate-digit-sum-of-a-string/)

---

## 💡 Solution Explanation

Hash-table lookup approach enabling constant-time O(1) element retrieval to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.py)**

```python
class Solution:
    def digitSum(self, s: str, k: int) -> str:
        while len(s) > k:
            s = ''.join(str(sum(map(int, g))) for g in batched(s, k))
        return s
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
