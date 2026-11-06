# [832. Flipping an Image](https://leetcode.com/problems/flipping-an-image/)

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given an `n x n` binary matrix `image`, flip the image **horizontally**, then invert it, and return *the resulting image*.

To flip an image horizontally means that each row of the image is reversed.

- For example, flipping `[1,1,0]` horizontally results in `[0,1,1]`.

To invert an image means that each `0` is replaced by `1`, and each `1` is replaced by `0`.

- For example, inverting `[0,1,1]` results in `[1,0,0]`.

 

**Example 1:**

```
Input: image = [[1,1,0],[1,0,1],[0,0,0]]
Output: [[1,0,0],[0,1,0],[1,1,1]]
Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
```

**Example 2:**

```
Input: image = [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
```

 

**Constraints:**

- `n == image.length`

- `n == image[i].length`

- `1 <= n <= 20`

- `images[i][j]` is either `0` or `1`.

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
    public int[][] flipAndInvertImage(int[][] image) {
        int n = image[0].length;
        int[][] arr = new int[n][n];

        // Step 1: Flip each row
        for (int i = 0; i < n; i++) {
            int k = n - 1;

            for (int j = 0; j < n; j++) {
                arr[i][j] = image[i][k];
                k--;
            }
        }

        // Step 2: Invert each element
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == 1) {
                    arr[i][j] = 0;
                } else {
                    arr[i][j] = 1;
                }
            }
        }

        return arr;
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
