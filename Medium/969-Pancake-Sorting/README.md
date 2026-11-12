# [969. Pancake Sorting](https://leetcode.com/problems/pancake-sorting/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given an array of integers `arr`, sort the array by performing a series of **pancake flips**.

In one pancake flip we do the following steps:

- Choose an integer `k` where `1 <= k <= arr.length`.

- Reverse the sub-array `arr[0...k-1]` (**0-indexed**).

For example, if `arr = [3,2,1,4]` and we performed a pancake flip choosing `k = 3`, we reverse the sub-array `[3,2,1]`, so `arr = [1,2,3,4]` after the pancake flip at `k = 3`.

Return *an array of the *`k`*-values corresponding to a sequence of pancake flips that sort *`arr`. Any valid answer that sorts the array within `10 * arr.length` flips will be judged as correct.

 

**Example 1:**

```
Input: arr = [3,2,4,1]
Output: [4,2,4,3]
Explanation: 
We perform 4 pancake flips, with k values 4, 2, 4, and 3.
Starting state: arr = [3, 2, 4, 1]
After 1st flip (k = 4): arr = [1, 4, 2, 3]
After 2nd flip (k = 2): arr = [4, 1, 2, 3]
After 3rd flip (k = 4): arr = [3, 2, 1, 4]
After 4th flip (k = 3): arr = [1, 2, 3, 4], which is sorted.
```

**Example 2:**

```
Input: arr = [1,2,3]
Output: []
Explanation: The input is already sorted, so there is no need to flip anything.
Note that other answers, such as [3, 3], would also be accepted.
```

 

**Constraints:**

- `1 <= arr.length <= 100`

- `1 <= arr[i] <= arr.length`

- All integers in `arr` are unique (i.e. `arr` is a permutation of the integers from `1` to `arr.length`).

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
    public List<Integer> pancakeSort(int[] arr) {
        Stack<Integer> stack = new Stack<>();
        int n = arr.length;
        int[] indices = new int[n];
        for(int i=0; i<n; ++i) indices[arr[i]-1] = i;
        for(int i=0; i<n; ++i) {
            int pull = indices[i];
            dew(stack, i, pull);
            indices[arr[i]-1] = pull;
            indices[i] = i;
            arr[pull] = arr[i];
            arr[i] = i+1;
        }
        LinkedList<Integer> ans = new LinkedList<>();
        while(!stack.isEmpty()) {
            int x = stack.pop();
            ans.addFirst(x);
        }
        return ans;
    }
    
    private void dew(Stack<Integer> stack, int j, int i) {
        if(i != j) {
            add(stack, i+1);
            add(stack, i-j+1);
            add(stack, i-j);
            add(stack, i-j-1);
            add(stack, i-j);
            add(stack, i+1);
        }
    }
    
    private void add(Stack<Integer> stack, int x) {
        if(x > 1) {
            if(!stack.isEmpty() && stack.peek() == x) stack.pop();
            else stack.push(x);
        }
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
