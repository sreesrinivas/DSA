# [842. Split Array into Fibonacci Sequence](https://leetcode.com/problems/split-array-into-fibonacci-sequence/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given a string of digits `num`, such as `"123456579"`. We can split it into a Fibonacci-like sequence `[123, 456, 579]`.

Formally, a **Fibonacci-like** sequence is a list `f` of non-negative integers such that:

- `0 <= f[i] < 231`, (that is, each integer fits in a **32-bit** signed integer type),

- `f.length >= 3`, and

- `f[i] + f[i + 1] == f[i + 2]` for all `0 <= i < f.length - 2`.

Note that when splitting the string into pieces, each piece must not have extra leading zeroes, except if the piece is the number `0` itself.

Return any Fibonacci-like sequence split from `num`, or return `[]` if it cannot be done.

 

**Example 1:**

```
Input: num = "1101111"
Output: [11,0,11,11]
Explanation: The output [110, 1, 111] would also be accepted.
```

**Example 2:**

```
Input: num = "112358130"
Output: []
Explanation: The task is impossible.
```

**Example 3:**

```
Input: num = "0123"
Output: []
Explanation: Leading zeroes are not allowed, so "01", "2", "3" is not valid.
```

 

**Constraints:**

- `1 <= num.length <= 200`

- `num` contains only digits.

---

## 💡 Solution Explanation

Two-pointer linear scan adjusting window boundaries based on constraints to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.cpp)**

```cpp
class Solution {
public:

    bool backtrack(string &S, int start, vector<int> &nums){        
        int n = S.size();
	// If we reached end of string & we have more than 2 elements
	// in our sequence then return true
        if(start >= n && nums.size()>=3){
            return true;
        }
	// Since '0' in beginning is not allowed therefore if the current char is '0'
	// then we can use it alone only and cannot extend it by adding more chars at the back.
	// Otherwise we make take upto 10 chars (length of INT_MAX)
        int maxSplitSize = (S[start]=='0') ? 1 : 10;
	// Try getting a solution by forming a number with 'i' chars begginning with 'start'
        for(int i=1; i<=maxSplitSize && start+i<=S.size(); i++){
            long long num = stoll(S.substr(start, i));
            if(num > INT_MAX)
                return false;
            int sz = nums.size();
	// If fibonacci property is not satisfied then we cannot get a solution
            if(sz >= 2 && nums[sz-1]+nums[sz-2] < num)
                return false;
            if(sz<=1 || nums[sz-1]+nums[sz-2]==num){
                nums.push_back(num);
                if(backtrack(S, start+i, nums))
                    return true;
                nums.pop_back();                
            }
        }
        return false;
    }
    
    vector<int> splitIntoFibonacci(string S) {
        vector<int> nums;
	// Backtrack from 0th char
        backtrack(S, 0, nums);
        return nums;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
