class Solution {
public:
    void solve(vector<int>&dp,int n,int index)
    {
        if(index==n){
            if(index%2==0)
            {
                dp[index]=dp[index/2];
            }else
                dp[index]=dp[index/2]+1;
            return;
        }
        if(index%2==0)
            dp[index]=dp[index/2];
        if(index%2!=0)
            dp[index]=dp[index/2]+1;
        solve(dp,n,index+1);
    }
    vector<int> countBits(int n) {
        vector<int>dp(n+1,-1);
        dp[0]=0;
        if(n==0) return dp;
        else solve(dp,n,1);
        return dp;
    }
};