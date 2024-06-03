class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum=0;
        unordered_map<int,int>mp;
        int ans=0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            int rem_sum=sum-goal;
            if(mp.find(rem_sum)!=mp.end())
            {
                //found
                ans+=mp[rem_sum];
            }
            mp[sum]++;
        }
        return ans;
    }
};