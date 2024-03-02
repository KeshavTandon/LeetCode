class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int start=0,end=n-1;
        for(int i=n-1;i>=0;i--)
        {
            if(abs(nums[start]*nums[start])>=abs(nums[end]*nums[end]))
            {
                ans[i]=abs(nums[start]*nums[start]);
                start++;
            }
            else{
                ans[i]=abs(nums[end]*nums[end]);
                end--;
            }
        }
        return ans;
    }
};