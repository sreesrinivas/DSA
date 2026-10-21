# [498. Diagonal Traverse](https://leetcode.com/problems/diagonal-traverse/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given an `m x n` matrix `mat`, return *an array of all the elements of the array in a diagonal order*.

 

**Example 1:**

```
Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]
```

**Example 2:**

```
Input: mat = [[1,2],[3,4]]
Output: [1,2,3,4]
```

 

**Constraints:**

- `m == mat.length`

- `n == mat[i].length`

- `1 <= m, n <= 104`

- `1 <= m * n <= 104`

- `-105 <= mat[i][j] <= 105`

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
def findDiagonalOrder(self, matrix: List[List[int]]) -> List[int]:
    d= collections.defaultdict(list)
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            d[i+j].append(matrix[i][j])
    ans= []
    for entry in d.items():
        if entry[0] % 2 == 0:
            ans.extend(entry[1][::-1])
        else:
            ans.extend(entry[1])
    return ans
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
