class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // for(int i=0;i<n+1;i++)
        // {
        //     for(int j=0;j<m+1;j++)
        //     {
        //         if(i==0 || j==0)
        //         dp[i][j]=0;
        //     }
        // }
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(s1[i-1]==s2[j-1])
                 dp[i][j]=1+dp[i-1][j-1];
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        //  for(int i=0;i<n+1;i++)
        // {
        //     for(int j=0;j<m+1;j++)
        //     {
        //         cout << dp[i][j]  << " ";
        //     }
        //      cout << endl;
        // }
        
        
        
        int i=n,j=m;
        string ans="";
        while(i>0 && j>0)
        {
            if(s1[i-1]==s2[j-1])
            {
                ans+=s1[i-1];
                i--,j--;
            }
            else if(dp[i][j-1]>dp[i-1][j])
            {
                ans+=s2[j-1];
                j--;
            }
            else{
                ans+=s1[i-1];
                i--;
            }
        }
        while(i>0)
        {
            // cout << "Inside i";
            // cout << s2[i-1] << endl;
            ans+=s1[i-1];
            i--;
        }
        while(j>0)
        {
            // cout << "Inside j";
            // cout << s1[j-1] << endl; 
            ans+=s2[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};