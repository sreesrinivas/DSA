# [892. Surface Area of 3D Shapes](https://leetcode.com/problems/surface-area-of-3d-shapes/)

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given an `n x n` `grid` where you have placed some `1 x 1 x 1` cubes. Each value `v = grid[i][j]` represents a tower of `v` cubes placed on top of cell `(i, j)`.

After placing these cubes, you have decided to glue any directly adjacent cubes to each other, forming several irregular 3D shapes.

Return *the total surface area of the resulting shapes*.

**Note:** The bottom face of each shape counts toward its surface area.

 

**Example 1:**

```
Input: grid = [[1,2],[3,4]]
Output: 34
```

**Example 2:**

```
Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
Output: 32
```

**Example 3:**

```
Input: grid = [[2,2,2],[2,1,2],[2,2,2]]
Output: 46
```

 

**Constraints:**

- `n == grid.length == grid[i].length`

- `1 <= n <= 50`

- `0 <= grid[i][j] <= 50`

---

## 💡 Solution Explanation

Optimal iterative solution using a single pass to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.java)**

```java
/*
    Explanation about calculation
    -----------------------------

    Total Area contributed by a cube -> 6 * 1 (according to discription [1 * 1 * 1])
    
    Common area when the cubes are placed on the top of each other (vertically) : 
        2 * (number_of_cubes - 1) -> 2 * (grid[i][j] - 1)
        
    so therefore, total surface area by a tower : (6 * grid[i][j] - 2 * (grid[i][j] - 1))
                                                : 4 * grid[i][j] + 2
                                                
    
    Also needs to subtract, adjacent hidden common area from total surface area calculated
    so far.
    
        adjacent_hidden_common_area_horizontally : 2 * min(cubes_cnt_in_first_tower, cubes_cnt_in_tower_next_to_first_tower)
                                                 : 2 * min(grid[i][j], grid[i][j + 1]) or
                                                 : 2 * min(grid[i][j], grid[i][j - 1]) based on implementation.
                                                 
        adjacent_hidden_common_area_vertically   : 2 * min(cubes_cnt_in_first_tower, cubes_cnt_in_tower_beneath_to_first_tower)
                                                 : 2 * min(grid[i][j], grid[i + 1][j]) or
                                                 : 2 * min(grid[i][j], grid[i - 1][j]) based on implementation.
*/

class Solution {
    public int surfaceArea(int[][] grid) {
        int n = grid.length, totSA = 0;
        for(int i = 0; i < n; i += 1) {
            for(int j = 0; j < n; j += 1) {
                if(grid[i][j] > 0) totSA += (6 * grid[i][j] - 2 * (grid[i][j] - 1));
                if(i > 0) totSA -= 2 * Math.min(grid[i][j], grid[i - 1][j]);//vertically hidden common area
                if(j > 0) totSA -= 2 * Math.min(grid[i][j], grid[i][j - 1]);//horizontally hidden common area
            }
        }
        
        return totSA;
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
