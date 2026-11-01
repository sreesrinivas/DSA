# [777. Swap Adjacent in LR String](https://leetcode.com/problems/swap-adjacent-in-lr-string/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

In a string composed of `'L'`, `'R'`, and `'X'` characters, like `"RXXLRXRXL"`, a move consists of either replacing one occurrence of `"XL"` with `"LX"`, or replacing one occurrence of `"RX"` with `"XR"`. Given the starting string `start` and the ending string `result`, return `True` if and only if there exists a sequence of moves to transform `start` to `result`.

 

**Example 1:**

```
Input: start = "RXXLRXRXL", result = "XRLXXRRLX"
Output: true
Explanation: We can transform start to result following these steps:
RXXLRXRXL ->
XRXLRXRXL ->
XRLXRXRXL ->
XRLXXRRXL ->
XRLXXRRLX
```

**Example 2:**

```
Input: start = "X", result = "L"
Output: false
```

 

**Constraints:**

- `1 <= start.length <= 104`

- `start.length == result.length`

- Both `start` and `result` will only consist of characters in `'L'`, `'R'`, and `'X'`.

---

## 💡 Solution Explanation

Exhaustive / multi-pass search across candidate elements to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.cpp)**

```cpp
class Solution {
public:
    bool canTransform(string start, string end) {
        int i = 0, j = 0;
        while(i < start.size() && j < end.size()) {
            while (i < start.size() && start[i] == 'X')
                i++;
            while (j < end.size() && end[j] == 'X')
                j++;
            if (i < start.size() && j < end.size()) {
                if (start[i] != end[j])
                    return false;
                else if (start[i] == 'L' && i < j)
                    return false;
                else if (start[i] == 'R' && i > j)
                    return false;
                i++;
                j++;
            }
        }
        
        while (i < start.size()) {
            if (start[i] != 'X')
                return false;
            i++;
        }
        
         while (j < end.size()) {
            if (end[j] != 'X')
                return false;
            j++;
        }
        return true;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
