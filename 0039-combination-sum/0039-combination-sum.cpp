class Solution
{
    public:
        void solve(int index, vector<int> &candidates, vector<vector< int >> &ans, vector< int > &temp, int target)
        {
            if (index == candidates.size())
            {
                if (target == 0)
                {
                    ans.push_back(temp);
                    
                }
                return;
            }

            if (target < 0)
                return;
            if (target >= candidates[index])
            {
               	//picking up
                temp.push_back(candidates[index]);
                solve(index, candidates, ans, temp, target - candidates[index]);
                temp.pop_back();
            }

           	//not picking up
            solve(index + 1, candidates, ans, temp, target);
        }
    vector<vector < int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector < int>> ans;
        vector<int> temp;
        solve(0, candidates, ans, temp, target);
        return ans;
    }
};