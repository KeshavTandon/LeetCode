class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int positivePointer=0;
        int negativePointer=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                ans[positivePointer]=nums[i];
                positivePointer+=2;
            }
            else{
                ans[negativePointer]=nums[i];
                negativePointer+=2;
            }
        }
        return ans;
    }
};