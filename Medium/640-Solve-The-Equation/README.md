# [640. Solve the Equation](https://leetcode.com/problems/solve-the-equation/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Solve a given equation and return the value of `'x'` in the form of a string `"x=#value"`. The equation contains only `'+'`, `'-'` operation, the variable `'x'` and its coefficient. You should return `"No solution"` if there is no solution for the equation, or `"Infinite solutions"` if there are infinite solutions for the equation.

If there is exactly one solution for the equation, we ensure that the value of `'x'` is an integer.

 

**Example 1:**

```
Input: equation = "x+5-3+x=6+x-2"
Output: "x=2"
```

**Example 2:**

```
Input: equation = "x=x"
Output: "Infinite solutions"
```

**Example 3:**

```
Input: equation = "2x=x"
Output: "x=0"
```

 

**Constraints:**

- `3 <= equation.length <= 1000`

- `equation` has exactly one `'='`.

- `equation` consists of integers with an absolute value in the range `[0, 100]` without any leading zeros, and the variable `'x'`.

- The input is generated that if there is a single solution, it will be an integer.

---

## 💡 Solution Explanation

Hash-table lookup approach enabling constant-time O(1) element retrieval to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.py)**

```python
class Solution:
    def solveEquation(self, equation: str) -> str:
        def evaluate(expression):
            tokens = expression.replace("+", "#+").replace("-", "#-").split("#")  # For example: "x+5-3+x" is replaced to "x#+5#-3#+x" then split by "#"
            res = [0] * 2
            for token in tokens:
                if not token: continue
                if token == "x" or token == "+x":
                    res[0] += 1
                elif token == "-x":
                    res[0] -= 1
                elif "x" in token:
                    res[0] += int(token[:token.index("x")])  # For example: "3x" or "-5x" or "+6x"
                else:
                    res[1] += int(token)
            return res

        parts = equation.split("=")
        leftRes = evaluate(parts[0])
        rightRes = evaluate(parts[1])
        a = leftRes[0] - rightRes[0]
        b = rightRes[1] - leftRes[1]
        if a == 0 and b == 0:
            return "Infinite solutions"
        if a == 0:
            return "No solution"
        return "x={}".format(b // a)
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
