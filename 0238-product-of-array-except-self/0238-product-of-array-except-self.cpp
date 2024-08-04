class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix(n),suffix(n),ans(n);
        prefix[0]=nums[0];
        suffix[n-1]=nums[n-1];
        for(int i=1;i<n-1;i++)
        {
            prefix[i]=prefix[i-1] * nums[i];
        }
        for(int i=n-2;i>=0;i--)
        {
            suffix[i]=suffix[i+1] * nums[i];
        }
        for(int i=0;i<n;i++)
        {
            if(i==0)
                ans[i]=suffix[i+1];
            else if(i==n-1)
                ans[i]=prefix[i-1];
            else
                ans[i]=prefix[i-1] * suffix[i+1];
        }
        return ans;
    }
};

//[1,2,3,4]
//[1,2,6,24] ->prefix
//[24,24,12,4] ->suffix
//for each index i, prefix[i-1] * suffix[i+1]
//[]