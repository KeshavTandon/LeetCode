class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target)
                return true;
            else if(nums[start]==nums[mid] && nums[mid]==nums[end])
            {
                start=start+1;
                end=end-1;
            }
            else if(nums[start]<=nums[mid])
            {
                //left part is sorted
                if(nums[start]<=target && nums[mid]>target)
                {
                    end=mid-1; 
                }
                else start=mid+1;
            }
            else{
                //right part is sorted
                if(nums[mid]<target && nums[end]>=target)
                {
                    start=mid+1;
                }
                else end=mid-1;
            }
        }
        return false;
    }
};