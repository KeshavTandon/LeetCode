class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int total=(1<<n);
        for(int powerSet=0;powerSet<total;powerSet++)
        {
            int xr=0;
            for(int bits=0;bits<n;bits++)
            {
                
                if(powerSet&(1<<bits))
                    xr^=nums[bits];
            }
            ans+=xr;
            
        }
        return ans;
    }
};