# [994. Rotting Oranges](https://leetcode.com/problems/rotting-oranges/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given an `m x n` `grid` where each cell can have one of three values:

- `0` representing an empty cell,

- `1` representing a fresh orange, or

- `2` representing a rotten orange.

Every minute, any fresh orange that is **4-directionally adjacent** to a rotten orange becomes rotten.

Return *the minimum number of minutes that must elapse until no cell has a fresh orange*. If *this is impossible, return* `-1`.

 

**Example 1:**

```
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
```

**Example 2:**

```
Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
```

**Example 3:**

```
Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
```

 

**Constraints:**

- `m == grid.length`

- `n == grid[i].length`

- `1 <= m, n <= 10`

- `grid[i][j]` is `0`, `1`, or `2`.

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
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        visited = grid
        q = collections.deque()
        countFreshOrange = 0
        for i in range(m):
            for j in range(n):
                if visited[i][j] == 2:
                    q.append((i, j))
                if visited[i][j] == 1:
                    countFreshOrange += 1
        if countFreshOrange == 0:
            return 0
        if not q:
            return -1
        
        minutes = -1
        dirs = [(1, 0), (-1, 0), (0, -1), (0, 1)]
        while q:
            size = len(q)
            while size > 0:
                x, y = q.popleft()
                size -= 1
                for dx, dy in dirs:
                    i, j = x + dx, y + dy
                    if 0 <= i < m and 0 <= j < n and visited[i][j] == 1:
                        visited[i][j] = 2
                        countFreshOrange -= 1
                        q.append((i, j))
            minutes += 1
        
        if countFreshOrange == 0:
            return minutes
        return -1
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
