class Solution {
public:
    bool solve(int index,vector<int>&nums,int target,vector<vector<int>>&dp)
    {
        if(target==0) return true;
        if(target<0) return false;
        if(index>=nums.size()) return false;
        if(dp[index][target]!=-1) return dp[index][target];
        bool include=solve(index+1,nums,target-nums[index],dp);
        bool exclude=solve(index+1,nums,target,dp);
        return dp[index][target]=include || exclude;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int tot_sum=0;
        for(int i=0;i<nums.size();i++)
            tot_sum+=nums[i];
        int temp=tot_sum/2;
        vector<vector<int>>dp(n,vector<int>(temp+1,-1));
        if(tot_sum%2!=0)//odd
            return false;
        else
            return solve(0,nums,tot_sum/2,dp);
    }
};