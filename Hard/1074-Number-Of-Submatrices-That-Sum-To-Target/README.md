# [1074. Number of Submatrices That Sum to Target](https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: JavaScript](https://img.shields.io/badge/Language-JavaScript-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given a `matrix` and a `target`, return the number of non-empty submatrices that sum to target.

A submatrix `x1, y1, x2, y2` is the set of all cells `matrix[x][y]` with `x1 <= x <= x2` and `y1 <= y <= y2`.

Two submatrices `(x1, y1, x2, y2)` and `(x1', y1', x2', y2')` are different if they have some coordinate that is different: for example, if `x1 != x1'`.

 

**Example 1:**

```
Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
Output: 4
Explanation: The four 1x1 submatrices that only contain 0.
```

**Example 2:**

```
Input: matrix = [[1,-1],[-1,1]], target = 0
Output: 5
Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.
```

**Example 3:**

```
Input: matrix = [[904]], target = 0
Output: 0
```

 

**Constraints:**

- `1 <= matrix.length <= 100`

- `1 <= matrix[0].length <= 100`

- `-1000 <= matrix[i][j] <= 1000`

- `-10^8 <= target <= 10^8`

---

## 💡 Solution Explanation

Exhaustive / multi-pass search across candidate elements to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(n)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.js)**

```javascript
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {number}
 */
var numSubmatrixSumTarget = function(matrix, target) {

  const rows = matrix.length, cols = matrix[0].length;

  for (let row of matrix) {
    for (let i = 1; i < cols; ++i) {
      row[i] += row[i - 1];
    }
  }

  let count = 0, sum, counter;
  for (let c1 = 0; c1 < cols; ++c1) {
    for (let c2 = c1; c2 < cols; ++c2) {
      sum = 0;
      counter = new Map([[0, 1]]);
      for (let r = 0; r < rows; ++r) {
        sum += matrix[r][c2] - (c1 ? matrix[r][c1 - 1] : 0);
        if (counter.has(sum - target)) count += counter.get(sum - target);
        counter.set(sum, (counter.get(sum) || 0) + 1);
      }
    }
  }
  return count;
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
