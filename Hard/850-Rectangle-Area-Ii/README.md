# [850. Rectangle Area II](https://leetcode.com/problems/rectangle-area-ii/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given a 2D array of axis-aligned `rectangles`. Each `rectangle[i] = [xi1, yi1, xi2, yi2]` denotes the `ith` rectangle where `(xi1, yi1)` are the coordinates of the **bottom-left corner**, and `(xi2, yi2)` are the coordinates of the **top-right corner**.

Calculate the **total area** covered by all `rectangles` in the plane. Any area covered by two or more rectangles should only be counted **once**.

Return *the **total area***. Since the answer may be too large, return it **modulo** `109 + 7`.

 

**Example 1:**

```
Input: rectangles = [[0,0,2,2],[1,0,2,3],[1,0,3,1]]
Output: 6
Explanation: A total area of 6 is covered by all three rectangles, as illustrated in the picture.
From (1,1) to (2,2), the green and red rectangles overlap.
From (1,0) to (2,3), all three rectangles overlap.
```

**Example 2:**

```
Input: rectangles = [[0,0,1000000000,1000000000]]
Output: 49
Explanation: The answer is 1018 modulo (109 + 7), which is 49.
```

 

**Constraints:**

- `1 <= rectangles.length <= 200`

- `rectanges[i].length == 4`

- `0 <= xi1, yi1, xi2, yi2 <= 109`

- `xi1 <= xi2`

- `yi1 <= yi2`

- All rectangles have non zero area.

---

## 💡 Solution Explanation

Exhaustive / multi-pass search across candidate elements to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(n)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.py)**

```python
class Solution:
    def rectangleArea(self, rectangles):
        xs = sorted(set([x for x1, y1, x2, y2 in rectangles for x in [x1, x2]]))
        ys = sorted(set([y for x1, y1, x2, y2 in rectangles for y in [y1, y2]]))
        x_i = {v: i for i, v in enumerate(xs)}
        y_i = {v: i for i, v in enumerate(ys)}
        m, n = len(y_i), len(x_i)
        
        grid = [[0] * m for _ in range(n)]
        for x1, y1, x2, y2 in rectangles:
            for x in range(x_i[x1], x_i[x2]):
                for y in range(y_i[y1], y_i[y2]):
                    grid[x][y] = 1

        ans = 0
        for x in range(n-1):
            for y in range(m-1):
                ans += grid[x][y]*(xs[x+1] - xs[x]) * (ys[y+1] - ys[y])
        return ans  % (10**9 + 7)
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
