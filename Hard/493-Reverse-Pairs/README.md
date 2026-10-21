# [493. Reverse Pairs](https://leetcode.com/problems/reverse-pairs/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given an integer array `nums`, return *the number of **reverse pairs** in the array*.

A **reverse pair** is a pair `(i, j)` where:

- `0 <= i < j < nums.length` and

- `nums[i] > 2 * nums[j]`.

 

**Example 1:**

```
Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
```

**Example 2:**

```
Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
```

 

**Constraints:**

- `1 <= nums.length <= 5 * 104`

- `-231 <= nums[i] <= 231 - 1`

---

## 💡 Solution Explanation

Exhaustive / multi-pass search across candidate elements to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.java)**

```java
class Solution {
    
    //Divide the array and count reverse pairs
    public static int divide(int[] nums, int low, int high){
        if(low >= high){
            return 0;
        }

        int count = 0;
        int mid = low + (high - low)/2;
        count += divide(nums, low, mid);
        count += divide(nums, mid + 1, high);
        count += countpair(nums, low, high, mid);
        conquer(nums, low, high, mid);

        return count;
    }

    //Merge two sorted halves
    public static void conquer(int[] nums, int low, int high, int mid){
        int[] merged = new int[high - low + 1];

        int left = low;
        int right = mid + 1;
        int k = 0;

        while(left <= mid && right <= high){
            if(nums[left] <= nums[right]){
                merged[k++] = nums[left++];
            }
            else{
                merged[k++] = nums[right++];
            }
        }

        while(left <= mid){
            merged[k++] = nums[left++];
        }

        while(right <= high){
            merged[k++] = nums[right++];
        }

        for(int i = 0, j = low; i < merged.length; i++, j++){
            nums[j] = merged[i];
        }


    }

    //Count reverse pairs across the two sorted halves
    public static int countpair(int[] nums, int low, int high, int mid){
        int count = 0;
        int right = mid + 1;

        for(int i = low; i <= mid; i++){
            while(right <= high && (long)nums[i] > 2L * nums[right]){
                right++;
               
            }
            count += right -  (mid + 1);
        }
        return count;
    }

    
    public int reversePairs(int[] nums) {
        return divide(nums, 0, nums.length - 1);
        
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
