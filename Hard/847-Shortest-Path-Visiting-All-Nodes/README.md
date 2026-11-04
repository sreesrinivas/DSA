# [847. Shortest Path Visiting All Nodes](https://leetcode.com/problems/shortest-path-visiting-all-nodes/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You have an undirected, connected graph of `n` nodes labeled from `0` to `n - 1`. You are given an array `graph` where `graph[i]` is a list of all the nodes connected with node `i` by an edge.

Return *the length of the shortest path that visits every node*. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.

 

**Example 1:**

```
Input: graph = [[1,2,3],[0],[0],[0]]
Output: 4
Explanation: One possible path is [1,0,2,0,3]
```

**Example 2:**

```
Input: graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
Output: 4
Explanation: One possible path is [0,1,4,2,3]
```

 

**Constraints:**

- `n == graph.length`

- `1 <= n <= 12`

- `0 <= graph[i].length < n`

- `graph[i]` does not contain `i`.

- If `graph[a]` contains `b`, then `graph[b]` contains `a`.

- The input graph is always connected.

---

## 💡 Solution Explanation

Exhaustive / multi-pass search across candidate elements to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(n)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.py)**

```python
class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:

        num_nodes = len(graph)  # Number of nodes in the graph
        queue = deque()
        visited = set()  # Set to store visited (node, state) tuples
      
        # Initialize the queue and visited set with all individual nodes and their bitmasks
        for node in range(num_nodes):
            state = 1 << node
            queue.append((node, state))
            visited.add((node, state))
      
        # Initialize the number of steps taken to reach all nodes
        steps = 0
      
        # Perform a BFS until a path visiting all nodes is found
        while True:
            # Iterate over nodes in the current layer
            for _ in range(len(queue)):
                current_node, state = queue.popleft()
                
                # Check if the current state has all nodes visited
                if state == (1 << num_nodes) - 1:
                    # Return the number of steps taken so far
                    return steps
              
                # Explore neighbors of the current node
                for neighbor in graph[current_node]:
                    new_state = state | (1 << neighbor)
                    # If the new state has not been visited, add it to the queue and set
                    if (neighbor, new_state) not in visited:
                        visited.add((neighbor, new_state))
                        queue.append((neighbor, new_state))
          
            # After exploring all nodes at the current depth, increment steps
            steps += 1
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
