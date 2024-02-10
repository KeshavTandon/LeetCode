class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        int count=0;
        for(int length=1;length<=n;length++)
        {
            for(int i=0;i+length-1<n;i++)
            {
                int j=i+length-1;
                if(i==j) //length=1 always true
                    dp[i][j]=true;
                else if(i+1==j) //length=2
                    dp[i][j]=(s[i]==s[j]);
                else
                    dp[i][j]=(s[i]==s[j] && dp[i+1][j-1]);
                
                if(dp[i][j]==true) count++;
            }
        }
        return count;
    }
};