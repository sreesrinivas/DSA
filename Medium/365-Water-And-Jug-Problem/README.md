# [365. Water and Jug Problem](https://leetcode.com/problems/water-and-jug-problem/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given two jugs with capacities `x` liters and `y` liters. You have an infinite water supply. Return whether the total amount of water in both jugs may reach `target` using the following operations:

- Fill either jug completely with water.

- Completely empty either jug.

- Pour water from one jug into another until the receiving jug is full, or the transferring jug is empty.

 

**Example 1: **

**Input: **  x = 3, y = 5, target = 4 

**Output: **  true 

**Explanation:**

Follow these steps to reach a total of 4 liters:

- Fill the 5-liter jug (0, 5).

- Pour from the 5-liter jug into the 3-liter jug, leaving 2 liters (3, 2).

- Empty the 3-liter jug (0, 2).

- Transfer the 2 liters from the 5-liter jug to the 3-liter jug (2, 0).

- Fill the 5-liter jug again (2, 5).

- Pour from the 5-liter jug into the 3-liter jug until the 3-liter jug is full. This leaves 4 liters in the 5-liter jug (3, 4).

- Empty the 3-liter jug. Now, you have exactly 4 liters in the 5-liter jug (0, 4).

Reference: The Die Hard example.

**Example 2: **

**Input: **  x = 2, y = 6, target = 5 

**Output: **  false 

**Example 3: **

**Input: **  x = 1, y = 2, target = 3 

**Output: **  true 

**Explanation:** Fill both jugs. The total amount of water in both jugs is equal to 3 now.

 

**Constraints:**

- `1 <= x, y, target <= 103`

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
from math import gcd
class Solution:
    def canMeasureWater(self, x: int, y: int, target: int) -> bool:
        if target>x+y:
            return False
        return target%gcd(x,y)==0

        #There's a trick for this : we can say that the jugs can be filled as per the required target only if the target in not greater than sum of containers capacity and also should satisfy the condition that target when divided by gcd of containers capacity should return 0 as remainder!!!!
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
