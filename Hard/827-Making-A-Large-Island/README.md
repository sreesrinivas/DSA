# [827. Making A Large Island](https://leetcode.com/problems/making-a-large-island/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given an `n x n` binary matrix `grid`. You are allowed to change **at most one** `0` to be `1`.

Return *the size of the largest **island** in* `grid` *after applying this operation*.

An **island** is a 4-directionally connected group of `1`s.

 

**Example 1:**

```
Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
```

**Example 2:**

```
Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
```

**Example 3:**

```
Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.
```

 

**Constraints:**

- `n == grid.length`

- `n == grid[i].length`

- `1 <= n <= 500`

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
class UnionFind:
    def __init__(self, n):
        self.parent = [-1] * n
        self.size = [0] * n
    def isExist(self, u):
        return self.parent[u] >= 0
    def add(self, u):
        if self.isExist(u): return  # Only add if not existed yet!
        self.parent[u] = u
        self.size[u] = 1
    def find(self, u):
        if self.parent[u] == u: return u
        self.parent[u] = self.find(self.parent[u])  # Path compression
        return self.parent[u]
    def union(self, u, v):
        pu, pv = self.find(u), self.find(v)
        if pu == pv: return False
        if self.size[pu] <= self.size[pv]:  # Merge the smaller component to the bigger component
            self.parent[pu] = pv  # Merge u into v
            self.size[pv] += self.size[pu]
        else:
            self.parent[pv] = pu  # Merge v into u
            self.size[pu] += self.size[pv]
        return True

class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        DIR = [0, 1, 0, -1, 0]
        m, n, ans = len(grid), len(grid[0]), 0
        uf = UnionFind(m * n)

        def landNeighbors(r, c):
            for i in range(4):
                nr, nc = r + DIR[i], c + DIR[i + 1]
                neiId = nr * n + nc
                if nr < 0 or nr == m or nc < 0 or nc == n or not uf.isExist(neiId): continue
                yield neiId

        for r in range(m):
            for c in range(n):
                if grid[r][c] == 0: continue
                curId = r * n + c
                uf.add(curId)
                for neiId in landNeighbors(r, c):
                    uf.union(curId, neiId)
                p = uf.find(curId)
                ans = max(ans, uf.size[p])

        for r in range(m):
            for c in range(n):
                if grid[r][c] == 1: continue
                neiParents = set()
                for neiId in landNeighbors(r, c):
                    neiParents.add(uf.find(neiId))
                sizeFormed = 1  # Start with 1, which is matrix[r][c] when turning from 0 into 1
                for p in neiParents:
                    sizeFormed += uf.size[p]
                ans = max(ans, sizeFormed)
        return ans
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
