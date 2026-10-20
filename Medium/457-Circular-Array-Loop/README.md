# [457. Circular Array Loop](https://leetcode.com/problems/circular-array-loop/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are playing a game involving a **circular** array of non-zero integers `nums`. Each `nums[i]` denotes the number of indices forward/backward you must move if you are located at index `i`:

- If `nums[i]` is positive, move `nums[i]` steps **forward**, and

- If `nums[i]` is negative, move `abs(nums[i])` steps **backward**.

Since the array is **circular**, you may assume that moving forward from the last element puts you on the first element, and moving backwards from the first element puts you on the last element.

A **cycle** in the array consists of a sequence of indices `seq` of length `k` where:

- Following the movement rules above results in the repeating index sequence `seq[0] -> seq[1] -> ... -> seq[k - 1] -> seq[0] -> ...`

- Every `nums[seq[j]]` is either **all positive** or **all negative**.

- `k > 1`

Return `true`* if there is a **cycle** in *`nums`*, or *`false`* otherwise*.

 

**Example 1:**

```
Input: nums = [2,-1,1,2,2]
Output: true
Explanation: The graph shows how the indices are connected. White nodes are jumping forward, while red is jumping backward.
We can see the cycle 0 --> 2 --> 3 --> 0 --> ..., and all of its nodes are white (jumping in the same direction).
```

**Example 2:**

```
Input: nums = [-1,-2,-3,-4,-5,6]
Output: false
Explanation: The graph shows how the indices are connected. White nodes are jumping forward, while red is jumping backward.
The only cycle is of size 1, so we return false.
```

**Example 3:**

```
Input: nums = [1,-1,5,1,4]
Output: true
Explanation: The graph shows how the indices are connected. White nodes are jumping forward, while red is jumping backward.
We can see the cycle 0 --> 1 --> 0 --> ..., and while it is of size > 1, it has a node jumping forward and a node jumping backward, so it is not a cycle.
We can see the cycle 3 --> 4 --> 3 --> ..., and all of its nodes are white (jumping in the same direction).
```

 

**Constraints:**

- `1 <= nums.length <= 5000`

- `-1000 <= nums[i] <= 1000`

- `nums[i] != 0`

 

**Follow up:** Could you solve it in `O(n)` time complexity and `O(1)` extra space complexity?

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
    // Function to calculate the next index
    // The second % n handles negative results correctly in C++
    int getNext(int curr, vector<int>& nums){
        int n = nums.size();
        return ((curr + nums[curr]) % n + n) % n;
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        
        // We iterate through each index as a potential start of a cycle
        for(int i = 0; i < n; i++){
            if(nums[i] == 0) continue; // Already visited/processed
            
            int slow = i, fast = i;
            // Capture the initial direction (positive or negative)
            int iniDir = nums[i];
            
            while(true){
                // 1. Direction Check: Slow pointer
                // If direction changes (product is negative) or becomes 0, path is invalid
                if(nums[slow] * iniDir <= 0) break;
                
                // 2. Direction Check: Fast pointer (current step)
                if(nums[fast] * iniDir <= 0) break;
                
                // 3. Direction Check: Fast pointer (next step)
                int nextFast = getNext(fast, nums);
                if(nums[nextFast] * iniDir <= 0) break;
                
                // Move pointers
                slow = getNext(slow, nums);
                fast = getNext(nextFast, nums);
                
                // Cycle detected
                if(slow == fast){
                    // Check for self-loop (cycle length must be > 1)
                    if(slow == getNext(slow, nums)) break;
                    else return true;
                } 
            }
            
            // Optimization: Mark the path as 0 (visited/invalid)
            // We only need to mark nodes that follow the same direction
            int curr = i;
            while(nums[curr] * iniDir > 0){
                int next = getNext(curr, nums);
                nums[curr] = 0;
                curr = next;
            }
        }
        return false;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
