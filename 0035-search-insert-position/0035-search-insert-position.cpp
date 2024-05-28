class Solution {
public:
    int findLowerBound(int start,int end,int target,vector<int>&nums)
    {
        int ans=nums.size();
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]>=target)
            {
                ans=mid;
                end=mid-1;
            }
            else
                start=mid+1;
        }
        return ans;
    }
    
    int searchInsert(vector<int>& nums, int target) {
        //finding the lower bound will give me the answer
       int ans= findLowerBound(0,nums.size()-1,target,nums);
        return ans;
        
    }
};