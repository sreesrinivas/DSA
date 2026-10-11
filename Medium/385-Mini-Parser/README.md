# [385. Mini Parser](https://leetcode.com/problems/mini-parser/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given a string s represents the serialization of a nested list, implement a parser to deserialize it and return *the deserialized* `NestedInteger`.

Each element is either an integer or a list whose elements may also be integers or other lists.

 

**Example 1:**

```
Input: s = "324"
Output: 324
Explanation: You should return a NestedInteger object which contains a single integer 324.
```

**Example 2:**

```
Input: s = "[123,[456,[789]]]"
Output: [123,[456,[789]]]
Explanation: Return a NestedInteger object containing a nested list with 2 elements:
1. An integer containing value 123.
2. A nested list containing two elements:
    i.  An integer containing value 456.
    ii. A nested list with one element:
         a. An integer containing value 789
```

 

**Constraints:**

- `1 <= s.length <= 5 * 104`

- `s` consists of digits, square brackets `"[]"`, negative sign `'-'`, and commas `','`.

- `s` is the serialization of valid `NestedInteger`.

- All the values in the input are in the range `[-106, 106]`.

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
def deserialize(self, s):
    # '-1' is not digit
    if s and s[-1].isdigit():
        return int(s)

    nested_integer = None
    digits = ''
    stack = []
    for c in s:
        if c.isdigit() or c == '-':
            digits += c
        elif c == '[':
            if nested_integer:
                stack.append(nested_integer)
            nested_integer = NestedInteger()
        elif c == ']':
            if digits:
                nested_integer.add(NestedInteger(int(digits)))
                digits = ''
            if stack:
                previous_nested_integer = stack.pop()
                previous_nested_integer.add(nested_integer)
                nested_integer = previous_nested_integer
        elif c == ',':
            if digits:
                nested_integer.add(NestedInteger(int(digits)))
                digits = ''

    return nested_integer
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
