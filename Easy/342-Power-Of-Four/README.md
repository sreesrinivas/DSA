# [342. Power of Four](https://leetcode.com/problems/power-of-four/)

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given an integer `n`, return *`true` if it is a power of four. Otherwise, return `false`*.

An integer `n` is a power of four, if there exists an integer `x` such that `n == 4x`.

 

**Example 1:**

```
Input: n = 16
Output: true
```

**Example 2:**

```
Input: n = 5
Output: false
```

**Example 3:**

```
Input: n = 1
Output: true
```

 

**Constraints:**

- `-231 <= n <= 231 - 1`

 

**Follow up:** Could you solve it without loops/recursion?

---

## 💡 Solution Explanation

Optimal iterative solution using a single pass to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.cpp)**

```cpp
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n<=0) return 0;
        int exp=31-countl_zero((unsigned)n);// log2(n)
        return (exp&1)==0 && n==1<<exp;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
