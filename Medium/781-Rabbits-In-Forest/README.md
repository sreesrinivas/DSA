# [781. Rabbits in Forest](https://leetcode.com/problems/rabbits-in-forest/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

There is a forest with an unknown number of rabbits. We asked n rabbits **"How many other rabbits have the same color as you?"** and collected the answers in an integer array `answers` where `answers[i]` is the answer of the `ith` rabbit.

Given the array `answers`, return *the minimum number of rabbits that could be in the forest*.

 

**Example 1:**

```
Input: answers = [1,1,2]
Output: 5
Explanation:
The two rabbits that answered "1" could both be the same color, say red.
The rabbit that answered "2" can't be red or the answers would be inconsistent.
Say the rabbit that answered "2" was blue.
Then there should be 2 other blue rabbits in the forest that didn't answer into the array.
The smallest possible number of rabbits in the forest is therefore 5: 3 that answered plus 2 that didn't.
```

**Example 2:**

```
Input: answers = [10,10,10]
Output: 11
```

 

**Constraints:**

- `1 <= answers.length <= 1000`

- `0 <= answers[i] < 1000`

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
from collections import Counter
from math import ceil

class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        freq = Counter(answers)
        total = 0
        for k, v in freq.items():
            group_size = k + 1
            groups = ceil(v / group_size)
            total += groups * group_size
        return total
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
