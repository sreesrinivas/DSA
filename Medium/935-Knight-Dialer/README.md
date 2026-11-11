# [935. Knight Dialer](https://leetcode.com/problems/knight-dialer/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

The chess knight has a **unique movement**, it may move two squares vertically and one square horizontally, or two squares horizontally and one square vertically (with both forming the shape of an **L**). The possible movements of chess knight are shown in this diagram:

A chess knight can move as indicated in the chess diagram below:

We have a chess knight and a phone pad as shown below, the knight **can only stand on a numeric cell** (i.e. blue cell).

Given an integer `n`, return how many distinct phone numbers of length `n` we can dial.

You are allowed to place the knight **on any numeric cell** initially and then you should perform `n - 1` jumps to dial a number of length `n`. All jumps should be **valid** knight jumps.

As the answer may be very large, **return the answer modulo** `109 + 7`.

 

**Example 1:**

```
Input: n = 1
Output: 10
Explanation: We need to dial a number of length 1, so placing the knight over any numeric cell of the 10 cells is sufficient.
```

**Example 2:**

```
Input: n = 2
Output: 20
Explanation: All the valid number we can dial are [04, 06, 16, 18, 27, 29, 34, 38, 40, 43, 49, 60, 61, 67, 72, 76, 81, 83, 92, 94]
```

**Example 3:**

```
Input: n = 3131
Output: 136006598
Explanation: Please take care of the mod.
```

 

**Constraints:**

- `1 <= n <= 5000`

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
    public int knightDialer(int N) {
        if(N==1) return 10;
        long mod = 1000000007;
        long[] pre = new long[10];  // to record previous result. It is needed because if we only use cur, the cur array itself is changed during calculation. 
        long[] cur = new long[10];  // to record current result. 
        Arrays.fill(pre,1);
        while(--N>0){
            cur[0]=(pre[4]+pre[6])%mod;
            cur[1]=(pre[6]+pre[8])%mod;
            cur[2]=(pre[7]+pre[9])%mod;
            cur[3]=(pre[4]+pre[8])%mod;
            cur[4]=(pre[3]+pre[9]+pre[0])%mod;
            //cur[5]=0;
            cur[6]=(pre[1]+pre[7]+pre[0])%mod;
            cur[7]=(pre[2]+pre[6])%mod;
            cur[8]=(pre[1]+pre[3])%mod;
            cur[9]=(pre[2]+pre[4])%mod;
            //pre = cur; //Wrong for it's address copy. 错误，这是地址拷贝了,导致出错
            for(int i=0; i<10; i++) pre[i]=cur[i];  //Right for it's value copy(deep copy).
        }
        long sum = 0;
        for(int i=0; i<10; i++){
            sum = (sum+cur[i])%mod;
        }
        return (int)sum;
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
