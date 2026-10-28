class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size(); 
        vector<int> bucket_partial_sum(1 << n, 0); 
        int total_sum = 0; 
        for(int i = 0;i < n; i++){
            total_sum += nums[i]; 
        }
        if(total_sum % k) return false; 
        int t_sum = total_sum / k; 
        for(int i = 1;i < (1 <<n); i++){
            int sum = 0; 
            for(int j = 0; j < n; j++){
                if(i & (1 << j)){
                    sum += nums[j]; 
                }
            }
            bucket_partial_sum[i] = sum % t_sum; 
        }

        vector<bool> dp(1 << n, false); 
        dp[0] = true; 
        for(int mask = 1; mask < (1 << n); mask++){
            for(int i = 0;i < n; i++){
                if(!(mask & (1 << i))) continue; 

                int prev_mask = mask & (~(1 << i)); 
                if(dp[prev_mask] && (nums[i] + bucket_partial_sum[prev_mask] <= t_sum)){
                    dp[mask] = true; 
                }
            }
        }

        return dp[(1 << n) - 1]; 
    }
};
