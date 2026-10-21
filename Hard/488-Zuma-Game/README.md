# [488. Zuma Game](https://leetcode.com/problems/zuma-game/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are playing a variation of the game Zuma.

In this variation of Zuma, there is a **single row** of colored balls on a board, where each ball can be colored red `'R'`, yellow `'Y'`, blue `'B'`, green `'G'`, or white `'W'`. You also have several colored balls in your hand.

Your goal is to **clear all** of the balls from the board. On each turn:

- Pick **any** ball from your hand and insert it in between two balls in the row or on either end of the row.

- If there is a group of **three or more consecutive balls** of the **same color**, remove the group of balls from the board.
	
If this removal causes more groups of three or more of the same color to form, then continue removing each group until there are none left.

- If there are no more balls on the board, then you win the game.

- Repeat this process until you either win or do not have any more balls in your hand.

Given a string `board`, representing the row of balls on the board, and a string `hand`, representing the balls in your hand, return *the **minimum** number of balls you have to insert to clear all the balls from the board. If you cannot clear all the balls from the board using the balls in your hand, return *`-1`.

 

**Example 1:**

```
Input: board = "WRRBBW", hand = "RB"
Output: -1
Explanation: It is impossible to clear all the balls. The best you can do is:
- Insert 'R' so the board becomes WRRRBBW. WRRRBBW -> WBBW.
- Insert 'B' so the board becomes WBBBW. WBBBW -> WW.
There are still balls remaining on the board, and you are out of balls to insert.
```

**Example 2:**

```
Input: board = "WWRRBBWW", hand = "WRBRW"
Output: 2
Explanation: To make the board empty:
- Insert 'R' so the board becomes WWRRRBBWW. WWRRRBBWW -> WWBBWW.
- Insert 'B' so the board becomes WWBBBWW. WWBBBWW -> WWWW -> empty.
2 balls from your hand were needed to clear the board.
```

**Example 3:**

```
Input: board = "G", hand = "GGGGG"
Output: 2
Explanation: To make the board empty:
- Insert 'G' so the board becomes GG.
- Insert 'G' so the board becomes GGG. GGG -> empty.
2 balls from your hand were needed to clear the board.
```

 

**Constraints:**

- `1 <= board.length <= 16`

- `1 <= hand.length <= 5`

- `board` and `hand` consist of the characters `'R'`, `'Y'`, `'B'`, `'G'`, and `'W'`.

- The initial row of balls on the board will **not** have any groups of three or more consecutive balls of the same color.

---

## 💡 Solution Explanation

Dynamic programming / memoized recursion approach storing overlapping subproblems to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.java)**

```java
class Solution {
    public int findMinStep(String board, String hand) {
        char[] handArr = hand.toCharArray();
        Arrays.sort(handArr);
        return dfs(board, new String(handArr), new HashMap<>());
    }

    private int dfs(String board, String hand, Map<String, Integer> memo) {
        if (board.isEmpty()) {
            return 0;
        }
        if (hand.isEmpty()) {
            return -1;
        }

        String key = board + '#' + hand;
        if (memo.containsKey(key)) {
            return memo.get(key);
        }

        int minSteps = Integer.MAX_VALUE;

        for (int i = 0; i < hand.length(); i++) {
            // Prune duplicate balls in hand at the same recursion depth
            if (i > 0 && hand.charAt(i) == hand.charAt(i - 1)) {
                continue;
            }

            char ball = hand.charAt(i);
            String nextHand = hand.substring(0, i) + hand.substring(i + 1);

            for (int j = 0; j <= board.length(); j++) {
                // Prune unpromising insertion slots
                if (!isGoodPlace(board, j, ball)) {
                    continue;
                }

                String insertedBoard = board.substring(0, j) + ball + board.substring(j);
                String collapsedBoard = collapse(insertedBoard);

                int subSteps = dfs(collapsedBoard, nextHand, memo);
                if (subSteps != -1) {
                    minSteps = Math.min(minSteps, subSteps + 1);
                }
            }
        }

        int result = (minSteps == Integer.MAX_VALUE) ? -1 : minSteps;
        memo.put(key, result);
        return result;
    }

    private boolean isGoodPlace(String board, int pos, char ball) {
        // Scenario 1: Extend an existing same-color run
        if (pos > 0 && board.charAt(pos - 1) == ball) {
            return true;
        }
        // Scenario 2: Split an identical pair to enable nested cascades
        if (pos > 0 && pos < board.length() && board.charAt(pos - 1) == board.charAt(pos)) {
            return true;
        }
        return false;
    }

    private String collapse(String board) {
        int i = 0;
        while (i < board.length()) {
            int j = i;
            while (j < board.length() && board.charAt(i) == board.charAt(j)) {
                j++;
            }
            if (j - i >= 3) {
                return collapse(board.substring(0, i) + board.substring(j));
            } else {
                i = j;
            }
        }
        return board;
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
