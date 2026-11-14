// OJ: https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool isValid(string s) {
        int i = 0, N = s.size();
        for (int j = 0; j < N; ++j) {
            s[i++] = s[j];
            if (i >= 3 && s[i - 3] == 'a' && s[i - 2] == 'b' && s[i - 1] == 'c') i -= 3;
        }
        return i == 0;
    }
};
