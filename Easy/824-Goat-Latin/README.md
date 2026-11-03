# [824. Goat Latin](https://leetcode.com/problems/goat-latin/)

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given a string `sentence` that consist of words separated by spaces. Each word consists of lowercase and uppercase letters only.

We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.) The rules of Goat Latin are as follows:

- If a word begins with a vowel (`'a'`, `'e'`, `'i'`, `'o'`, or `'u'`), append `"ma"` to the end of the word.

	
For example, the word `"apple"` becomes `"applema"`.

- If a word begins with a consonant (i.e., not a vowel), remove the first letter and append it to the end, then add `"ma"`.
	
For example, the word `"goat"` becomes `"oatgma"`.

- Add one letter `'a'` to the end of each word per its word index in the sentence, starting with `1`.
	
For example, the first word gets `"a"` added to the end, the second word gets `"aa"` added to the end, and so on.

Return* the final sentence representing the conversion from sentence to Goat Latin*.

 

**Example 1:**

```
Input: sentence = "I speak Goat Latin"
Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
```

**Example 2:**

```
Input: sentence = "The quick brown fox jumped over the lazy dog"
Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
```

 

**Constraints:**

- `1 <= sentence.length <= 150`

- `sentence` consists of English letters and spaces.

- `sentence` has no leading or trailing spaces.

- All the words in `sentence` are separated by a single space.

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
    string toGoatLatin(string sentence) {
        string ans = "", temp = "";
        int k = 0;
        for(int i = 0; i < sentence.size();i++){
            if(sentence[i] != ' ') temp += sentence[i];
            else{
                if(temp[0] == 97 || temp[0] == 101 || temp[0] == 105 || temp[0] == 111 || temp[0] == 117 || temp[0] == 65 || temp[0] == 69 || temp[0] == 73 || temp[0] == 79 || temp[0] == 85){
                    temp += "ma";
                }
                else{
                    temp = temp + temp[0] + "ma";
                    temp = temp.substr(1);
                }
                for(int j = 0; j <= k; j++){
                    temp += "a";
                }
                k++;
                cout<<temp<<endl;
                ans += temp + " ";
                temp = "";
            }
        }
        if(temp[0] == 97 || temp[0] == 101 || temp[0] == 105 || temp[0] == 111 || temp[0] == 117 || temp[0] == 65 || temp[0] == 69 || temp[0] == 73 || temp[0] == 79 || temp[0] == 85){
            temp += "ma";
        }
        else{
            temp = temp + temp[0] + "ma";
            temp = temp.substr(1);
        }
        for(int j = 0; j <= k; j++){
            temp += "a";
        }
        ans += temp;
        return ans;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
