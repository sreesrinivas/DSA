# [797. All Paths From Source to Target](https://leetcode.com/problems/all-paths-from-source-to-target/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given a directed acyclic graph (**DAG**) of `n` nodes labeled from `0` to `n - 1`, find all possible paths from node `0` to node `n - 1` and return them in **any order**.

The graph is given as follows: `graph[i]` is a list of all nodes you can visit from node `i` (i.e., there is a directed edge from node `i` to node `graph[i][j]`).

 

**Example 1:**

```
Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
```

**Example 2:**

```
Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
```

 

**Constraints:**

- `n == graph.length`

- `2 <= n <= 15`

- `0 <= graph[i][j] < n`

- `graph[i][j] != i` (i.e., there will be no self-loops).

- All the elements of `graph[i]` are **unique**.

- The input graph is **guaranteed** to be a **DAG**.

---

## 💡 Solution Explanation

Two-pointer linear scan adjusting window boundaries based on constraints to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.java)**

```java
class Solution {
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        path.add(0);
        backtracking(res, graph, 0, path);
        return res;
    }
    
    private void backtracking(List<List<Integer>> res, int[][] graph, int start, List<Integer> cur) {
        if(graph[start].length==0 || start==graph.length-1) {
            if(start==graph.length-1) {
                res.add(new ArrayList<>(cur));
            }
            return;
        }
        
        for(int next:graph[start]) {
            cur.add(next);
            backtracking(res, graph, next, cur);
            cur.remove(cur.size()-1);
        }
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
