# [949. Largest Time for Given Digits](https://leetcode.com/problems/largest-time-for-given-digits/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given an array `arr` of 4 digits, find the latest 24-hour time that can be made using each digit **exactly once**.

24-hour times are formatted as `"HH:MM"`, where `HH` is between `00` and `23`, and `MM` is between `00` and `59`. The earliest 24-hour time is `00:00`, and the latest is `23:59`.

Return *the latest 24-hour time in `"HH:MM"` format*. If no valid time can be made, return an empty string.

 

**Example 1:**

```
Input: arr = [1,2,3,4]
Output: "23:41"
Explanation: The valid 24-hour times are "12:34", "12:43", "13:24", "13:42", "14:23", "14:32", "21:34", "21:43", "23:14", and "23:41". Of these times, "23:41" is the latest.
```

**Example 2:**

```
Input: arr = [5,5,5,5]
Output: ""
Explanation: There are no valid 24-hour times as "55:55" is not valid.
```

 

**Constraints:**

- `arr.length == 4`

- `0 <= arr[i] <= 9`

---

## 💡 Solution Explanation

Exhaustive / multi-pass search across candidate elements to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.py)**

```python
class Solution(object):
    def largestTimeFromDigits(self, arr):
        s=""
        arr1=arr[:]
        for x in range(2,-1,-1):
            if x in arr:
                s+=str(x)
                arr.remove(x)
                break
        if len(s)>0 and s[0]=="2":
            for x in range(3,-1,-1):
                if x in arr:
                    s+=str(x)+":"
                    arr.remove(x)
                    break
        if len(s)>2:
            for x in range(5,-1,-1):
                if x in arr:
                    s+=str(x)
                    arr.remove(x)
                    break
        if len(s)>3:
            for x in range(9,-1,-1):
                if x in arr:
                    s+=str(x)
                    break
        if len(s)==5:
            return s
        a=""
        for x in range(1,-1,-1):
            if x in arr1:
                a+=str(x)
                arr1.remove(x)
                break
        if len(a)>0 and a[0] in "01":
            for x in range(9,-1,-1):
                if x in arr1:
                    a+=str(x)+":"
                    arr1.remove(x)
                    break
        if len(a)>2:
            for x in range(5,-1,-1):
                if x in arr1:
                    a+=str(x)
                    arr1.remove(x)
                    break
        if len(a)>3:
            for x in range(9,-1,-1):
                if x in arr1:
                    a+=str(x)
                    break
        return a if len(a)==5 else ""
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
