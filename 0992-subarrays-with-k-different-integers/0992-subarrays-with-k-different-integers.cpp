class Solution {
public:
    int subarraysWithatmostKDistinct(vector<int>nums,int k)
    {
        int l=0,r=0,res=0;
        unordered_map<int,int>mp;
        for(r=0;r<nums.size();r++)
        {
            mp[nums[r]]++;
            while(mp.size()>k)
            {
                mp[nums[l]]--;
                if(mp[nums[l]]==0)
                {
                    mp.erase(nums[l]);
                }
                l++;
            }
            res=res+(r-l+1);
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
         return subarraysWithatmostKDistinct(nums,k)-subarraysWithatmostKDistinct(nums,k-1);
    }
};