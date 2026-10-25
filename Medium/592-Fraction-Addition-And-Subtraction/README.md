# [592. Fraction Addition and Subtraction](https://leetcode.com/problems/fraction-addition-and-subtraction/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given a string `expression` representing an expression of fraction addition and subtraction, return the calculation result in string format.

The final result should be an irreducible fraction. If your final result is an integer, change it to the format of a fraction that has a denominator `1`. So in this case, `2` should be converted to `2/1`.

 

**Example 1:**

```
Input: expression = "-1/2+1/2"
Output: "0/1"
```

**Example 2:**

```
Input: expression = "-1/2+1/2+1/3"
Output: "1/3"
```

**Example 3:**

```
Input: expression = "1/3-1/2"
Output: "-1/6"
```

 

**Constraints:**

- The input string only contains `'0'` to `'9'`, `'/'`, `'+'` and `'-'`. So does the output.

- Each fraction (input and output) has the format `±numerator/denominator`. If the first input fraction or the output is positive, then `'+'` will be omitted.

- The input only contains valid **irreducible fractions**, where the **numerator** and **denominator** of each fraction will always be in the range `[1, 10]`. If the denominator is `1`, it means this fraction is actually an integer in a fraction format defined above.

- The number of given fractions will be in the range `[1, 10]`.

- The numerator and denominator of the **final result** are guaranteed to be valid and in the range of **32-bit** int.

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
    def fractionAddition(self, expression: str) -> str:
        nums = list(map(int, re.findall(r'[+-]?\d+', expression)))
        numerator = 0
        denominator = 1
        
        for i in range(0, len(nums), 2):
            num, den = nums[i], nums[i + 1]
            numerator = numerator * den + num * denominator
            denominator *= den
        
        common_divisor = gcd(numerator, denominator)
        return f"{numerator // common_divisor}/{denominator // common_divisor}"
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
