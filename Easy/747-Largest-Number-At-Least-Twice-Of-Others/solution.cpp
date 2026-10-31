class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();
        int maxele = *max_element(nums.begin(), nums.end());
        int idx = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == maxele) {
                idx = i;
            } else {
                if (nums[i] * 2 > maxele) {
                    return -1;
                }
            }
        }

        return idx;
    }
};
