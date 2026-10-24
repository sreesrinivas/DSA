# [554. Brick Wall](https://leetcode.com/problems/brick-wall/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

There is a rectangular brick wall in front of you with `n` rows of bricks. The `ith` row has some number of bricks each of the same height (i.e., one unit) but they can be of different widths. The total width of each row is the same.

Draw a vertical line from the top to the bottom and cross the least bricks. If your line goes through the edge of a brick, then the brick is not considered as crossed. You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will obviously cross no bricks.

Given the 2D array `wall` that contains the information about the wall, return *the minimum number of crossed bricks after drawing such a vertical line*.

 

**Example 1:**

```
Input: wall = [[1,2,2,1],[3,1,2],[1,3,2],[2,4],[3,1,2],[1,3,1,1]]
Output: 2
```

**Example 2:**

```
Input: wall = [[1],[1],[1]]
Output: 3
```

 

**Constraints:**

- `n == wall.length`

- `1 <= n <= 104`

- `1 <= wall[i].length <= 104`

- `1 <= sum(wall[i].length) <= 2 * 104`

- `sum(wall[i])` is the same for each row `i`.

- `1 <= wall[i][j] <= 231 - 1`

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
class Solution(object):
    def leastBricks(self, wall):
        edge_counts = {}
        for row in wall:
            edge = 0
            for brick in row[:-1]:
                edge += brick
                edge_counts[edge] = edge_counts.get(edge, 0) + 1
        max_edges = max(edge_counts.values()) if edge_counts else 0
        return len(wall) - max_edges
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
