# [1017. Convert to Base -2](https://leetcode.com/problems/convert-to-base-2/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given an integer `n`, return *a binary string representing its representation in base* `-2`.

**Note** that the returned string should not have leading zeros unless the string is `"0"`.

 

**Example 1:**

```
Input: n = 2
Output: "110"
Explantion: (-2)2 + (-2)1 = 2
```

**Example 2:**

```
Input: n = 3
Output: "111"
Explantion: (-2)2 + (-2)1 + (-2)0 = 3
```

**Example 3:**

```
Input: n = 4
Output: "100"
Explantion: (-2)2 = 4
```

 

**Constraints:**

- `0 <= n <= 109`

---

## 💡 Solution Explanation

Exhaustive / multi-pass search across candidate elements to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.py)**

```python
class Solution:
    def baseNeg2(self, N: int) -> str:
        neg = [1 << i for i in range(1, 33, 2)]
        for mask in neg:
            if N & mask: N += mask*2
        return bin(N)[2:]
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
