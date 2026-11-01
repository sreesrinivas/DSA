# [765. Couples Holding Hands](https://leetcode.com/problems/couples-holding-hands/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

There are `n` couples sitting in `2n` seats arranged in a row and want to hold hands.

The people and seats are represented by an integer array `row` where `row[i]` is the ID of the person sitting in the `ith` seat. The couples are numbered in order, the first couple being `(0, 1)`, the second couple being `(2, 3)`, and so on with the last couple being `(2n - 2, 2n - 1)`.

Return *the minimum number of swaps so that every couple is sitting side by side*. A swap consists of choosing any two people, then they stand up and switch seats.

 

**Example 1:**

```
Input: row = [0,2,1,3]
Output: 1
Explanation: We only need to swap the second (row[1]) and third (row[2]) person.
```

**Example 2:**

```
Input: row = [3,2,0,1]
Output: 0
Explanation: All couples are already seated side by side.
```

 

**Constraints:**

- `2n == row.length`

- `2 <= n <= 30`​​​​​​​

- `0 <= row[i] < 2n`

- All the elements of `row` are **unique**.

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
//dfs to find the connected components
    void dfs(int curr,vector<vector<int> >&adj,vector<bool>&vis)
    {
        vis[curr]=true;
        for(auto x:adj[curr])
        {
            if(!vis[x])
                dfs(x,adj,vis);
        }
    }
    int minSwapsCouples(vector<int>& row) {
        int n=row.size()/2;
        vector<int>par(2*n);
        for(int i=0;i<n;i++)
        {
            par[2*i]=i;
            par[2*i+1]=i;
        }
        vector<vector<int> >adj(n);
        int connected_components=0;
        for(int i=0;i<n;i++)
        {
            int u=par[row[2*i]],v=par[row[2*i+1]];
            if(u==v)
                continue;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
               //every dfs call on new vertex corresponds to a new connected component
                connected_components++;
                dfs(i,adj,vis);
            }
            
        }
      
        return n-connected_components;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
