# [764. Largest Plus Sign](https://leetcode.com/problems/largest-plus-sign/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given an integer `n`. You have an `n x n` binary grid `grid` with all values initially `1`'s except for some indices given in the array `mines`. The `ith` element of the array `mines` is defined as `mines[i] = [xi, yi]` where `grid[xi][yi] == 0`.

Return *the order of the largest **axis-aligned** plus sign of *1*'s contained in *`grid`. If there is none, return `0`.

An **axis-aligned plus sign** of `1`'s of order `k` has some center `grid[r][c] == 1` along with four arms of length `k - 1` going up, down, left, and right, and made of `1`'s. Note that there could be `0`'s or `1`'s beyond the arms of the plus sign, only the relevant area of the plus sign is checked for `1`'s.

 

**Example 1:**

```
Input: n = 5, mines = [[4,2]]
Output: 2
Explanation: In the above grid, the largest plus sign can only be of order 2. One of them is shown.
```

**Example 2:**

```
Input: n = 1, mines = [[0,0]]
Output: 0
Explanation: There is no plus sign, so return 0.
```

 

**Constraints:**

- `1 <= n <= 500`

- `1 <= mines.length <= 5000`

- `0 <= xi, yi < n`

- All the pairs `(xi, yi)` are **unique**.

---

## 💡 Solution Explanation

Dynamic programming / memoized recursion approach storing overlapping subproblems to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.cpp)**

```cpp
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<bool>> isMine(n, vector<bool>(n, false));
        for (auto& pos: mines) isMine[pos[0]][pos[1]] = true;
        int ans = 0;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                int plusSignSize = dpMaxArm(n, isMine, r, c, 0);
                for (int d = 1; d < 4; ++d)
                    plusSignSize = min(plusSignSize, dpMaxArm(n, isMine, r, c, d));
                ans = max(ans, plusSignSize);
            }
        }
        return ans;
    }

    int DIR[5] = {0, 1, 0, -1, 0};
    int memo[500][500][4] = {};
    int dpMaxArm(int n, vector<vector<bool>>& isMine, int r, int c, int d) {
        if (r < 0 or r >= n or c < 0 or c >= n or isMine[r][c]) return 0;
        if (memo[r][c][d] != 0) return memo[r][c][d];
        return memo[r][c][d] = dpMaxArm(n, isMine, r + DIR[d], c + DIR[d+1], d) + 1;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
