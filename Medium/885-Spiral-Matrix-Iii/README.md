# [885. Spiral Matrix III](https://leetcode.com/problems/spiral-matrix-iii/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You start at the cell `(rStart, cStart)` of an `rows x cols` grid facing east. The northwest corner is at the first row and column in the grid, and the southeast corner is at the last row and column.

You will walk in a clockwise spiral shape to visit every position in this grid. Whenever you move outside the grid's boundary, we continue our walk outside the grid (but may return to the grid boundary later.). Eventually, we reach all `rows * cols` spaces of the grid.

Return *an array of coordinates representing the positions of the grid in the order you visited them*.

 

**Example 1:**

```
Input: rows = 1, cols = 4, rStart = 0, cStart = 0
Output: [[0,0],[0,1],[0,2],[0,3]]
```

**Example 2:**

```
Input: rows = 5, cols = 6, rStart = 1, cStart = 4
Output: [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]
```

 

**Constraints:**

- `1 <= rows, cols <= 100`

- `0 <= rStart < rows`

- `0 <= cStart < cols`

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
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        int srow=rStart,erow=rStart,scol=cStart,ecol=cStart;
       int  count=0;
        while(count!=rows*cols){
            for(int i=scol; i<=ecol; i++){
                if(srow>=0 && srow<rows && i>=0 && i<cols){
                    ans.push_back({srow,i});
                    count++;
                }
            }
            ecol++;
            for(int i=srow; i<=erow; i++){
                if(i>=0 &&i<rows && ecol<cols && ecol>=0){
                    ans.push_back({i,ecol});
                    count++;
                }
            }
            erow++;

            for(int i=ecol; i>=scol; i--){
                if(erow>=0 &&erow<rows && i>=0 &&i<cols ){
                    ans.push_back({erow,i});
                    count++;
                }
            }
            scol--;

            for(int i=erow; i>=srow; i--){
                if(i>=0 && i<rows &&  scol>=0&& scol<cols){
                    ans.push_back({i,scol});
                    count++;
                }
            }
            srow--;
        }
        return ans;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
