class Solution {
public:
    int solve(vector<int>&nums,int goal)
    {
        if(goal<0) return 0;
        int count=0;
        int left=0,right=0,sum=0;
        while(right<nums.size())
        {
            sum+=(nums[right])%2;
           while(sum>goal)
           {
               sum-=(nums[left])%2;
               left++;
           }
            count+=right-left+1;
            right++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        return solve(nums,k)-solve(nums,k-1);
    }
};