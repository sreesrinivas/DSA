# [391. Perfect Rectangle](https://leetcode.com/problems/perfect-rectangle/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given an array `rectangles` where `rectangles[i] = [xi, yi, ai, bi]` represents an axis-aligned rectangle. The bottom-left point of the rectangle is `(xi, yi)` and the top-right point of it is `(ai, bi)`.

Return `true` *if all the rectangles together form an exact cover of a rectangular region*.

 

**Example 1:**

```
Input: rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
Output: true
Explanation: All 5 rectangles together form an exact cover of a rectangular region.
```

**Example 2:**

```
Input: rectangles = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
Output: false
Explanation: Because there is a gap between the two rectangular regions.
```

**Example 3:**

```
Input: rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
Output: false
Explanation: Because two of the rectangles overlap with each other.
```

 

**Constraints:**

- `1 <= rectangles.length <= 2 * 104`

- `rectangles[i].length == 4`

- `-105 <= xi < ai <= 105`

- `-105 <= yi < bi <= 105`

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
    def isRectangleCover(self, rectangles: List[List[int]]) -> bool:
        area = 0
        border_points = set()
        
        for x1, y1, x2, y2 in rectangles:
            area += (x2 - x1) * (y2 - y1)
            # Symmetric difference cleanly toggles points in the set
            border_points ^= {(x1, y1), (x1, y2), (x2, y1), (x2, y2)}
            
        if len(border_points) != 4:
            return False
        
        # Extract the global bounding box from the 4 remaining corners
        x1, y1, x2, y2 = (
            min(x for x, _ in border_points),
            min(y for _, y in border_points),
            max(x for x, _ in border_points),
            max(y for _, y in border_points)
        )
        
        return area == (x2 - x1) * (y2 - y1)
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
