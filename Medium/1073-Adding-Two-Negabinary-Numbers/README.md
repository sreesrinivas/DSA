# [1073. Adding Two Negabinary Numbers](https://leetcode.com/problems/adding-two-negabinary-numbers/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given two numbers `arr1` and `arr2` in base **-2**, return the result of adding them together.

Each number is given in *array format*:  as an array of 0s and 1s, from most significant bit to least significant bit.  For example, `arr = [1,1,0,1]` represents the number `(-2)^3 + (-2)^2 + (-2)^0 = -3`.  A number `arr` in *array, format* is also guaranteed to have no leading zeros: either `arr == [0]` or `arr[0] == 1`.

Return the result of adding `arr1` and `arr2` in the same format: as an array of 0s and 1s with no leading zeros.

 

**Example 1:**

```
Input: arr1 = [1,1,1,1,1], arr2 = [1,0,1]
Output: [1,0,0,0,0]
Explanation: arr1 represents 11, arr2 represents 5, the output represents 16.
```

**Example 2:**

```
Input: arr1 = [0], arr2 = [0]
Output: [0]
```

**Example 3:**

```
Input: arr1 = [0], arr2 = [1]
Output: [1]
```

 

**Constraints:**

- `1 <= arr1.length, arr2.length <= 1000`

- `arr1[i]` and `arr2[i]` are `0` or `1`

- `arr1` and `arr2` have no leading zeros

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
class Solution(object):
    def addNegabinary(self, arr1, arr2):
        """
        ref:
            - https://en.wikipedia.org/wiki/Negative_base#Addition

            Carry:          1 −1  0 −1  1 −1  0  0  0
            First addend:         1  0  1  0  1  0  1
            Second addend:        1  1  1  0  1  0  0 + addition
                            --------------------------
            Number:         1 −1  2  0  3 −1  2  0  1 when we come with a number, lookup from the hashtable
            -----------------------------------------
            Bit (result):   1  1  0  0  1  1  0  0  1
            Carry:          0  1 −1  0 −1  1 −1  0  0 <- each number will be moved to the carry on the top in the next bit
        """
        lookup = {
            -2: (0, 1), # useless becos −2 occurs only during subtraction
            -1: (1, 1),
            0: (0, 0),
            1: (1, 0),
            2: (0, -1),
            3: (1, -1),
        }
        carry = 0
        result = []
        # do addition
        while len(arr1) > 0 or len(arr2) > 0:
            a = 0
            if len(arr1) > 0:
                a = arr1.pop()
            b = 0
            if len(arr2) > 0:
                b = arr2.pop()
            temp = a + b + carry
            res, carry = lookup[temp]
            result.append(res)
        # if there is still a carry
        while carry != 0:
            res, carry = lookup[carry]
            result.append(res)
        # remove leading zeros
        while len(result) > 1 and result[-1] == 0:
            result.pop()
        return result[::-1]
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
