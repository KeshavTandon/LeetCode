class Solution {
public:
    int dp[50001][2];
    int solve(int index,int buy,vector<int>&prices,int fee)
    {
        if(index==prices.size()) return 0;
        int profit=0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        if(buy)
        {
            profit=max(-prices[index]-fee+solve(index+1,0,prices,fee),0+solve(index+1,1,prices,fee));
        }
        else{
            profit=max(prices[index]+solve(index+1,1,prices,fee),0+solve(index+1,0,prices,fee));
        }
        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
         memset(dp,-1,sizeof(dp));
        return solve(0,1,prices,fee);
    }
};