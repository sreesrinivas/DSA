# [807. Max Increase to Keep City Skyline](https://leetcode.com/problems/max-increase-to-keep-city-skyline/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

There is a city composed of `n x n` blocks, where each block contains a single building shaped like a vertical square prism. You are given a **0-indexed** `n x n` integer matrix `grid` where `grid[r][c]` represents the **height** of the building located in the block at row `r` and column `c`.

A city's **skyline** is the outer contour formed by all the building when viewing the side of the city from a distance. The **skyline** from each cardinal direction north, east, south, and west may be different.

We are allowed to increase the height of **any number of buildings by any amount** (the amount can be different per building). The height of a `0`-height building can also be increased. However, increasing the height of a building should **not** affect the city's **skyline** from any cardinal direction.

Return *the **maximum total sum** that the height of the buildings can be increased by **without** changing the city's **skyline** from any cardinal direction*.

 

**Example 1:**

```
Input: grid = [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]
Output: 35
Explanation: The building heights are shown in the center of the above image.
The skylines when viewed from each cardinal direction are drawn in red.
The grid after increasing the height of buildings without affecting skylines is:
gridNew = [ [8, 4, 8, 7],
            [7, 4, 7, 7],
            [9, 4, 8, 7],
            [3, 3, 3, 3] ]
```

**Example 2:**

```
Input: grid = [[0,0,0],[0,0,0],[0,0,0]]
Output: 0
Explanation: Increasing the height of any building will result in the skyline changing.
```

 

**Constraints:**

- `n == grid.length`

- `n == grid[r].length`

- `2 <= n <= 50`

- `0 <= grid[r][c] <= 100`

---

## 💡 Solution Explanation

Exhaustive / multi-pass search across candidate elements to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.java)**

```java
class Solution {
    public int maxIncreaseKeepingSkyline(int[][] grid) {
        int row[] = new int[grid.length];
        int col[] = new int[grid[0].length];
        int rowMax = Integer.MIN_VALUE;
        int colMax = Integer.MIN_VALUE;
        int buildingHeightIncreased = 0;

        for (int i = 0; i < grid.length; i++) {
            rowMax = Integer.MIN_VALUE;
            colMax = Integer.MIN_VALUE;

            for (int j = 0; j < grid[0].length; j++) {
                rowMax = grid[i][j] > rowMax ? grid[i][j] : rowMax;
                colMax = grid[j][i] > colMax ? grid[j][i] : colMax;
            }

            row[i] = rowMax;
            col[i] = colMax;
        }

        for (int i = 0; i < grid.length; i++)
            for (int j = 0; j < grid[0].length; j++)
                buildingHeightIncreased += Math.min(row[i], col[j]) - grid[i][j];

        return buildingHeightIncreased;
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
