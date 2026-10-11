# [394. Decode String](https://leetcode.com/problems/decode-string/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given an encoded string, return its decoded string.

The encoding rule is: `k[encoded_string]`, where the `encoded_string` inside the square brackets is being repeated exactly `k` times. Note that `k` is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, `k`. For example, there will not be input like `3a` or `2[4]`.

The test cases are generated so that the length of the output will never exceed `105`.

 

**Example 1:**

```
Input: s = "3[a]2[bc]"
Output: "aaabcbc"
```

**Example 2:**

```
Input: s = "3[a2[c]]"
Output: "accaccacc"
```

**Example 3:**

```
Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
```

 

**Constraints:**

- `1 <= s.length <= 30`

- `s` consists of lowercase English letters, digits, and square brackets `'[]'`.

- `s` is guaranteed to be **a valid** input.

- All the integers in `s` are in the range `[1, 300]`.

---

## 💡 Solution Explanation

Optimal iterative solution using a single pass to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.java)**

```java
class Solution {
    public String decodeString(String s) {
        Stack<StringBuilder> st=new Stack<>();
        Stack<Integer> count=new Stack<>();
        int num=0;
        StringBuilder curr=new StringBuilder();
        for(char ch:s.toCharArray()){
            if(Character.isDigit(ch)) num=num*10+(ch-'0');
            else if(ch=='['){
                count.push(num);
                st.push(curr);
                num=0;
                curr=new StringBuilder();
            }
            else if(ch==']'){
                int temp=count.pop();
                StringBuilder prev=st.pop();
                while(temp>0){
                    prev.append(curr);
                    temp--;
                }
                curr=prev;
            }
            else curr.append(ch);
        }
        return curr.toString();
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
