class Solution {
public:
    int dp[101][10001];
    int solve(int e,int f){
        if(e==1)return f;//e==0 is an invalid input
        if(f==0 || f==1)return f;
        if(dp[e][f]!=-1)return dp[e][f];
        int mn=INT_MAX;
        for(int k=1;k<=f;k++){
            //here, max because of worst case includes all attemps
            int temp=1+max(solve(e-1,k-1),solve(e,f-k));//at kth floor if it's break, if it's not breaks
            mn=min(mn,temp);//min attempts to find the threshold floor
        }
        return dp[e][f]=mn;
    }
    int superEggDrop(int e, int f) {
        memset(dp,-1,sizeof(dp));
        return solve(e,f);
    }
};
