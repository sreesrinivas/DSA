# [241. Different Ways to Add Parentheses](https://leetcode.com/problems/different-ways-to-add-parentheses/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given a string `expression` of numbers and operators, return *all possible results from computing all the different possible ways to group numbers and operators*. You may return the answer in **any order**.

The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed `104`.

 

**Example 1:**

```
Input: expression = "2-1-1"
Output: [0,2]
Explanation:
((2-1)-1) = 0 
(2-(1-1)) = 2
```

**Example 2:**

```
Input: expression = "2*3-4*5"
Output: [-34,-14,-10,-10,10]
Explanation:
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
```

 

**Constraints:**

- `1 <= expression.length <= 20`

- `expression` consists of digits and the operator `'+'`, `'-'`, and `'*'`.

- All the integer values in the input expression are in the range `[0, 99]`.

- The integer values in the input expression do not have a leading `'-'` or `'+'` denoting the sign.

---

## 💡 Solution Explanation

Exhaustive / multi-pass search across candidate elements to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(n)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.py)**

```python
class Solution(object):
    def diffWaysToCompute(self, expression: str):
        # operations map
        operation = {'*' : lambda x,y: x*y, '+' : lambda x,y: x+y, '-' : lambda x,y: x-y}

        def helper(expression):
            result = []
            for i, x in enumerate(expression):
                if x in ('+', '-', '*'):
                    leftResult = helper(expression[0:i]) # list of results for the left expression(s)
                    rightResult = helper(expression[i+1:]) # list of results for the right expression(s)
                    # append all the combinations
                    for leftValue in leftResult:
                        for rightValue in rightResult:
                            result.append(operation[x](leftValue, rightValue))
            return result if result else [int(expression)] # if result list is empty => expression is the single number
        return helper(expression)
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
