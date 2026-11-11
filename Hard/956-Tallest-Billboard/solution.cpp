class Solution {
    int dp[21][10003];
    int ans = 0 ;
public:
    int solve(int i , int sum, vector<int> & rods){
        if(i>=rods.size()) return sum == 0? 0 : -1 ; 
        if(dp[i][sum+5000]) return dp[i][sum+5000];
        int x = solve(i+1,sum + rods[i],rods);
        x = x == -1? -1 : x + rods[i];
        int y = solve(i+1,sum - rods[i],rods);
        int z = solve(i+1,sum,rods);
        return dp[i][sum + 5000] = max({x,y,z});

    }
    int tallestBillboard(vector<int>& rods) {
        memset(dp,0,sizeof(dp));
        int ans =  solve(0,0,rods);
        return ans==-1?-1:ans;
    }
};
