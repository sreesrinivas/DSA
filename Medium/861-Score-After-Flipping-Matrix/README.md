# [861. Score After Flipping Matrix](https://leetcode.com/problems/score-after-flipping-matrix/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given an `m x n` binary matrix `grid`.

A **move** consists of choosing any row or column and toggling each value in that row or column (i.e., changing all `0`'s to `1`'s, and all `1`'s to `0`'s).

Every row of the matrix is interpreted as a binary number, and the **score** of the matrix is the sum of these numbers.

Return *the highest possible **score** after making any number of **moves** (including zero moves)*.

 

**Example 1:**

```
Input: grid = [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
Output: 39
Explanation: 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
```

**Example 2:**

```
Input: grid = [[0]]
Output: 1
```

 

**Constraints:**

- `m == grid.length`

- `n == grid[i].length`

- `1 <= m, n <= 20`

- `grid[i][j]` is either `0` or `1`.

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
    void flipRow(vector<vector<int>>& A,int row,int n){
        for(int j = 0;j < n;j++){
            if(A[row][j] == 0)
                A[row][j] = 1;
            else
                A[row][j] = 0;
        }
    }
    
    void flipCol(vector<vector<int>>& A,int col,int m){
        for(int i = 0;i < m;i++){
            if(A[i][col] == 0)
                A[i][col] = 1;
            else
                A[i][col] = 0;
        }
    }
    
    
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        vector<int> col(n,0);
        
        for(int i = 0;i < m;i++){
            if(A[i][0] == 0)
                flipRow(A,i,n);
            for(int j = 0;j < n;j++){
                if(A[i][j] == 1)
                    col[j]++;
            }
        }
        
        for(int j = 0;j < n;j++){
            if(col[j] <= m/2)
                flipCol(A,j,m);
        }
        
        int result = 0,sum;
        for(vector<int> v : A){
            sum = 0;
            for(int j = v.size()-1;j >= 0 ;j--){
                if(v[j] == 1)
                    sum += pow(2,v.size()-1-j);
            }
            result += sum;
        }
        
        return result;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
