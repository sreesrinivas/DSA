# [817. Linked List Components](https://leetcode.com/problems/linked-list-components/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given the `head` of a linked list containing unique integer values and an integer array `nums` that is a subset of the linked list values.

Return the number of **connected** **components** in `nums`. A connected component is a non-empty, maximal sequence of **consecutive** nodes in the linked list such that every node's value belongs to nums.

 

**Example 1:**

```
Input: head = [0,1,2,3], nums = [0,1,3]
Output: 2
Explanation: 0 and 1 are connected, so [0, 1] and [3] are the two connected components.
```

**Example 2:**

```
Input: head = [0,1,2,3,4], nums = [0,3,1,4]
Output: 2
Explanation: 0 and 1 are connected, 3 and 4 are connected, so [0, 1] and [3, 4] are the two connected components.
```

 

**Constraints:**

- The number of nodes in the linked list is `n`.

- `1 <= n <= 104`

- `0 <= Node.val < n`

- All the values `Node.val` are **unique**.

- `1 <= nums.length <= n`

- `0 <= nums[i] < n`

- All the values of `nums` are **unique**.

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
    public int numComponents(ListNode head, int[] nums) {
        boolean[] arr = new boolean[10_001];
        for(int num : nums) arr[num] = true;

        int res = 0;
        ListNode ptr = head;
        while(ptr != null) {
            if(!arr[ptr.val]) ptr = ptr.next;
            else {
                while(ptr != null && arr[ptr.val]) {
                    ptr = ptr.next;
                }
                res++;
            }
        }

        return res;
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
