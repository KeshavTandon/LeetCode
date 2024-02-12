class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        unordered_map<long,int>mp[n]; //array of map
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                long diff=(long)nums[i]-nums[j];
                auto it=mp[j].find(diff);
                long count_on_j= it==mp[j].end()?0:it->second;
                ans+=count_on_j;
                mp[i][diff]+=count_on_j+1;
            }
        }
        return ans;
    }
};