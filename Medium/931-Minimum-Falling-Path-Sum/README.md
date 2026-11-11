# [931. Minimum Falling Path Sum](https://leetcode.com/problems/minimum-falling-path-sum/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given an `n x n` array of integers `matrix`, return *the **minimum sum** of any **falling path** through* `matrix`.

A **falling path** starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position `(row, col)` will be `(row + 1, col - 1)`, `(row + 1, col)`, or `(row + 1, col + 1)`.

 

**Example 1:**

```
Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
```

**Example 2:**

```
Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.
```

 

**Constraints:**

- `n == matrix.length == matrix[i].length`

- `1 <= n <= 100`

- `-100 <= matrix[i][j] <= 100`

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
int dp[101][101];
int n;

int find(int x, int y, vector<vector<int>>& g)
{
    if(x == n)
        return 0;

    if(dp[x][y] != -100000)
        return dp[x][y];

    int ans = g[x][y] + find(x+1, y, g);

    if(y-1>=0)
        ans = min(ans, g[x][y] + find(x+1, y-1, g) );

    if(y+1!=n)
        ans = min(ans, g[x][y] + find(x+1, y+1, g) );
    
    return dp[x][y] = ans;
}

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        
        n = mat.size();
        int ans = 1e9;
        
        for(int i=0; i<101; ++i)
            for(int j=0; j<101; ++j)
                dp[i][j] = -100000;

        for(int i=0; i<mat.size(); ++i)
            ans = min(ans, find(0, i, mat));
        
        return ans;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
