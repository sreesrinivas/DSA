# [264. Ugly Number II](https://leetcode.com/problems/ugly-number-ii/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

An **ugly number** is a positive integer whose prime factors are limited to `2`, `3`, and `5`.

Given an integer `n`, return *the* `nth` ***ugly number***.

 

**Example 1:**

```
Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
```

**Example 2:**

```
Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
```

 

**Constraints:**

- `1 <= n <= 1690`

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
class Solution(object):
    def nthUglyNumber(self, n):
        &quot;&quot;&quot;
        :type n: int
        :rtype: int
        &quot;&quot;&quot;
        if n == 1: return 1
        p1, p2, p3 = 0, 0, 0 #pointers in the following list
        
        q = [0] * n
        q[0] = 1
        
        for i in range(1, n):
            t1, t2, t3 = q[p1] * 2, q[p2] * 3, q[p3] * 5
            q[i] = min(t1, t2, t3)
            if q[i] == t1: p1 += 1
            if q[i] == t2: p2 += 1
            if q[i] == t3: p3 += 1
            
        return q[-1]
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
