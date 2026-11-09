# [838. Push Dominoes](https://leetcode.com/problems/push-dominoes/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

There are `n` dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.

After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.

When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.

You are given a string `dominoes` representing the initial state where:

- `dominoes[i] = 'L'`, if the `ith` domino has been pushed to the left,

- `dominoes[i] = 'R'`, if the `ith` domino has been pushed to the right, and

- `dominoes[i] = '.'`, if the `ith` domino has not been pushed.

Return *a string representing the final state*.

 

**Example 1:**

```
Input: dominoes = "RR.L"
Output: "RR.L"
Explanation: The first domino expends no additional force on the second domino.
```

**Example 2:**

```
Input: dominoes = ".L.R...LR..L.."
Output: "LL.RR.LLRRLL.."
```

 

**Constraints:**

- `n == dominoes.length`

- `1 <= n <= 105`

- `dominoes[i]` is either `'L'`, `'R'`, or `'.'`.

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
class Solution: 
    def pushDominoes(self, dominoes: str) -> str:

        prev = ''
        
        while dominoes != prev:
            prev = dominoes

            dominoes = (dominoes.replace('R.L', 'xxx')      # <-- 1)

                                .replace('R.' , 'RR' )      # <-- 2)         
                                .replace('.L' , 'LL' ))         

        return  dominoes.replace('xxx', 'R.L')              # <-- 3)
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
