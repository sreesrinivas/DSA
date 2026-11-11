# [956. Tallest Billboard](https://leetcode.com/problems/tallest-billboard/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are installing a billboard and want it to have the largest height. The billboard will have two steel supports, one on each side. Each steel support must be an equal height.

You are given a collection of `rods` that can be welded together. For example, if you have rods of lengths `1`, `2`, and `3`, you can weld them together to make a support of length `6`.

Return *the largest possible height of your billboard installation*. If you cannot support the billboard, return `0`.

 

**Example 1:**

```
Input: rods = [1,2,3,6]
Output: 6
Explanation: We have two disjoint subsets {1,2,3} and {6}, which have the same sum = 6.
```

**Example 2:**

```
Input: rods = [1,2,3,4,5,6]
Output: 10
Explanation: We have two disjoint subsets {2,3,5} and {4,6}, which have the same sum = 10.
```

**Example 3:**

```
Input: rods = [1,2]
Output: 0
Explanation: The billboard cannot be supported, so we return 0.
```

 

**Constraints:**

- `1 <= rods.length <= 20`

- `1 <= rods[i] <= 1000`

- `sum(rods[i]) <= 5000`

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
    int dp[21][10003];
    int ans = 0 ;
public:
    int solve(int i , int sum, vector<int> & rods){
        if(i>=rods.size()) return sum == 0? 0 : -1 ; 
        if(dp[i][sum+5000]) return dp[i][sum+5000];
        int x = solve(i+1,sum + rods[i],rods);
        x = x == -1? -1 : x + rods[i];
        int y = solve(i+1,sum - rods[i],rods);
        int z = solve(i+1,sum,rods);
        return dp[i][sum + 5000] = max({x,y,z});

    }
    int tallestBillboard(vector<int>& rods) {
        memset(dp,0,sizeof(dp));
        int ans =  solve(0,0,rods);
        return ans==-1?-1:ans;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
