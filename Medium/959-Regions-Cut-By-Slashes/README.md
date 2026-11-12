# [959. Regions Cut By Slashes](https://leetcode.com/problems/regions-cut-by-slashes/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

An `n x n` grid is composed of `1 x 1` squares where each `1 x 1` square consists of a `'/'`, `'\'`, or blank space `' '`. These characters divide the square into contiguous regions.

Given the grid `grid` represented as a string array, return *the number of regions*.

Note that backslash characters are escaped, so a `'\'` is represented as `'\\'`.

 

**Example 1:**

```
Input: grid = [" /","/ "]
Output: 2
```

**Example 2:**

```
Input: grid = [" /","  "]
Output: 1
```

**Example 3:**

```
Input: grid = ["/\\","\\/"]
Output: 5
Explanation: Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.
```

 

**Constraints:**

- `n == grid.length == grid[i].length`

- `1 <= n <= 30`

- `grid[i][j]` is either `'/'`, `'\'`, or `' '`.

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
    vector<int> parent;
    vector<int> rank;
    int count;
    
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int dots = n + 1;
        parent.resize(dots * dots);
        rank.resize(dots * dots, 1);
        count = 0;

        // Initialize Union-Find structure
        for (int i = 0; i < parent.size(); ++i) {
            parent[i] = i;
        }

        // Connect boundaries to the top-left corner (0,0)
        for (int i = 0; i < dots; ++i) {
            for (int j = 0; j < dots; ++j) {
                if (i == 0 || j == 0 || i == n || j == n) {
                    int cell = i * dots + j;
                    unionSets(0, cell);
                }
            }
        }

        // Process each cell and connect regions based on slashes
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '\\') {
                    int cell1 = i * dots + j;
                    int cell2 = (i + 1) * dots + (j + 1);
                    unionSets(cell1, cell2);
                } else if (grid[i][j] == '/') {
                    int cell1 = (i + 1) * dots + j;
                    int cell2 = i * dots + (j + 1);
                    unionSets(cell1, cell2);
                }
            }
        }

        return count;
    }
    
private:
    void unionSets(int a, int b) {
        int parentA = find(a);
        int parentB = find(b);
        if (parentA == parentB) {
            count++;
        } else {
            if (rank[parentA] > rank[parentB]) {
                parent[parentB] = parentA;
            } else if (rank[parentA] < rank[parentB]) {
                parent[parentA] = parentB;
            } else {
                parent[parentB] = parentA;
                rank[parentA]++;
            }
        }
    }
    
    int find(int a) {
        if (parent[a] == a) {
            return a;
        }
        return parent[a] = find(parent[a]);
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
