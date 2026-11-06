# [883. Projection Area of 3D Shapes](https://leetcode.com/problems/projection-area-of-3d-shapes/)

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Language: JavaScript](https://img.shields.io/badge/Language-JavaScript-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given an `n x n` `grid` where we place some `1 x 1 x 1` cubes that are axis-aligned with the `x`, `y`, and `z` axes.

Each value `v = grid[i][j]` represents a tower of `v` cubes placed on top of the cell `(i, j)`.

We view the projection of these cubes onto the `xy`, `yz`, and `zx` planes.

A **projection** is like a shadow, that maps our **3-dimensional** figure to a **2-dimensional** plane. We are viewing the "shadow" when looking at the cubes from the top, the front, and the side.

Return *the total area of all three projections*.

 

**Example 1:**

```
Input: grid = [[1,2],[3,4]]
Output: 17
Explanation: Here are the three projections ("shadows") of the shape made with each axis-aligned plane.
```

**Example 2:**

```
Input: grid = [[2]]
Output: 5
```

**Example 3:**

```
Input: grid = [[1,0],[0,2]]
Output: 8
```

 

**Constraints:**

- `n == grid.length == grid[i].length`

- `1 <= n <= 50`

- `0 <= grid[i][j] <= 50`

---

## 💡 Solution Explanation

Exhaustive / multi-pass search across candidate elements to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.js)**

```javascript
const projectionArea=t=>{let e=0;front=0,side=0;for(let r=0;r<t.length;r++){let n=0,o=0;for(let l=0;l<t[r].length;l++)t[r][l]>0&&e++,n=Math.max(n,t[r][l]),o=Math.max(o,t[l][r]);front+=n,side+=o}return e+front+side};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
