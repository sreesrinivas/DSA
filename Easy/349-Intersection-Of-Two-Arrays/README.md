# [349. Intersection of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays/)

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given two integer arrays `nums1` and `nums2`, return *an array of their intersection*. Each element in the result must be **unique** and you may return the result in **any order**.

 

**Example 1:**

```
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
```

**Example 2:**

```
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
```

 

**Constraints:**

- `1 <= nums1.length, nums2.length <= 1000`

- `0 <= nums1[i], nums2[i] <= 1000`

---

## 💡 Solution Explanation

Sorting-based greedy or two-pointer approach to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n log n)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.cpp)**

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& set1, vector<int>& joint) {
        vector<int> answer;

        sort(set1.begin(), set1.end());
        sort(joint.begin(), joint.end());

        size_t i = 0;
        size_t j = 0;

        while (i < set1.size() && j < joint.size()) {
            if (set1[i] == joint[j]) {
                if (answer.empty() || answer.back() != set1[i]) {
                    answer.push_back(set1[i]);
                }
                i++;
                j++;
            } 
            else if (set1[i] < joint[j]) {
                i++;
            } 
            else {
                j++;
            }
        }

        return answer;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
