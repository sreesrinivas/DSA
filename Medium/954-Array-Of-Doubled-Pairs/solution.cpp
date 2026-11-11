class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int& a, int& b) {
            return abs(a) < abs(b);
        });

        unordered_map<int, int> mp;
        for (int& x : arr)
            mp[x]++;

        for (int& x : arr) {
            if (mp[x] == 0)
                continue;

            if (mp[2 * x] <= 0)
                return false;

            mp[2 * x]--;
            mp[x]--;
        }

        return true;
    }
};
