# [738. Monotone Increasing Digits](https://leetcode.com/problems/monotone-increasing-digits/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

An integer has **monotone increasing digits** if and only if each pair of adjacent digits `x` and `y` satisfy `x <= y`.

Given an integer `n`, return *the largest number that is less than or equal to *`n`* with **monotone increasing digits***.

 

**Example 1:**

```
Input: n = 10
Output: 9
```

**Example 2:**

```
Input: n = 1234
Output: 1234
```

**Example 3:**

```
Input: n = 332
Output: 299
```

 

**Constraints:**

- `0 <= n <= 109`

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
    int monotoneIncreasingDigits(int N) {
        string n_str = to_string(N);
        
        int marker = n_str.size();
        for(int i = n_str.size()-1; i > 0; i --) {
            if(n_str[i] < n_str[i-1]) {
                marker = i;
                n_str[i-1] = n_str[i-1]-1;
            }
        }
        
        for(int i = marker; i < n_str.size(); i ++) n_str[i] = '9';
        
        return stoi(n_str);
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
