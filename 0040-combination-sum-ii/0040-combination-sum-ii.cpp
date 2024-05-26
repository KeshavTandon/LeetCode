class Solution {
public:
    void solve(int index,vector<int>& candidates,vector<vector<int>>&ans,vector<int>&temp,int target)
    {
        if(index>=candidates.size())
        {
            if(target==0)
            {
                ans.push_back(temp);
            }
            return;
        }
        if(target==0)
        {
            ans.push_back(temp);
            return;
         }
        
        if(target<0)
            return;
        
        for(int i=index;i<candidates.size();i++)
        {
            if((index==i || candidates[i-1]!=candidates[i]) && (candidates[i]<=target))
            {
                temp.push_back(candidates[i]);
                solve(i+1,candidates,ans,temp,target-candidates[i]);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,candidates,ans,temp,target);
        return ans;
    }
};