class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count1=0;
        int maj1=NULL;
        int count2=0;
        int maj2=NULL;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==maj1) count1++;
            else if(nums[i]==maj2) count2++;
            else if(count1==0)
            {
                maj1=nums[i];
                count1=1;
            }
            else if(count2==0)
            {
                maj2=nums[i];
                count2=1;
            }
            else{
                count1--,count2--;
            }
        }
        
        int freq1=0,freq2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==maj1) freq1++;
            if(nums[i]==maj2) freq2++;
        }
        
        cout << freq1 << freq2 << endl;
        vector<int>ans;
        if(freq1>floor(n/3))
            ans.push_back(maj1);
        if(freq2>floor(n/3) && maj1!=maj2)
            ans.push_back(maj2);
        return ans;
    }
};