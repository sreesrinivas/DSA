# [726. Number of Atoms](https://leetcode.com/problems/number-of-atoms/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given a string `formula` representing a chemical formula, return *the count of each atom*.

The atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.

One or more digits representing that element's count may follow if the count is greater than `1`. If the count is `1`, no digits will follow.

- For example, `"H2O"` and `"H2O2"` are possible, but `"H1O2"` is impossible.

Two formulas are concatenated together to produce another formula.

- For example, `"H2O2He3Mg4"` is also a formula.

A formula placed in parentheses, and a count (optionally added) is also a formula.

- For example, `"(H2O2)"` and `"(H2O2)3"` are formulas.

Return the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than `1`), followed by the second name (in sorted order), followed by its count (if that count is more than `1`), and so on.

The test cases are generated so that all the values in the output fit in a **32-bit** integer.

 

**Example 1:**

```
Input: formula = "H2O"
Output: "H2O"
Explanation: The count of elements are {'H': 2, 'O': 1}.
```

**Example 2:**

```
Input: formula = "Mg(OH)2"
Output: "H2MgO2"
Explanation: The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.
```

**Example 3:**

```
Input: formula = "K4(ON(SO3)2)2"
Output: "K4N2O14S4"
Explanation: The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.
```

 

**Constraints:**

- `1 <= formula.length <= 1000`

- `formula` consists of English letters, digits, `'('`, and `')'`.

- `formula` is always valid.

---

## 💡 Solution Explanation

Sorting-based greedy or two-pointer approach to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n log n)`
- **Space Complexity:** `O(n)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.py)**

```python
class Solution:
    def countOfAtoms(self, formula: str) -> str:
        scopes = [{}]
        i, n = 0, len(formula)

        def read_number():
            nonlocal i
            start = i
            while i < n and formula[i].isdigit():
                i += 1
            return int(formula[start:i]) if i > start else 1

        while i < n:
            if formula[i] == "(":
                scopes.append({})
                i += 1
            elif formula[i] == ")":
                i += 1
                multiplier = read_number()
                group = scopes.pop()
                for atom, count in group.items():
                    scopes[-1][atom] = scopes[-1].get(atom, 0) + count * multiplier
            else:
                start = i
                i += 1
                while i < n and formula[i].islower():
                    i += 1
                atom = formula[start:i]
                scopes[-1][atom] = scopes[-1].get(atom, 0) + read_number()

        return "".join(atom + (str(count) if count > 1 else "")
                       for atom, count in sorted(scopes[0].items()))
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
