class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        int n=nums.size();
        int left=0,right=0;
        int sum=0;
        int length= INT_MAX;
        while(right<n)
        {
            sum+=nums[right];
            while(sum>=k)
            {
                sum-=nums[left];
                length=min(length,right-left+1);
                left++;
            }
            right++;
        }
        return (length==INT_MAX)?0:length;
    }
};


