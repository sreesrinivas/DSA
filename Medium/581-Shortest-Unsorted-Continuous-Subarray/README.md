# [581. Shortest Unsorted Continuous Subarray](https://leetcode.com/problems/shortest-unsorted-continuous-subarray/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given an integer array `nums`, you need to find one **continuous subarray** such that if you only sort this subarray in non-decreasing order, then the whole array will be sorted in non-decreasing order.

Return *the shortest such subarray and output its length*.

 

**Example 1:**

```
Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
```

**Example 2:**

```
Input: nums = [1,2,3,4]
Output: 0
```

**Example 3:**

```
Input: nums = [1]
Output: 0
```

 

**Constraints:**

- `1 <= nums.length <= 104`

- `-105 <= nums[i] <= 105`

 

**Follow up:** Can you solve it in `O(n)` time complexity?

---

## 💡 Solution Explanation

Sorting-based greedy or two-pointer approach to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n log n)`
- **Space Complexity:** `O(n)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.java)**

```java
public class Solution {
    public int findUnsortedSubarray(int[] nums) {
        int len=nums.length;
        int max=Integer.MIN_VALUE, min=Integer.MAX_VALUE;
        int start=-1, end=-1;
        
        for(int i=0; i<len; i++){
            max = Math.max(max, nums[i]); //from left to right, search the current max
            min = Math.min(min, nums[len-i-1]);  //from right to left, search the current min 
            
            if(nums[i] < max)  
                end = i;
            if(nums[len-i-1] > min)
                start = len-i-1;
        }
        
        if(start==-1) //the entire array is already sorted
            return 0;
        
        return end-start+1;
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
