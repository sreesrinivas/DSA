# [1020. Number of Enclaves](https://leetcode.com/problems/number-of-enclaves/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given an `m x n` binary matrix `grid`, where `0` represents a sea cell and `1` represents a land cell.

A **move** consists of walking from one land cell to another adjacent (**4-directionally**) land cell or walking off the boundary of the `grid`.

Return *the number of land cells in* `grid` *for which we cannot walk off the boundary of the grid in any number of **moves***.

 

**Example 1:**

```
Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
```

**Example 2:**

```
Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.
```

 

**Constraints:**

- `m == grid.length`

- `n == grid[i].length`

- `1 <= m, n <= 500`

- `grid[i][j]` is either `0` or `1`.

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
class Solution(object):
    def numEnclaves(self, A):
        visited = set()
        result = 0
        for i in range(len(A)):
            for j in range(len(A[0])):
                if A[i][j] == 1 and (i, j) not in visited:
                    temp = self.dfs(A, visited, i, j)
                    if temp > 0:
                        result += temp
        return result

    def dfs(self, A, visited, i, j):
        if i < 0 or i == len(A) or j < 0 or j == len(A[0]):
            return -1
        if A[i][j] == 0:
            return 0
        if (i, j) in visited:
            return 0
        visited.add((i, j))
        total = 1
        top = self.dfs(A, visited, i-1, j)
        bottom = self.dfs(A, visited, i+1, j)
        left = self.dfs(A, visited, i, j-1)
        right = self.dfs(A, visited, i, j+1)
        if top == -1 or bottom == -1 or left == -1 or right == -1:
            return -1
        return total + top + bottom + left + right
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
