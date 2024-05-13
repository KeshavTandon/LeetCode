class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans=INT_MIN;
        if(nums.size()<k) return NULL;
         double avg=0;
        for(int i=0;i<k;i++)
        {
            avg+=nums[i];
        }
        
        ans=avg;
        for(int i=k;i<nums.size();i++)
        {
            // cout << avg << endl;
           avg-=nums[i-k];
           avg+=nums[i];
           ans=max(ans,avg);
        }
        cout << ans << endl;
        return ans/k;
        
    }
};