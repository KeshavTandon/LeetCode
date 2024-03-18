class Solution {
public:
    int solve(int index,vector<int>&nums,vector<vector<int>>&dp,int prev)
    {
        //Base Case
        if(index>=nums.size()) return 0;
        if( dp[index][prev+1]!=-1) return dp[index][prev+1];
        int include=0,exclude=0;
        if(prev==-1 || nums[index]>nums[prev])
            include=1+solve(index+1,nums,dp,index);
        exclude=0+solve(index+1,nums,dp,prev);
        return dp[index][prev+1]=max(include,exclude);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,nums,dp,-1);
    }
};