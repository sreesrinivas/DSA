# [675. Cut Off Trees for Golf Event](https://leetcode.com/problems/cut-off-trees-for-golf-event/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are asked to cut off all the trees in a forest for a golf event. The forest is represented as an `m x n` matrix. In this matrix:

- `0` means the cell cannot be walked through.

- `1` represents an empty cell that can be walked through.

- A number greater than `1` represents a tree in a cell that can be walked through, and this number is the tree's height.

In one step, you can walk in any of the four directions: north, east, south, and west. If you are standing in a cell with a tree, you can choose whether to cut it off.

You must cut off the trees in order from shortest to tallest. When you cut off a tree, the value at its cell becomes `1` (an empty cell).

Starting from the point `(0, 0)`, return *the minimum steps you need to walk to cut off all the trees*. If you cannot cut off all the trees, return `-1`.

**Note:** The input is generated such that no two trees have the same height, and there is at least one tree needs to be cut off.

 

**Example 1:**

```
Input: forest = [[1,2,3],[0,0,4],[7,6,5]]
Output: 6
Explanation: Following the path above allows you to cut off the trees from shortest to tallest in 6 steps.
```

**Example 2:**

```
Input: forest = [[1,2,3],[0,0,0],[7,6,5]]
Output: -1
Explanation: The trees in the bottom row cannot be accessed as the middle row is blocked.
```

**Example 3:**

```
Input: forest = [[2,3,4],[0,0,5],[8,7,6]]
Output: 6
Explanation: You can follow the same path as Example 1 to cut off all the trees.
Note that you can cut off the first tree at (0, 0) before making any steps.
```

 

**Constraints:**

- `m == forest.length`

- `n == forest[i].length`

- `1 <= m, n <= 50`

- `0 <= forest[i][j] <= 109`

- Heights of all trees are **distinct**.

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
    int bfs(int r,int c,int nr,int nc,vector<vector<int>>& forest) {
        if(r==nr && c==nc) return 0; 
        int m=forest.size();
        int n=forest[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{r,c}});
        vis[r][c]=1;
        int row[4]={1,-1,0,0};
        int col[4]={0,0,1,-1};
        while(!q.empty()) {
            auto [count,p]=q.front();
            q.pop();
            int a=p.first;
            int b=p.second;
            for(int i=0;i<4;i++) {
                int na=a+row[i];
                int nb=b+col[i];
                if(na>=0 && nb>=0 && na<m && nb<n && !vis[na][nb] && forest[na][nb]!=0) {
                    if(na==nr && nb==nc) return count+1;
                    vis[na][nb]=1;
                    q.push({count+1,{na,nb}});
                }
            }
        }
        return -1;
    }

    int cutOffTree(vector<vector<int>>& forest) {
        int m=forest.size();
        int n=forest[0].size();
        vector<pair<int,pair<int,int>>> v;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(forest[i][j]>1) {
                    v.push_back({forest[i][j],{i,j}});
                }
            }
        }
        sort(v.begin(),v.end());
        int count=0;
        int r=0,c=0;
        for(auto& t:v) {
            int nr=t.second.first;
            int nc=t.second.second;
            int dis=bfs(r,c,nr,nc,forest);
            if(dis==-1) return -1;
            count+=dis;
            r=nr;
            c=nc; 
        }
        return count;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
