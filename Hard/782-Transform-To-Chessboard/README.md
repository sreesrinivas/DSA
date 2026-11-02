# [782. Transform to Chessboard](https://leetcode.com/problems/transform-to-chessboard/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given an `n x n` binary grid `board`. In each move, you can swap any two rows with each other, or any two columns with each other.

Return *the minimum number of moves to transform the board into a **chessboard board***. If the task is impossible, return `-1`.

A **chessboard board** is a board where no `0`'s and no `1`'s are 4-directionally adjacent.

 

**Example 1:**

```
Input: board = [[0,1,1,0],[0,1,1,0],[1,0,0,1],[1,0,0,1]]
Output: 2
Explanation: One potential sequence of moves is shown.
The first move swaps the first and second column.
The second move swaps the second and third row.
```

**Example 2:**

```
Input: board = [[0,1],[1,0]]
Output: 0
Explanation: Also note that the board with 0 in the top left corner, is also a valid chessboard.
```

**Example 3:**

```
Input: board = [[1,0],[1,0]]
Output: -1
Explanation: No matter what sequence of moves you make, you cannot end with a valid chessboard.
```

 

**Constraints:**

- `n == board.length`

- `n == board[i].length`

- `2 <= n <= 30`

- `board[i][j]` is either `0` or `1`.

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
    int movesToChessboard(vector<vector<int>>& board) {
        int n = board.size();
        
		//////////////////////////////////////////////////////////////////////////////
		//Secon rule
		//////////////////////////////////////////////////////////////////////////////
        //count how many columns we have for type1(column equal to the first column) and type2(column that have each cell different than the first column)
        int countCol_type1 = 1; //this is equal to 1 because we already count the first column
        int countCol_type2 =0;

        //count how many rows we have for type1(rows equal to the first row) and type2(rows that have each cell different than the first row)
        int countRow_type1 = 1; //this is equal to 1 because we already count the first row
        int countRow_type2 = 0;

        //check if the board is a valid board (by valid I mean that it can be a chess board. Scroll above to know the how to know if it's valid)
        for (int j = 1; j < n; j++) {

            //check horizontaly (each columns of the horizontal lane)
            if (board[0][j] == board[0][0]) {
                countCol_type1++;

                //check if all cell of the j column is equal to the first column (if not means that it is a invalid board, so return -1)
                for (int i = 1; i < n; i++) {
                    if (board[i][j] != board[i][0])return -1;
                }
            }
            else {
                countCol_type2++;

                //check if all cell of the j column is different to the first column (if not means that it is a invalid board, so return -1)
                for (int i = 1; i < n; i++) {
                    if (board[i][j] == board[i][0])return -1;
                }
            }

            //check vertically (each rows of the vertical lane)
            if (board[j][0] == board[0][0]) {
                countRow_type1++;

                //check if all cell of the j row is equal to the first row (if not means that it is a invalid board, so return -1)
                for (int i = 1; i < n; i++) {
                    if (board[j][i] != board[0][i])return -1;
                }
            }
            else {
                countRow_type2++;

                //check if all cell of the j row is different to the first row (if not means that it is a invalid board, so return -1)
                for (int i = 1; i < n; i++) {
                    if (board[j][i] == board[0][i])return -1;
                }
            }
        }


		//////////////////////////////////////////////////////////////////////////////
		//first rule
		//////////////////////////////////////////////////////////////////////////////
        //we have to make sure that n. of type1 is equal to type2 of only with 1 of difference (when n = odd number)
        //if it isn't means that the board is invalid) 
        if (abs(countCol_type1 - countCol_type2) > 1) return -1;    // if type1 - type2 != -1,0,1 then return -1
        if (abs(countRow_type1 - countRow_type2) > 1) return -1;
		
		
		//////////////////////////////////////////////////////////////////////////////
		//Calculate how many steps we need to do to get the chess board
		//////////////////////////////////////////////////////////////////////////////
        int countRow = 0;
        int countCol = 0;
        //count how many moves need to make the board as a chessboard that start with 0 
        for (int j = 0; j < n; j++) {
            if (board[0][j] != j % 2)countCol++;
            if (board[j][0] != j % 2)countRow++;
        }

        //count how many moves need to make the board as a chessboard (horizontally) that start with 1 
        int countRow2 = n - countRow;
        int countCol2 = n - countCol;

        int res = 0;
        //if countRow2 is an odd number return countRow/2
        if (countRow2 % 2)res+= countRow / 2;
        //if countRow is an odd number return countRow2/2
        else if (countRow % 2)res+= countRow2 / 2;
        //if countRow and countRow2 are even numbers return the smaller one
        else res += min(countRow, countRow2) / 2;

        //if countCol2 is an odd number return countCol/2
        if (countCol2 % 2)res += countCol / 2;
        //if countCol is an odd number return countCol2/2
        else if (countCol % 2)res += countCol2 / 2;
        //if countCol and countCol2 are even numbers return the smaller one
        else res += min(countCol, countCol2) / 2;

        return res;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
