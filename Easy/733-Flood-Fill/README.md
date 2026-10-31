# [733. Flood Fill](https://leetcode.com/problems/flood-fill/)

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given an image represented by an `m x n` grid of integers `image`, where `image[i][j]` represents the pixel value of the image. You are also given three integers `sr`, `sc`, and `color`. Your task is to perform a **flood fill** on the image starting from the pixel `image[sr][sc]`.

To perform a **flood fill**:

- Begin with the starting pixel and change its color to `color`.

- Perform the same process for each pixel that is **directly adjacent** (pixels that share a side with the original pixel, either horizontally or vertically) and shares the **same color** as the starting pixel.

- Keep **repeating** this process by checking neighboring pixels of the *updated* pixels and modifying their color if it matches the original color of the starting pixel.

- The process **stops** when there are **no more** adjacent pixels of the original color to update.

Return the **modified** image after performing the flood fill.

 

**Example 1:**

**Input:** image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2

**Output:** [[2,2,2],[2,2,0],[2,0,1]]

**Explanation:**

From the center of the image with position `(sr, sc) = (1, 1)` (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.

Note the bottom corner is **not** colored 2, because it is not horizontally or vertically connected to the starting pixel.

**Example 2:**

**Input:** image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0

**Output:** [[0,0,0],[0,0,0]]

**Explanation:**

The starting pixel is already colored with 0, which is the same as the target color. Therefore, no changes are made to the image.

 

**Constraints:**

- `m == image.length`

- `n == image[i].length`

- `1 <= m, n <= 50`

- `0 <= image[i][j], color < 216`

- `0 <= sr < m`

- `0 <= sc < n`

---

## 💡 Solution Explanation

Optimal iterative solution using a single pass to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.py)**

```python
from collections import deque

class Solution:
    def floodFill(self, image: list[list[int]], sr: int, sc: int, color: int) -> list[list[int]]:
        # If the original color is already the new color, no changes are needed.
        if image[sr][sc] == color:
            return image

        q = deque()
        q.append([sr, sc])

        # Create an independent copy of the image.
        image_copy = [row[:] for row in image]
        original_color = image_copy[sr][sc]

        # Immediately change the starting pixel's color.
        image_copy[sr][sc] = color

        # Explore all connected pixels having the original color.
        while q:
            i, j = q.popleft()

            # Check the four neighbours: down, right, up, and left.
            for x, y in [[1, 0], [0, 1], [-1, 0], [0, -1]]:
                dx, dy = i + x, j + y

                # If the neighbour is valid and has the original color,
                # change its color and add it to the queue.
                if (
                    0 <= dx < len(image) and
                    0 <= dy < len(image[0]) and
                    image_copy[dx][dy] == original_color
                ):
                    image_copy[dx][dy] = color
                    q.append([dx, dy])

        return image_copy
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
