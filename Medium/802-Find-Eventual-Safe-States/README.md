# [802. Find Eventual Safe States](https://leetcode.com/problems/find-eventual-safe-states/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

There is a directed graph of `n` nodes with each node labeled from `0` to `n - 1`. The graph is represented by a **0-indexed** 2D integer array `graph` where `graph[i]` is an integer array of nodes adjacent to node `i`, meaning there is an edge from node `i` to each node in `graph[i]`.

A node is a **terminal node** if there are no outgoing edges. A node is a **safe node** if every possible path starting from that node leads to a **terminal node** (or another safe node).

Return *an array containing all the **safe nodes** of the graph*. The answer should be sorted in **ascending** order.

 

**Example 1:**

```
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Explanation: The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.
```

**Example 2:**

```
Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
Output: [4]
Explanation:
Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.
```

 

**Constraints:**

- `n == graph.length`

- `1 <= n <= 104`

- `0 <= graph[i].length <= n`

- `0 <= graph[i][j] <= n - 1`

- `graph[i]` is sorted in a strictly increasing order.

- The graph may contain self-loops.

- The number of edges in the graph will be in the range `[1, 4 * 104]`.

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
    int n;
    vector<int> degreein;
    vector< vector<int> > rGraph;
    vector<int> ans;
    
    void init(vector<vector<int>>& G){
        n = G.size();
        degreein = vector<int>(n,0);
        rGraph.resize(n, vector<int>(0) );
        
        for (int u=0; u<n; u++){
            for (int v:G[u]){
                rGraph[v].push_back(u);
                degreein[u]++;
            }
        }
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        init(graph);
        queue<int> que;
        for (int i=0; i<n; i++){
            if (degreein[i]==0) que.push(i);
        }
        while (que.size()){
            int u = que.front(); que.pop();
            ans.push_back(u);
            for (int v:rGraph[u]){
                degreein[v]--;
                if (degreein[v]==0) que.push(v);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
