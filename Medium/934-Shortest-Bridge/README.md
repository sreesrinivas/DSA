# [934. Shortest Bridge](https://leetcode.com/problems/shortest-bridge/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given an `n x n` binary matrix `grid` where `1` represents land and `0` represents water.

An **island** is a 4-directionally connected group of `1`'s not connected to any other `1`'s. There are **exactly two islands** in `grid`.

You may change `0`'s to `1`'s to connect the two islands to form **one island**.

Return *the smallest number of *`0`*'s you must flip to connect the two islands*.

 

**Example 1:**

```
Input: grid = [[0,1],[1,0]]
Output: 1
```

**Example 2:**

```
Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2
```

**Example 3:**

```
Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1
```

 

**Constraints:**

- `n == grid.length == grid[i].length`

- `2 <= n <= 100`

- `grid[i][j]` is either `0` or `1`.

- There are exactly two islands in `grid`.

---

## 💡 Solution Explanation

Exhaustive / multi-pass search across candidate elements to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.cpp)**

```cpp
class Solution {
public:
    int n;
    int directions[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
    queue<vector<int>> q;

    void dfs(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& visited) {
        visited[r][c] = true;
        for (auto& dir : directions) {
            int nr = r + dir[0], nc = c + dir[1];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                if (grid[nr][nc] == 0) {
                    visited[nr][nc] = true;
                    q.push({nr, nc, 1});
                } else {
                    dfs(grid, nr, nc, visited);
                }
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        bool found = false;

        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, visited);
                    found = true;
                    break;
                }
            }
        }

        while (!q.empty()) {
            auto curr = q.front(); q.pop();
            int r = curr[0], c = curr[1], dist = curr[2];

            for (auto& dir : directions) {
                int nr = r + dir[0], nc = c + dir[1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    if (grid[nr][nc] == 1) return dist;
                    visited[nr][nc] = true;
                    q.push({nr, nc, dist + 1});
                }
            }
        }
        return 0;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
