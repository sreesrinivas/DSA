# [771. Jewels and Stones](https://leetcode.com/problems/jewels-and-stones/)

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You're given strings `jewels` representing the types of stones that are jewels, and `stones` representing the stones you have. Each character in `stones` is a type of stone you have. You want to know how many of the stones you have are also jewels.

Letters are case sensitive, so `"a"` is considered a different type of stone from `"A"`.

 

**Example 1:**

```
Input: jewels = "aA", stones = "aAAbbbb"
Output: 3
```

**Example 2:**

```
Input: jewels = "z", stones = "ZZ"
Output: 0
```

 

**Constraints:**

- `1 <= jewels.length, stones.length <= 50`

- `jewels` and `stones` consist of only English letters.

- All the characters of `jewels` are **unique**.

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
    public int numJewelsInStones(String jewels, String stones) {
        char[] jewel = jewels.toCharArray();
        char[] stone = stones.toCharArray();
        int count =0;
        for(int i=0;i<stone.length;i++){
            for(int j=0;j<jewel.length;j++){
                if(stone[i] == jewel[j]){
                    count++;
                    break;
                }
            }
        }
        return count;
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
