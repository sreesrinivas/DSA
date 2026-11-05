# [870. Advantage Shuffle](https://leetcode.com/problems/advantage-shuffle/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given two integer arrays `nums1` and `nums2` both of the same length. The **advantage** of `nums1` with respect to `nums2` is the number of indices `i` for which `nums1[i] > nums2[i]`.

Return *any permutation of *`nums1`* that maximizes its **advantage** with respect to *`nums2`.

 

**Example 1:**

```
Input: nums1 = [2,7,11,15], nums2 = [1,10,4,11]
Output: [2,11,7,15]
```

**Example 2:**

```
Input: nums1 = [12,24,8,32], nums2 = [13,25,32,11]
Output: [24,32,8,12]
```

 

**Constraints:**

- `1 <= nums1.length <= 105`

- `nums2.length == nums1.length`

- `0 <= nums1[i], nums2[i] <= 109`

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
    public int[] advantageCount(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int[] ans = new int[n];
        boolean[] check = new boolean[n];
        Arrays.sort(nums1);
        for(int i=0;i<n;i++){
            int ind = ceil(nums2[i],nums1,n);
            while(ind<n && check[ind]){
                ind++;
            }
            if(ind==n){
                int k=0;
                while(check[k]==true){
                    k++;
                }
                check[k]=true;
                ans[i]=nums1[k];
            }
            else{
                check[ind]=true;
                ans[i]=nums1[ind];
            }
        }
        return ans;
    }
    int ceil(int x,int[] nums,int n){
        int l=0,r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(x<nums[mid]){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return r+1;
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
