class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int n = s.length();
        vector<vector<int>> ans;
        int i = 0;
        int j = 0, len = 0;
        while (i < n && j <= n) {
            if (j<n && s[i] == s[j]) {
                j++;
            } else {
                len = j - i;

                if (len >= 3) {
                    ans.push_back({i, j - 1});
                }
                i = j;
                j++;
            }
        }
        return ans;
    }
};
