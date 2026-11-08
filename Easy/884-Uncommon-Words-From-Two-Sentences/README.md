# [884. Uncommon Words from Two Sentences](https://leetcode.com/problems/uncommon-words-from-two-sentences/)

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

A **sentence** is a string of single-space separated words where each word consists only of lowercase letters.

A word is **uncommon** if it appears exactly once in one of the sentences, and **does not appear** in the other sentence.

Given two **sentences** `s1` and `s2`, return *a list of all the **uncommon words***. You may return the answer in **any order**.

 

**Example 1:**

**Input:** s1 = "this apple is sweet", s2 = "this apple is sour"

**Output:** ["sweet","sour"]

**Explanation:**

The word `"sweet"` appears only in `s1`, while the word `"sour"` appears only in `s2`.

**Example 2:**

**Input:** s1 = "apple apple", s2 = "banana"

**Output:** ["banana"]

 

**Constraints:**

- `1 <= s1.length, s2.length <= 200`

- `s1` and `s2` consist of lowercase English letters and spaces.

- `s1` and `s2` do not have leading or trailing spaces.

- All the words in `s1` and `s2` are separated by a single space.

---

## 💡 Solution Explanation

Exhaustive / multi-pass search across candidate elements to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(n)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.cpp)**

```cpp
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        // we need to find unique occurences
        string s = s1 + " " + s2;

        cout<<s1.max_size();

        // store all words from s
        unordered_map<string,int> um;
        string tmp="";
        for(auto& val : s){ // similar to, i=0;i<s.size();i++
            if(val == ' '){
                um[tmp]++;
                tmp = "";
            }
            else{
                tmp += val; // denotes, val = s[i]
            }
        }
        
        // condition needed if empty string allowed
        if(tmp != ""){
            um[tmp]++;
            tmp = "";
        }

        // check unique means single count
        vector<string> ans;
        for(auto& val:um){ // auto it=um.begin();it<um.end();it++

            // val.first = apple, val.second = 2

            if(val.second==1){
                ans.emplace_back(val.first); // can use push_back also                
            }

        }

        return ans;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
