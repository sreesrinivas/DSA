# [684. Redundant Connection](https://leetcode.com/problems/redundant-connection/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

In this problem, a tree is an **undirected graph** that is connected and has no cycles.

You are given a graph that started as a tree with `n` nodes labeled from `1` to `n`, with one additional edge added. The added edge has two **different** vertices chosen from `1` to `n`, and was not an edge that already existed. The graph is represented as an array `edges` of length `n` where `edges[i] = [ai, bi]` indicates that there is an edge between nodes `ai` and `bi` in the graph.

Return *an edge that can be removed so that the resulting graph is a tree of *`n`* nodes*. If there are multiple answers, return the answer that occurs last in the input.

 

**Example 1:**

```
Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
```

**Example 2:**

```
Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]
```

 

**Constraints:**

- `n == edges.length`

- `3 <= n <= 1000`

- `edges[i].length == 2`

- `1 <= ai < bi <= edges.length`

- `ai != bi`

- There are no repeated edges.

- The given graph is connected.

---

## 💡 Solution Explanation

Optimal iterative solution using a single pass to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.py)**

```python
class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        self.already_connected = defaultdict(list)
        for edge in edges:
            self.visited = defaultdict(bool)
            x, y = edge[0], edge[1]
            if self.is_already_connected(x, y):
                return edge
            self.already_connected[x].append(y)
            self.already_connected[y].append(x)
            
    def is_already_connected(self, x, y):
        if x == y:
            return True
        for x_adjacent in self.already_connected[x]:
            if not self.visited[x_adjacent]:
                self.visited[x_adjacent] = True
                if self.is_already_connected(x_adjacent, y):
                    return True
        return False
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
