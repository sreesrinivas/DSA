class Solution {
public:

    string findLongestWord(string s, vector<string>& dictionary) {
        
        int n(size(s));
        auto check = [&](string& str, int len) {
            for (int i=n-1; ~i and len-1>=0; i--)
                if (s[i] == str[len-1]) len--;
            return (len == 0);
        };
        
        string res;
        int maxLen(0);
        
        for (auto& word : dictionary) {
            int len(size(word));
            if (check(word, len) and (maxLen < len or (len == maxLen and (word < res or res.empty())))) {
                maxLen = len;
                res = word;
            }
        }
        return res;
    }
};
