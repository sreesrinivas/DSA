# [633. Sum of Square Numbers](https://leetcode.com/problems/sum-of-square-numbers/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given a non-negative integer `c`, decide whether there're two integers `a` and `b` such that `a2 + b2 = c`.

 

**Example 1:**

```
Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5
```

**Example 2:**

```
Input: c = 3
Output: false
```

 

**Constraints:**

- `0 <= c <= 231 - 1`

---

## 💡 Solution Explanation

Optimal iterative solution using a single pass to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.java)**

```java
class Solution {
    public boolean judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; a++) {   // Iterate through all possible values of `a`
            double b = Math.sqrt(c - a * a);  // Compute `b` as the square root of `c - a^2`
            if (b == (int)b) {                 // Check if `b` is an integer
                return true;                   // If `b` is an integer, return true
            }
        }
        return false;                          // If no such pair `(a, b)` is found, return false
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
