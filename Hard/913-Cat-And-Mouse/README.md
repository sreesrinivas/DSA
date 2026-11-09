# [913. Cat and Mouse](https://leetcode.com/problems/cat-and-mouse/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

A game on an **undirected** graph is played by two players, Mouse and Cat, who alternate turns.

The graph is given as follows: `graph[a]` is a list of all nodes `b` such that `ab` is an edge of the graph.

The mouse starts at node `1` and goes first, the cat starts at node `2` and goes second, and there is a hole at node `0`.

During each player's turn, they **must** travel along one edge of the graph that meets where they are.  For example, if the Mouse is at node 1, it **must** travel to any node in `graph[1]`.

Additionally, it is not allowed for the Cat to travel to the Hole (node `0`).

Then, the game can end in three ways:

- If ever the Cat occupies the same node as the Mouse, the Cat wins.

- If ever the Mouse reaches the Hole, the Mouse wins.

- If ever a position is repeated (i.e., the players are in the same position as a previous turn, and it is the same player's turn to move), the game is a draw.

Given a `graph`, and assuming both players play optimally, return

- `1` if the mouse wins the game,

- `2` if the cat wins the game, or

- `0` if the game is a draw.

 

**Example 1:**

```
Input: graph = [[2,5],[3],[0,4,5],[1,4,5],[2,3],[0,2,3]]
Output: 0
```

**Example 2:**

```
Input: graph = [[1,3],[0],[3],[0,2]]
Output: 1
```

 

**Constraints:**

- `3 <= graph.length <= 50`

- `1 <= graph[i].length < graph.length`

- `0 <= graph[i][j] < graph.length`

- `graph[i][j] != i`

- `graph[i]` is unique.

- The mouse and the cat can always move.

---

## 💡 Solution Explanation

Dynamic programming / memoized recursion approach storing overlapping subproblems to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.java)**

```java
class Solution {
    int[][][] dp;
    public int catMouseGame(int[][] graph) {
        int n = graph.length;
        dp = new int[2*n][n][n];
        for(int i=0; i<dp.length; i++) for(int j=0;  j<dp[0].length; j++) Arrays.fill(dp[i][j],-1);
        return seach(graph, 0, 1,2);
    }
    // t is which step, x is mouse location, y is cat location
    int seach(int[][] graph, int t, int x, int y){
        if (t == graph.length * 2) return 0;
        if (x == y) return dp[t][x][y] = 2;
        if (x == 0) return dp[t][x][y] = 1;
        if (dp[t][x][y] != -1) return dp[t][x][y];
         int who = t % 2;
         boolean flag;
        if (who == 0) { // mouse's turn
            flag = true; // by default, is cat win
            for (int i = 0; i < graph[x].length; i++) {
                int nxt = seach(graph, t + 1, graph[x][i], y);
                if (nxt == 1) return dp[t][x][y] = 1;
                else if (nxt != 2) flag = false;
            }
            if (flag) return dp[t][x][y] = 2;
            else return dp[t][x][y] = 0;
        }
        else { // cat's turn
            flag = true; // by default is mouse win
            for (int i = 0; i < graph[y].length; i++)
                if (graph[y][i] != 0) {
                    int nxt = seach(graph, t + 1, x, graph[y][i]);
                    if (nxt == 2) return dp[t][x][y] = 2;
                    else if (nxt != 1) flag = false;
                }
            if (flag) return dp[t][x][y] = 1;
            else return dp[t][x][y] = 0;
        }
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
