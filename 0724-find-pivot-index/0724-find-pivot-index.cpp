class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        vector<int>leftPrefix(n),rightPrefix(n);
        leftPrefix[0]=nums[0],rightPrefix[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
        {
            leftPrefix[i]=leftPrefix[i-1]+nums[i];
        }
        
        for(int i=n-2;i>=0;i--)
        {
            rightPrefix[i]=rightPrefix[i+1]+nums[i];
        }
        
        for(int i=0;i<n;i++)
        {
            if(i==0){
                if(rightPrefix[i+1]==0){
                    return 0;
                }
            }
            else if(i==n-1)
            {
                if(leftPrefix[i-1]==0)
                    return n-1;
            }
            else if(leftPrefix[i-1]==rightPrefix[i+1])
                return i;
        }
        return -1;
    }
};
//[1,8,11,17,22,28] ->left
//[28,27,20,17,11,6] ->right