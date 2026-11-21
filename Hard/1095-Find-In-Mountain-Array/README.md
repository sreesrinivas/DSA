# [1095. Find in Mountain Array](https://leetcode.com/problems/find-in-mountain-array/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

*(This problem is an **interactive problem**.)*

You may recall that an array `arr` is a **mountain array** if and only if:

- `arr.length >= 3`

- There exists some `i` with `0 < i < arr.length - 1` such that:
	
`arr[0] < arr[1] < ... < arr[i - 1] < arr[i]`
`arr[i] > arr[i + 1] > ... > arr[arr.length - 1]`

Given a mountain array `mountainArr`, return the **minimum** `index` such that `mountainArr.get(index) == target`. If such an `index` does not exist, return `-1`.

**You cannot access the mountain array directly.** You may only access the array using a `MountainArray` interface:

- `MountainArray.get(k)` returns the element of the array at index `k` (0-indexed).

- `MountainArray.length()` returns the length of the array.

Submissions making more than `100` calls to `MountainArray.get` will be judged *Wrong Answer*. Also, any solutions that attempt to circumvent the judge will result in disqualification.

 

**Example 1:**

```
Input: mountainArr = [1,2,3,4,5,3,1], target = 3
Output: 2
Explanation: 3 exists in the array, at index=2 and index=5. Return the minimum index, which is 2.
```

**Example 2:**

```
Input: mountainArr = [0,1,2,4,2,1], target = 3
Output: -1
Explanation: 3 does not exist in the array, so we return -1.
```

 

**Constraints:**

- `3 <= mountainArr.length() <= 104`

- `0 <= target <= 109`

- `0 <= mountainArr.get(index) <= 109`

---

## 💡 Solution Explanation

Binary search approach dividing the search range logarithmically to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(log n)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.java)**

```java
class Solution {
    public int findInMountainArray(int target, MountainArray mountainArr) {
        int peak = findPeakIndex(mountainArr);
        
        if (target == mountainArr.get(peak)) return peak;
        
        int leftIndex = binarySearch(mountainArr, 0, peak - 1, target, true);
        int rightIndex = binarySearch(mountainArr, peak + 1, mountainArr.length() - 1, target, false);
        
        return leftIndex != -1 ? leftIndex : rightIndex;
    }
    
    int findPeakIndex(MountainArray arr) {
        int len = arr.length();
        int left = 0, right = len -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midVal = arr.get(mid);
            int leftMidVal = mid > 0 ? arr.get(mid - 1) : Integer.MIN_VALUE;
            int rightMidVal = mid < len - 1 ? arr.get(mid + 1) : Integer.MAX_VALUE;
            
            if (midVal > leftMidVal && midVal > rightMidVal) return mid;
            
            if (midVal >= leftMidVal && midVal <= rightMidVal) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return -1;
    }
    
    int binarySearch(MountainArray mountainArr, int left, int right, int target, boolean incr) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int val = mountainArr.get(mid);
            if (val == target) return mid;
            
            if (target > val) {
                if (incr) {
                    left = mid + 1;  
                } else {
                    right = mid - 1;
                }
            } else { // target < val
                if (incr) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        
        return -1;
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
