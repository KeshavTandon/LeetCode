class Solution {
public:
    void solve(int start,int size,int target, vector<vector<int>>&ans,vector<int>&temp)
    {
        //Base Case
        if(temp.size()==size)
        {
            if(target==0)
            {
                ans.push_back(temp);
            }
            return;
        }
        
        for(int ele=start;ele<=9;ele++)
        {
            if(ele<=target)
            {
                temp.push_back(ele);
                solve(ele+1,size,target-ele,ans,temp);
                temp.pop_back();
            }
        }
    }
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(1,k,n,ans,temp);
        return ans;
    }
};