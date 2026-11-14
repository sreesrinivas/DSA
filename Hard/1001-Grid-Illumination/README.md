# [1001. Grid Illumination](https://leetcode.com/problems/grid-illumination/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

There is a 2D `grid` of size `n x n` where each cell of this grid has a lamp that is initially **turned off**.

You are given a 2D array of lamp positions `lamps`, where `lamps[i] = [rowi, coli]` indicates that the lamp at `grid[rowi][coli]` is **turned on**. Even if the same lamp is listed more than once, it is turned on.

When a lamp is turned on, it **illuminates its cell** and **all other cells** in the same **row, column, or diagonal**.

You are also given another 2D array `queries`, where `queries[j] = [rowj, colj]`. For the `jth` query, determine whether `grid[rowj][colj]` is illuminated or not. After answering the `jth` query, **turn off** the lamp at `grid[rowj][colj]` and its **8 adjacent lamps** if they exist. A lamp is adjacent if its cell shares either a side or corner with `grid[rowj][colj]`.

Return *an array of integers *`ans`*,** where *`ans[j]`* should be *`1`* if the cell in the *`jth`* query was illuminated, or *`0`* if the lamp was not.*

 

**Example 1:**

```
Input: n = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,0]]
Output: [1,0]
Explanation: We have the initial grid with all lamps turned off. In the above picture we see the grid after turning on the lamp at grid[0][0] then turning on the lamp at grid[4][4].
The 0th query asks if the lamp at grid[1][1] is illuminated or not (the blue square). It is illuminated, so set ans[0] = 1. Then, we turn off all lamps in the red square.

The 1st query asks if the lamp at grid[1][0] is illuminated or not (the blue square). It is not illuminated, so set ans[1] = 0. Then, we turn off all lamps in the red rectangle.
```

**Example 2:**

```
Input: n = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,1]]
Output: [1,1]
```

**Example 3:**

```
Input: n = 5, lamps = [[0,0],[0,4]], queries = [[0,4],[0,1],[1,4]]
Output: [1,1,0]
```

 

**Constraints:**

- `1 <= n <= 109`

- `0 <= lamps.length <= 20000`

- `0 <= queries.length <= 20000`

- `lamps[i].length == 2`

- `0 <= rowi, coli < n`

- `queries[j].length == 2`

- `0 <= rowj, colj < n`

---

## 💡 Solution Explanation

Exhaustive / multi-pass search across candidate elements to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(n)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.java)**

```java
class Solution {
    int[][] dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}, {0,0}};
    
	public int[] gridIllumination(int N, int[][] lamps, int[][] queries) {
        Map<Integer, Integer> m1 = new HashMap();       // row number to count of lamps
        Map<Integer, Integer> m2 = new HashMap();       // col number to count of lamps
        Map<Integer, Integer> m3 = new HashMap();       // diagonal x-y to count of lamps
        Map<Integer, Integer> m4 = new HashMap();       // diagonal x+y to count of lamps
        Map<Integer, Boolean> m5 = new HashMap();       // whether lamp is  ON|OFF
        
        // increment counters while adding lamps
        for(int i=0; i<lamps.length; i++){
            int x = lamps[i][0];
            int y = lamps[i][1];
            m1.put(x, m1.getOrDefault(x, 0) + 1);
            m2.put(y, m2.getOrDefault(y, 0) + 1);
            m3.put(x-y, m3.getOrDefault(x-y, 0) + 1);
            m4.put(x+y, m4.getOrDefault(x+y, 0) + 1);
            m5.put(N*x + y, true);
        }

        int[] ans = new int[queries.length];
        // address queries
        for(int i=0; i<queries.length; i++){
            int x = queries[i][0];
            int y = queries[i][1];
            
            ans[i] = (m1.getOrDefault(x, 0) > 0 || m2.getOrDefault(y, 0) > 0 || m3.getOrDefault(x-y, 0) > 0 || m4.getOrDefault(x+y, 0) > 0) ? 1 : 0;            
            // switch off the lamps, if any
            for(int d=0; d<dirs.length; d++){
                int x1 = x + dirs[d][0];
                int y1 = y + dirs[d][1];
				if(m5.containsKey(N*x1 + y1) && m5.get(N*x1 + y1)){
                    // the lamp is on, turn it off, so decrement the count of the lamps
                    m1.put(x1, m1.getOrDefault(x1, 1) - 1);
                    m2.put(y1, m2.getOrDefault(y1, 1) - 1);
                    m3.put(x1 - y1, m3.getOrDefault(x1 - y1, 1) - 1);
                    m4.put(x1 + y1, m4.getOrDefault(x1 + y1, 1) - 1);
                    m5.put(N*x1+y1, false);
                }
            }
        }
        
        return ans;
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
