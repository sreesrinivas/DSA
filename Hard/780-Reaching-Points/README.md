# [780. Reaching Points](https://leetcode.com/problems/reaching-points/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given four integers `sx`, `sy`, `tx`, and `ty`, return `true`* if it is possible to convert the point *`(sx, sy)`* to the point *`(tx, ty)` *through some operations**, or *`false`* otherwise*.

The allowed operation on some point `(x, y)` is to convert it to either `(x, x + y)` or `(x + y, y)`.

 

**Example 1:**

```
Input: sx = 1, sy = 1, tx = 3, ty = 5
Output: true
Explanation:
One series of moves that transforms the starting point to the target is:
(1, 1) -> (1, 2)
(1, 2) -> (3, 2)
(3, 2) -> (3, 5)
```

**Example 2:**

```
Input: sx = 1, sy = 1, tx = 2, ty = 2
Output: false
```

**Example 3:**

```
Input: sx = 1, sy = 1, tx = 1, ty = 1
Output: true
```

 

**Constraints:**

- `1 <= sx, sy, tx, ty <= 109`

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
    public boolean reachingPoints(int sx, int sy, int tx, int ty) {
		 while(tx >= sx && ty >= sy){
            if(tx > ty) {
                if(sy == ty) return (tx - sx) % ty == 0;
                tx %= ty;
            }
            else {
                if(sx == tx) return (ty - sy) % tx == 0;
                ty %= tx;
            }
        }
        return false;
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
