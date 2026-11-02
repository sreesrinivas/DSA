class Solution {
public:
    #define ll long long

    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();

        int lh = n / 2;
        int rh = n - lh;

        vector<vector<ll>> leftSum(lh + 1), rightSum(rh + 1);

        for (int mask = 0; mask < (1 << lh); mask++) {
            ll sum = 0;
            int cnt = 0;

            for (int i = 0; i < lh; i++) {
                if (mask & (1 << i)) {
                    sum += nums[i];
                    cnt++;
                }
            }

            leftSum[cnt].push_back(sum);
        }

        for (int mask = 0; mask < (1 << rh); mask++) {
            ll sum = 0;
            int cnt = 0;

            for (int i = 0; i < rh; i++) {
                if (mask & (1 << i)) {
                    sum += nums[lh + i];
                    cnt++;
                }
            }

            rightSum[cnt].push_back(sum);
        }

        for (auto &v : rightSum)
            sort(v.begin(), v.end());

        ll total = accumulate(nums.begin(), nums.end(), 0LL);

        for (int k = 1; k <= n / 2; k++) {

            if ((total * k) % n != 0)
                continue;

            ll target = (total * k) / n;

            for (int lc = 0; lc <= min(k, lh); lc++) {

                int rc = k - lc;

                if (rc > rh)
                    continue;

                auto &vec = rightSum[rc];

                for (ll left : leftSum[lc]) {

                    ll need = target - left;

                    auto it = lower_bound(vec.begin(), vec.end(), need);

                    if (it != vec.end() && *it == need)
                        return true;
                }
            }
        }

        return false;
    }
};
