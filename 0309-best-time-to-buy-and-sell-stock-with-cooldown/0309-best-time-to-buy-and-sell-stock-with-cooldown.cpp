class Solution {
public:
    int dp[5000][2];
    int solve(int index,vector<int>&prices,int n,bool flag)
    {
        if(index>=n) return 0;
        int profit=0;
        if(dp[index][flag]!=-1) return dp[index][flag];
        if(flag)//true ->i can buy that stock
        {
            int take=solve(index+1,prices,n,false)-prices[index];
            int not_take=solve(index+1,prices,n,true);
            profit=max(take,not_take);
        }
        else{  //false->i can sell the stock
            int sell=prices[index]+solve(index+2,prices,n,true);
            int not_sell=solve(index+1,prices,n,false);
            profit=max(sell,not_sell);
        }
        return dp[index][flag]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,prices,n,true);
    }
};