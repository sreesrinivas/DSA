# [966. Vowel Spellchecker](https://leetcode.com/problems/vowel-spellchecker/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given a `wordlist`, we want to implement a spellchecker that converts a query word into a correct word.

For a given `query` word, the spell checker handles two categories of spelling mistakes:

- Capitalization: If the query matches a word in the wordlist (**case-insensitive**), then the query word is returned with the same case as the case in the wordlist.

	
Example: `wordlist = ["yellow"]`, `query = "YellOw"`: `correct = "yellow"`
Example: `wordlist = ["Yellow"]`, `query = "yellow"`: `correct = "Yellow"`
Example: `wordlist = ["yellow"]`, `query = "yellow"`: `correct = "yellow"`

- Vowel Errors: If after replacing the vowels `('a', 'e', 'i', 'o', 'u')` of the query word with any vowel individually, it matches a word in the wordlist (**case-insensitive**), then the query word is returned with the same case as the match in the wordlist.
	
Example: `wordlist = ["YellOw"]`, `query = "yollow"`: `correct = "YellOw"`
Example: `wordlist = ["YellOw"]`, `query = "yeellow"`: `correct = ""` (no match)
Example: `wordlist = ["YellOw"]`, `query = "yllw"`: `correct = ""` (no match)

In addition, the spell checker operates under the following precedence rules:

- When the query exactly matches a word in the wordlist (**case-sensitive**), you should return the same word back.

- When the query matches a word up to capitalization, you should return the first such match in the wordlist.

- When the query matches a word up to vowel errors, you should return the first such match in the wordlist.

- If the query has no matches in the wordlist, you should return the empty string.

Given some `queries`, return a list of words `answer`, where `answer[i]` is the correct word for `query = queries[i]`.

 

**Example 1:**

```
Input: wordlist = ["KiTe","kite","hare","Hare"], queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
Output: ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]
```

**Example 2:**

```
Input: wordlist = ["yellow"], queries = ["YellOw"]
Output: ["yellow"]
```

 

**Constraints:**

- `1 <= wordlist.length, queries.length <= 5000`

- `1 <= wordlist[i].length, queries[i].length <= 7`

- `wordlist[i]` and `queries[i]` consist only of only English letters.

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
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exactMatchSet(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseInsensitiveMap;
        unordered_map<string, string> vowelInsensitiveMap;

        auto normalizeVowels = [](const string& word) {
            string res = word;
            for (char& c : res) {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    c = '*';
                }
            }
            return res;
        };

        for (string& word : wordlist) {
            string lowerWord = word;
            transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);

            if (!caseInsensitiveMap.count(lowerWord)) {
                caseInsensitiveMap[lowerWord] = word;
            }

            string vowelNormalized = normalizeVowels(lowerWord);
            if (!vowelInsensitiveMap.count(vowelNormalized)) {
                vowelInsensitiveMap[vowelNormalized] = word;
            }
        }

        vector<string> results;
        for (string& query : queries) {
            if (exactMatchSet.count(query)) {
                results.push_back(query);
                continue;
            }

            string lowerQuery = query;
            transform(lowerQuery.begin(), lowerQuery.end(), lowerQuery.begin(), ::tolower);
            if (caseInsensitiveMap.count(lowerQuery)) {
                results.push_back(caseInsensitiveMap[lowerQuery]);
                continue;
            }

            string vowelNormalized = normalizeVowels(lowerQuery);
            if (vowelInsensitiveMap.count(vowelNormalized)) {
                results.push_back(vowelInsensitiveMap[vowelNormalized]);
                continue;
            }

            results.push_back(""); // No match
        }
        return results;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
