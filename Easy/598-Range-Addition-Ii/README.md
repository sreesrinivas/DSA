# [598. Range Addition II](https://leetcode.com/problems/range-addition-ii/)

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given an `m x n` matrix `M` initialized with all `0`'s and an array of operations `ops`, where `ops[i] = [ai, bi]` means `M[x][y]` should be incremented by one for all `0 <= x < ai` and `0 <= y < bi`.

Count and return *the number of maximum integers in the matrix after performing all the operations*.

 

**Example 1:**

```
Input: m = 3, n = 3, ops = [[2,2],[3,3]]
Output: 4
Explanation: The maximum integer in M is 2, and there are four of it in M. So return 4.
```

**Example 2:**

```
Input: m = 3, n = 3, ops = [[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3]]
Output: 4
```

**Example 3:**

```
Input: m = 3, n = 3, ops = []
Output: 9
```

 

**Constraints:**

- `1 <= m, n <= 4 * 104`

- `0 <= ops.length <= 104`

- `ops[i].length == 2`

- `1 <= ai <= m`

- `1 <= bi <= n`

---

## 💡 Solution Explanation

Optimal iterative solution using a single pass to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.java)**

```java
class Solution {
    public int maxCount(int m, int n, int[][] ops) {
        int a = m;
        int b = n;
        for(int i = 0; i < ops.length; i++){
            int x = ops[i][0];
            int y = ops[i][1];

            a = Math.min(a, x);
            b = Math.min(b, y);
        }
        return a * b;
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
