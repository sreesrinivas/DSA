# [804. Unique Morse Code Words](https://leetcode.com/problems/unique-morse-code-words/)

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows:

- `'a'` maps to `".-"`,

- `'b'` maps to `"-..."`,

- `'c'` maps to `"-.-."`, and so on.

For convenience, the full table for the `26` letters of the English alphabet is given below:

```
[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
```

Given an array of strings `words` where each word can be written as a concatenation of the Morse code of each letter.

- For example, `"cab"` can be written as `"-.-..--..."`, which is the concatenation of `"-.-."`, `".-"`, and `"-..."`. We will call such a concatenation the **transformation** of a word.

Return *the number of different **transformations** among all words we have*.

 

**Example 1:**

```
Input: words = ["gin","zen","gig","msg"]
Output: 2
Explanation: The transformation of each word is:
"gin" -> "--...-."
"zen" -> "--...-."
"gig" -> "--...--."
"msg" -> "--...--."
There are 2 different transformations: "--...-." and "--...--.".
```

**Example 2:**

```
Input: words = ["a"]
Output: 1
```

 

**Constraints:**

- `1 <= words.length <= 100`

- `1 <= words[i].length <= 12`

- `words[i]` consists of lowercase English letters.

---

## 💡 Solution Explanation

Hash-table lookup approach enabling constant-time O(1) element retrieval to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.py)**

```python
class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        # Define the English alphabet
        letters = "abcdefghijklmnopqrstuvwxyz"
        
        # Define the corresponding Morse code representations
        morse_code = [".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."]

        # Create a dictionary that maps letters to Morse code
        morse_dict = dict(zip(letters, morse_code))

        # Initialize a list to store words converted to Morse code
        words2 = []

        # Iterate through each word in the input list
        for word in words:
            # Initialize an empty string to store the Morse code for the current word
            k = ""
            
            # Iterate through each character in the current word
            for i in word:
                # Append the Morse code representation of the character to the string
                k += morse_dict[i]

            # Append the Morse code for the current word to the list
            words2.append(k) 

        # Return the count of unique Morse code representations
        return len(set(words2))
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
