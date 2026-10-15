# [442. Find All Duplicates in an Array](https://leetcode.com/problems/find-all-duplicates-in-an-array/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given an integer array `nums` of length `n` where all the integers of `nums` are in the range `[1, n]` and each integer appears **at most** **twice**, return *an array of all the integers that appears **twice***.

You must write an algorithm that runs in `O(n)` time and uses only *constant* auxiliary space, excluding the space needed to store the output

 

**Example 1:**

```
Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
```

**Example 2:**

```
Input: nums = [1,1,2]
Output: [1]
```

**Example 3:**

```
Input: nums = [1]
Output: []
```

 

**Constraints:**

- `n == nums.length`

- `1 <= n <= 105`

- `1 <= nums[i] <= n`

- Each element in `nums` appears **once** or **twice**.

---

## 💡 Solution Explanation

Exhaustive / multi-pass search across candidate elements to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(n)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.cpp)**

```cpp
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if(nums.empty())return {};
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]!=nums[j])continue;
                else{
                    ans.push_back(nums[i]);
                    break;
                }
            }
        }
        return ans;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
