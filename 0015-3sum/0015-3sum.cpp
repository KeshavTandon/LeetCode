class Solution {
public:
    void TwoSum(vector<int>&nums,int target,int start,vector<vector<int>>&ans)
    {
        int end=nums.size()-1;
        while(start<end)
        {
            int total=nums[start]+nums[end];
            if(total==target)
            { 
                ans.push_back({-target,nums[start],nums[end]});
                start++,end--;
                while(start<end && nums[start]==nums[start-1]) start++;
                while(start<end && nums[end]==nums[end+1]) end--;
                    
                
            }
            else if(total<target) start++;
            else end--;
        }
        return;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        if(n<3)
        {
            return {};
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            int target=-nums[i];
            TwoSum(nums,target,i+1,ans);
        }
        return ans;
    }
};