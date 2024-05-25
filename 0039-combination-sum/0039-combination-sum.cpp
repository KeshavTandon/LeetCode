class Solution {
public:
    void solve(int index,vector<int>& candidates,vector<vector<int>>&ans,vector<int>&temp,int target)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        if(target<0)
            return;
        for(int i=index;i<candidates.size();i++)
        {
            temp.push_back(candidates[i]);
            solve(i,candidates,ans,temp,target-candidates[i]);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,candidates,ans,temp,target);
        return ans;
    }
};