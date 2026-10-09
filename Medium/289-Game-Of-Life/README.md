# [289. Game of Life](https://leetcode.com/problems/game-of-life/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

According to Wikipedia's article: "The **Game of Life**, also known simply as **Life**, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an `m x n` grid of cells, where each cell has an initial state: **live** (represented by a `1`) or **dead** (represented by a `0`). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

- Any live cell with fewer than two live neighbors dies as if caused by under-population.

- Any live cell with two or three live neighbors lives on to the next generation.

- Any live cell with more than three live neighbors dies, as if by over-population.

- Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

The next state of the board is determined by applying the above rules simultaneously to every cell in the current state of the `m x n` grid `board`. In this process, births and deaths occur **simultaneously**.

Given the current state of the `board`, **update** the `board` to reflect its next state.

**Note** that you do not need to return anything.

 

**Example 1:**

```
Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
```

**Example 2:**

```
Input: board = [[1,1],[1,0]]
Output: [[1,1],[1,1]]
```

 

**Constraints:**

- `m == board.length`

- `n == board[i].length`

- `1 <= m, n <= 25`

- `board[i][j]` is `0` or `1`.

 

**Follow up:**

- Could you solve it in-place? Remember that the board needs to be updated simultaneously: You cannot update some cells first and then use their updated values to update other cells.

- In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches upon the border of the array (i.e., live cells reach the border). How would you address these problems?

---

## 💡 Solution Explanation

Exhaustive / multi-pass search across candidate elements to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.java)**

```java
class Solution {

    private int countLive(int row, int col, int[][] board) {

        int count = 0;

        if (col - 1 >= 0) {

            if (row - 1 >= 0 && board[row - 1][col - 1] >= 1)
                count++;

            if (row + 1 < board.length && board[row + 1][col - 1] >= 1)
                count++;

            if (board[row][col - 1] >= 1)
                count++;
        }

        if (col + 1 < board[0].length) {

            if (row - 1 >= 0 && board[row - 1][col + 1] >= 1)
                count++;

            if (row + 1 < board.length && board[row + 1][col + 1] >= 1)
                count++;

            if (board[row][col + 1] >= 1)
                count++;
        }

        if (row - 1 >= 0 && board[row - 1][col] >= 1)
            count++;

        if (row + 1 < board.length && board[row + 1][col] >= 1)
            count++;

        return count;
    }

    public void gameOfLife(int[][] board) {

        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {

                int count = countLive(i, j, board);

                if (board[i][j] == 1) {

                    if (count != 2 && count != 3)
                        board[i][j] = 2;

                } else {

                    if (count == 3)
                        board[i][j] = -1;
                }
            }
        }

        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {

                if (board[i][j] == 2)
                    board[i][j] = 0;

                if (board[i][j] == -1)
                    board[i][j] = 1;
            }
        }
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
