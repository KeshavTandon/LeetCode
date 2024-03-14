class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        int curr_sum=0;
        for(int i=0;i<nums.size();i++)
        {
            curr_sum+=nums[i];
            int rem_sum=curr_sum-goal;
            if(mp.find(rem_sum)!=mp.end())
                ans+=mp[rem_sum];
            mp[curr_sum]++;
        }
        return ans;
    }
};