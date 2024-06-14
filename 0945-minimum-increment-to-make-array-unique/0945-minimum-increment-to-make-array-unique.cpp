class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n=nums.size();
        int moves=0;
        int maxi=*max_element(nums.begin(),nums.end());
        vector<int>count(n+maxi,0);
        for(int i=0;i<n;i++)
        {
            count[nums[i]]++;
        }
        for(int i=0;i<n+maxi;i++)
        {
            if(count[i]<=1) 
                continue;
            int extras=count[i]-1;
            moves+=extras;
            count[i]=1;
            count[i+1]+=extras;
        }
        return moves;
        
    }
};