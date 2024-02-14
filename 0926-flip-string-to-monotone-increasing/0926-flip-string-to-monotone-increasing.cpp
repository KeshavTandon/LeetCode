class Solution {
public:
    int solve(int index,string &s,int prev,vector<vector<int>>&dp)
    {
        if(index>=s.size())
        {
            return 0;
        }
        if(dp[index][prev]!=-1) return dp[index][prev];
        int flip=INT_MAX,no_flip=INT_MAX;
        if(s[index]=='0')
        {
            if(prev==0)
            {
                flip=1+solve(index+1,s,1,dp);
                no_flip=0+solve(index+1,s,0,dp);
            }
            else{
                flip=1+solve(index+1,s,1,dp);
            }
        }
        else if(s[index]=='1')
        {
            if(prev==0)
            {
                flip=1+solve(index+1,s,0,dp);
                no_flip=0+solve(index+1,s,1,dp);
            }
            else{
                no_flip=0+solve(index+1,s,1,dp);
            }
        }
        return dp[index][prev]=min(flip,no_flip);   
    }
    
    int minFlipsMonoIncr(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,s,0,dp);
    }
};