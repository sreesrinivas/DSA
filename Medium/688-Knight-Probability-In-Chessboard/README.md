# [688. Knight Probability in Chessboard](https://leetcode.com/problems/knight-probability-in-chessboard/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

On an `n x n` chessboard, a knight starts at the cell `(row, column)` and attempts to make exactly `k` moves. The rows and columns are **0-indexed**, so the top-left cell is `(0, 0)`, and the bottom-right cell is `(n - 1, n - 1)`.

A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.

Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.

The knight continues moving until it has made exactly `k` moves or has moved off the chessboard.

Return *the probability that the knight remains on the board after it has stopped moving*.

 

**Example 1:**

```
Input: n = 3, k = 2, row = 0, column = 0
Output: 0.06250
Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
From each of those positions, there are also two moves that will keep the knight on the board.
The total probability the knight stays on the board is 0.0625.
```

**Example 2:**

```
Input: n = 1, k = 0, row = 0, column = 0
Output: 1.00000
```

 

**Constraints:**

- `1 <= n <= 25`

- `0 <= k <= 100`

- `0 <= row, column <= n - 1`

---

## 💡 Solution Explanation

Exhaustive / multi-pass search across candidate elements to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.py)**

```python
class Solution:
    def knightProbability(self, N: int, K: int, r: int, c: int) -> float:
        if K == 0:
            return 1
        totalMoves = 8 ** K
        dpArr = [[[0 for _ in range(K+1)] for _ in range(N)] for _ in range(N)]
        return self._getMoves(N, K, r, c, dpArr)/totalMoves
    
    def _getMoves(self, N:int, K:int, r:int, c:int, dpArr: List[List[List]]) -> None:
        if r < 0 or c < 0 or r >= N or c >= N:
            return 0
        if K == 0:
            return 1
        if dpArr[r][c][K]:
            return dpArr[r][c][K]
        places = [[1,2],[1,-2],[-1,2],[-1,-2],[-2,-1],[-2,1],[2,1],[2,-1]]
        res = 0
        for i, j in places:
            res += self._getMoves(N, K-1, r+i, c+j, dpArr)
        dpArr[r][c][K] = res
        return res
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
