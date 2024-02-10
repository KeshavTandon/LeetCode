class Solution {
public:
    int dp[1001][1001];
    bool checkPalindrome(int start,int end,string &s)
    {
        if(start>=end) return true;
        if(dp[start][end]!=-1) return dp[start][end];
        if(s[start]==s[end])
            return checkPalindrome(start+1,end-1,s);
        
        return dp[start][end]=false;
    }
    string longestPalindrome(string s) {
        memset(dp,-1,sizeof(dp));
        int n=s.size();
        int maxLength=-1,sp=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(checkPalindrome(i,j,s))
                {
                    if(j-i+1>maxLength){
                        maxLength=j-i+1;
                        sp=i;
                    }
                }
            }
        }
        return s.substr(sp,maxLength);
    }
};