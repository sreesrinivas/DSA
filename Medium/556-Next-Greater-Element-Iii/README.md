# [556. Next Greater Element III](https://leetcode.com/problems/next-greater-element-iii/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given a positive integer `n`, find *the smallest integer which has exactly the same digits existing in the integer* `n` *and is greater in value than* `n`. If no such positive integer exists, return `-1`.

**Note** that the returned integer should fit in **32-bit integer**, if there is a valid answer but it does not fit in **32-bit integer**, return `-1`.

 

**Example 1:**

```
Input: n = 12
Output: 21
```

**Example 2:**

```
Input: n = 21
Output: -1
```

 

**Constraints:**

- `1 <= n <= 231 - 1`

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
    int nextGreaterElement(int n) {
        string s =  to_string(n);
        int x =  s.size();
        int index = -1;
        for(int i= x-1 ; i>=0 ; i--){
        	if(s[i]<s[i+1]){index = i; break;}
        }
        if(index == -1) return  -1;
    
        // reverse( index +1 , x - 1);
        int i = index + 1 , j = x-1 ;
        while(i<=j) swap(s[i++] , s[j--]);

        // upperbound
        int ii =  upper_bound(s.begin() + index + 1  , s.end() , s[index]) - s.begin();
        swap(s[index], s[ii]);
        // cout<< ii << endl;
        long long p =  stoll(s);
        return p<=INT_MAX ? p : -1;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
