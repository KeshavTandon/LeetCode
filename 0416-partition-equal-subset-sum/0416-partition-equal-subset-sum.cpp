class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++) 
            sum+=nums[i];
        int n=nums.size();
        int fin_sum=sum/2;
        vector<vector<bool>>dp(n+1,vector<bool>(fin_sum+1,false));
        if(sum%2!=0) return false;
        else
        {
            for(int i=0;i<n+1;i++){
                for(int j=0;j<fin_sum+1;j++)
                {
                    if(i==0)
                        dp[i][j]=false;
                    if(j==0) 
                        dp[i][j]=true;
                }
            }
            
            for(int i=1;i<n+1;i++)
            {
                for(int j=1;j<fin_sum+1;j++)
                {
                    if(nums[i-1]<=j)
                    {
                        dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
                    }
                    else
                        dp[i][j]=dp[i-1][j];
                }
            }
        }
           return dp[n][fin_sum]; 
    }
};