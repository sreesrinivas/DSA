# [794. Valid Tic-Tac-Toe State](https://leetcode.com/problems/valid-tic-tac-toe-state/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given a Tic-Tac-Toe board as a string array `board`, return `true` if and only if it is possible to reach this board position during the course of a valid tic-tac-toe game.

The board is a `3 x 3` array that consists of characters `' '`, `'X'`, and `'O'`. The `' '` character represents an empty square.

Here are the rules of Tic-Tac-Toe:

- Players take turns placing characters into empty squares `' '`.

- The first player always places `'X'` characters, while the second player always places `'O'` characters.

- `'X'` and `'O'` characters are always placed into empty squares, never filled ones.

- The game ends when there are three of the same (non-empty) character filling any row, column, or diagonal.

- The game also ends if all squares are non-empty.

- No more moves can be played if the game is over.

 

**Example 1:**

```
Input: board = ["O  ","   ","   "]
Output: false
Explanation: The first player always plays "X".
```

**Example 2:**

```
Input: board = ["XOX"," X ","   "]
Output: false
Explanation: Players take turns making moves.
```

**Example 3:**

```
Input: board = ["XOX","O O","XOX"]
Output: true
```

 

**Constraints:**

- `board.length == 3`

- `board[i].length == 3`

- `board[i][j]` is either `'X'`, `'O'`, or `' '`.

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
    bool validTicTacToe(vector<string>& board) {
        int countX = 0, countO = 0;
        for (string row : board) {
            for (char cell : row) {
                if (cell == 'X') countX++;
                if (cell == 'O') countO++;
            }
        }
        
        if (countO > countX || countX > countO + 1) return false;
        
        bool xWins = isWinner(board, 'X');
        bool oWins = isWinner(board, 'O');

        if (xWins && oWins) return false;
        if (xWins && countX != countO + 1) return false;
        if (oWins && countX != countO) return false;
        
        return true;
    }
    
    bool isWinner(vector<string>& board, char player) {
        for (int i = 0; i < 3; i++) {
            if (board[i] == string(3, player) || 
                (board[0][i] == player &&
                 board[1][i] == player &&
                 board[2][i] == player)) {
                return true;
            }
        }
        return (board[0][0] == player &&
                board[1][1] == player &&
                board[2][2] == player) ||
               (board[0][2] == player &&
                board[1][1] == player &&
                board[2][0] == player);
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
