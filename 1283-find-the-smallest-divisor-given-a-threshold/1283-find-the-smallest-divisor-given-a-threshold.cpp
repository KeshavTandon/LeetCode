class Solution {
public:
    bool isPossible(vector<int>&nums,int mid,int t)  
    {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans+=ceil(double(nums[i])/double(mid));
        }
        return ans<=t;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start=1;
        int end=*max_element(nums.begin(),nums.end());
        int ans=INT_MAX;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(isPossible(nums,mid,threshold))
            {
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
};