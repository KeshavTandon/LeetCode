class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<amount+1;j++)
            {
                if(i==0)
                    dp[i][j]=INT_MAX-1;
                if(j==0)
                    dp[i][j]=0;
            }
        }
        
        //initialising the second row
        for(int i=1;i<amount+1;i++)
        {
            if(i%coins[0]==0)
            dp[1][i]=i/coins[0];
            else dp[1][i]=INT_MAX-1;
        }
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<amount+1;j++)
            {
                if(coins[i-1]<=j)
                {
                    dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
if(dp[n][amount]==INT_MAX || dp[n][amount]==INT_MAX-1)
    return -1;
        return dp[n][amount];
    }
};