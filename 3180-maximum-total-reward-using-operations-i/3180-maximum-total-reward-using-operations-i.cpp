class Solution
{
    public:
    int dp[2001][4001];
        int solve(int index, vector<int> &rewardValues, int sum)
        {
            if (index >= rewardValues.size())
            {
               return sum;
            }
            
            if(dp[index][sum]!=-1) return dp[index][sum];

            int notTake = solve(index + 1, rewardValues, sum);
            
            int take=0;
            if (rewardValues[index] > sum)
            {
                take=solve(index + 1, rewardValues, sum+rewardValues[index]);
            }
            return dp[index][sum]=max(take,notTake);
        }
    int maxTotalReward(vector<int> &rewardValues)
    {
        int sum = 0;
        memset(dp,-1,sizeof(dp));
        sort(rewardValues.begin(), rewardValues.end());
        return solve(0, rewardValues, sum);
        
    }
};