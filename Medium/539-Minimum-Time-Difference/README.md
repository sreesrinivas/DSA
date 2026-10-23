# [539. Minimum Time Difference](https://leetcode.com/problems/minimum-time-difference/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given a list of 24-hour clock time points in **"HH:MM"** format, return *the minimum **minutes** difference between any two time-points in the list*.

 

**Example 1:**

```
Input: timePoints = ["23:59","00:00"]
Output: 1
```

**Example 2:**

```
Input: timePoints = ["00:00","23:59","00:00"]
Output: 0
```

 

**Constraints:**

- `2 <= timePoints.length <= 2 * 104`

- `timePoints[i]` is in the format **"HH:MM"**.

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
    int findMinDifference(vector<string>& timePoints) {
        vector<int>minutes;
        for(int i =0 ;i<timePoints.size();i++){
            string str =timePoints[i];

            int hours =stoi(str.substr(0,2));
            int minute =stoi(str.substr(3,2));
            int totalminutes =hours*60+minute;
            minutes.push_back(totalminutes);
        }
        sort(minutes.begin(),minutes.end());

        int mini =INT_MAX;
        for(int i=0 ;i<minutes.size()-1;i++){
            int diff =minutes[i+1]-minutes[i];
            mini =min(mini ,diff);
        }
        int lastdiff =minutes[0]+1440 -minutes[minutes.size()-1];
        mini=min(mini, lastdiff);
        return mini;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
