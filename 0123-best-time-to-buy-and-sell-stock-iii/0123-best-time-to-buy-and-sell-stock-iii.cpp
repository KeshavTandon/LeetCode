class Solution {
public:
    int calculateProfit(int index,vector<int>&prices,int buy,int cap,vector<vector<vector<int>>>&dp)
    {
        if(cap==0) return 0;
        if(index==prices.size()) return 0;
        
        if(dp[index][buy][cap]!=-1) return dp[index][buy][cap];
        if(buy)//1
        {
            return dp[index][buy][cap]=max(-prices[index]+calculateProfit(index+1,prices,0,cap,dp),0+calculateProfit(index+1,prices,buy,cap,dp));
        }
        else{ //selling
            return dp[index][buy][cap]=max(prices[index]+calculateProfit(index+1,prices,1,cap-1,dp),calculateProfit(index+1,prices,buy,cap,dp));
        }
    }
    
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        return calculateProfit(0,prices,1,2,dp);
    }
};