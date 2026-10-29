# [685. Redundant Connection II](https://leetcode.com/problems/redundant-connection-ii/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

In this problem, a rooted tree is a **directed** graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.

The given input is a directed graph that started as a rooted tree with `n` nodes (with distinct values from `1` to `n`), with one additional directed edge added. The added edge has two different vertices chosen from `1` to `n`, and was not an edge that already existed.

The resulting graph is given as a 2D-array of `edges`. Each element of `edges` is a pair `[ui, vi]` that represents a **directed** edge connecting nodes `ui` and `vi`, where `ui` is a parent of child `vi`.

Return *an edge that can be removed so that the resulting graph is a rooted tree of* `n` *nodes*. If there are multiple answers, return the answer that occurs last in the given 2D-array.

 

**Example 1:**

```
Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
```

**Example 2:**

```
Input: edges = [[1,2],[2,3],[3,4],[4,1],[1,5]]
Output: [4,1]
```

 

**Constraints:**

- `n == edges.length`

- `3 <= n <= 1000`

- `edges[i].length == 2`

- `1 <= ui, vi <= n`

- `ui != vi`

---

## 💡 Solution Explanation

Two-pointer linear scan adjusting window boundaries based on constraints to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.cpp)**

```cpp
class UnionFind {
    vector<int> parent, rank; 
public: 
    UnionFind(int n) {
        parent.resize(n); 
        iota(parent.begin(), parent.end(), 0); 
        rank.resize(n); 
        fill(rank.begin(), rank.end(), 1); 
    }
    
    int find(int p) {
        if (p != parent[p]) 
            parent[p] = find(parent[p]); 
        return parent[p]; 
    }
    
    bool connect(int p, int q) {
        int prt = find(p), qrt = find(q); 
        if (prt == qrt) return false; 
        if (rank[prt] > rank[qrt]) swap(prt, qrt); 
        parent[prt] = qrt; 
        rank[qrt] += rank[prt]; 
        return true; 
    }
}; 


class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size(); 
        vector<int> parent(n, 0), cand0, cand1, cand2; 
        bool mult = false, cycle = false; 
        UnionFind *uf = new UnionFind(n); 
        
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1]; 
            if (parent[v-1]) {
                mult = true; 
                cand0 = {parent[v-1], v}; 
                cand1 = {u, v}; 
            } else {
                parent[v-1] = u; 
                if (!uf->connect(u-1, v-1)) {
                    cycle = true; 
                    cand2 = {u, v}; 
                }
            }
        }
        return mult && cycle ? cand0 : mult ? cand1 : cand2; 
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
