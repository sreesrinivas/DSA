# [970. Powerful Integers](https://leetcode.com/problems/powerful-integers/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given three integers `x`, `y`, and `bound`, return *a list of all the **powerful integers** that have a value less than or equal to* `bound`.

An integer is **powerful** if it can be represented as `xi + yj` for some integers `i >= 0` and `j >= 0`.

You may return the answer in **any order**. In your answer, each value should occur **at most once**.

 

**Example 1:**

```
Input: x = 2, y = 3, bound = 10
Output: [2,3,4,5,7,9,10]
Explanation:
2 = 20 + 30
3 = 21 + 30
4 = 20 + 31
5 = 21 + 31
7 = 22 + 31
9 = 23 + 30
10 = 20 + 32
```

**Example 2:**

```
Input: x = 3, y = 5, bound = 15
Output: [2,4,6,8,10,14]
```

 

**Constraints:**

- `1 <= x, y <= 100`

- `0 <= bound <= 106`

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
    def powerfulIntegers(self, x: int, y: int, bound: int) -> List[int]:
        result = set()
        a = 1
        while a < bound:
            b = 1
            while a + b <= bound:
                result.add(a + b)
                if y == 1:
                    break
                b *= y
            if x == 1:
                break
            a *= x
        return list(result)
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
