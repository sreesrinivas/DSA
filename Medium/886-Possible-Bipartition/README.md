# [886. Possible Bipartition](https://leetcode.com/problems/possible-bipartition/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

We want to split a group of `n` people (labeled from `1` to `n`) into two groups of **any size**. Each person may dislike some other people, and they should not go into the same group.

Given the integer `n` and the array `dislikes` where `dislikes[i] = [ai, bi]` indicates that the person labeled `ai` does not like the person labeled `bi`, return `true` *if it is possible to split everyone into two groups in this way*.

 

**Example 1:**

```
Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: The first group has [1,4], and the second group has [2,3].
```

**Example 2:**

```
Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Explanation: We need at least 3 groups to divide them. We cannot put them in two groups.
```

 

**Constraints:**

- `1 <= n <= 2000`

- `0 <= dislikes.length <= 104`

- `dislikes[i].length == 2`

- `1 <= ai < bi <= n`

- All the pairs of `dislikes` are **unique**.

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
#define WHITE 0
#define RED 1
#define BLUE 2

class Solution 
{
public:
    bool possibleBipartition(int N, vector<vector<int>> &edges) 
    {
        vector<vector<int>> adj(N + 1); // adjacency list for undirected graph
        vector<int> color(N + 1, WHITE); // color of each vertex in graph, initially WHITE
        vector<bool> explored(N + 1, false); // to check if each vertex has been explored exactly once
        
        // create adjacency list from given edges
        for (auto &edge: edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // print adjacency list (comment out before submitting)
        for (int i = 0; i <= N; ++i)
        {
            cout << "adj[" << i << "]: ";
            for (int j = 0; j < adj[i].size(); ++j)
            {
                cout << adj[i][j] << " ";
            }
            cout << "\n";
        }
        
        // queue to perform BFS over each connected component in the graph
        // while performing BFS, we check if we encounter any conflicts while
        // coloring the vertices of the graph
        // conflicts indicate that bi-partition is not possible
        queue<int> q;
        
        for (int i = 1; i <= N; ++i)
        {
            if (!explored[i])
            {
                // this component has not been colored yet
				// we color the first vertex RED and push it into the queue
                color[i] = RED;
                q.push(i);
                
                // perform BFS from vertex i
                while (!q.empty())
                {
                    int u = q.front();
                    q.pop();
                    
                    // check if u is already explored 
                    if (explored[u])
                    {
                        continue;
                    }
                    
                    explored[u] = true;
                    
                    // for each neighbor of u, execute this loop
                    for (auto v: adj[u])
                    {
                        // v is u's neighboring vertex
                        
                        // checking if there's any conflict in coloring
                        if (color[v] == color[u])
                        {
							// conflict edge found, so we return false 
							// as bi-partition will not be possible
                            return false;
                        }
                        
                        // we color v with the opposite color of u
                        if (color[u] == RED)
                        {
                            color[v] = BLUE;
                        }
                        else 
                        {
                            color[v] = RED;
                        }
                        
                        q.push(v);
                    }
                }
            }
        }
        
        // if no conflicts encountered then graph must be bipartite
        // so we return true
        
        return true;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
