class Solution {
public:
    int solve(vector<int>&nums,int goal)
    {
        if(goal<0) return 0;
        int count=0;
        int left=0,right=0,sum=0;
        while(right<nums.size())
        {
            sum+=nums[right];
           while(sum>goal)
           {
               sum-=nums[left];
               left++;
           }
            count+=right-left+1;
            right++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2!=0)
                nums[i]=1;
            else nums[i]=0;
        }
        return solve(nums,k)-solve(nums,k-1);
    }
};