# [741. Cherry Pickup](https://leetcode.com/problems/cherry-pickup/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given an `n x n` `grid` representing a field of cherries, each cell is one of three possible integers.

- `0` means the cell is empty, so you can pass through,

- `1` means the cell contains a cherry that you can pick up and pass through, or

- `-1` means the cell contains a thorn that blocks your way.

Return *the maximum number of cherries you can collect by following the rules below*:

- Starting at the position `(0, 0)` and reaching `(n - 1, n - 1)` by moving right or down through valid path cells (cells with value `0` or `1`).

- After reaching `(n - 1, n - 1)`, returning to `(0, 0)` by moving left or up through valid path cells.

- When passing through a path cell containing a cherry, you pick it up, and the cell becomes an empty cell `0`.

- If there is no valid path between `(0, 0)` and `(n - 1, n - 1)`, then no cherries can be collected.

 

**Example 1:**

```
Input: grid = [[0,1,-1],[1,0,-1],[1,1,1]]
Output: 5
Explanation: The player started at (0, 0) and went down, down, right right to reach (2, 2).
4 cherries were picked up during this single trip, and the matrix becomes [[0,1,-1],[0,0,-1],[0,0,0]].
Then, the player went left, up, up, left to return home, picking up one more cherry.
The total number of cherries picked up is 5, and this is the maximum possible.
```

**Example 2:**

```
Input: grid = [[1,1,-1],[1,-1,1],[-1,1,1]]
Output: 0
```

 

**Constraints:**

- `n == grid.length`

- `n == grid[i].length`

- `1 <= n <= 50`

- `grid[i][j]` is `-1`, `0`, or `1`.

- `grid[0][0] != -1`

- `grid[n - 1][n - 1] != -1`

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
    def cherryPickup(self, grid: List[List[int]]) -> int:
        
        m = len(grid)
        n = len(grid[0])
        mem = [ [ [-2**31 for i in range(m)] for j in range(n) ] for k in range(m)]
        
        return max(0, self.dfs(grid, mem, m, n, 0, 0, 0, 0))
    
    def dfs(self, grid, mem, m, n, x1, y1, x2, y2):
        
        if x1>=m or x2>=m or y1 >= n or y2>=n or grid[x1][y1] == -1 or grid[x2][y2] == -1:
            return -2**31
        
        if mem[x1][y1][x2] != -2**31:
            return mem[x1][y1][x2]
        
        cherry = 0
        
        if grid[x1][y1] == 1:
            cherry+=1
        
        if x1!=x2 and grid[x2][y2] == 1:
            cherry+=1
            
        if x1==m-1 and y1==n-1:
            return cherry
        
        cherry += max(
            self.dfs(grid, mem, m, n, x1+1, y1, x2+1, y2),
            self.dfs(grid, mem, m, n, x1+1, y1, x2, y2+1),
            self.dfs(grid, mem, m, n, x1, y1+1, x2+1, y2),
            self.dfs(grid, mem, m, n, x1, y1+1, x2, y2+1),
            )
        
        mem[x1][y1][x2] = cherry
        
        return cherry
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
