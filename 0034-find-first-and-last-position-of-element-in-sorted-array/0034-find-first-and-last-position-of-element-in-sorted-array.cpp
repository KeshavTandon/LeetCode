class Solution {
public:
    int findFirstOccurence(int start,int end,vector<int>&nums,int target)
    {
        int ans=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                end=mid-1;
            }
            else if(nums[mid]<target)
            {
                start=mid+1;
            }
            else end=mid-1;
        }
        return ans;
    }
    
    int findLastOccurence(int start,int end,vector<int>&nums,int target)
    {
        int ans=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                start=mid+1;
            }
            else if(nums[mid]<target)
            {
                start=mid+1;
            }
            else end=mid-1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int ans1=findFirstOccurence(0,nums.size()-1,nums,target);
        int ans2=findLastOccurence(0,nums.size()-1,nums,target);
        vector<int>p={ans1,ans2};
        return p;
    }
};