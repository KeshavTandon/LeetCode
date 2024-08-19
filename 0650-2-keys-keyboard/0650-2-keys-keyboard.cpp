class Solution {
public:
    int dp[1000][1000];
    int solve(int currA,int clip,int n)
    {
        if(currA==n)
            return 0;
        
        if(currA>n)
            return 1000000;
        
        if(dp[currA][clip]!=-1)
            return dp[currA][clip];
        
        int copyAllPaste=1+1+solve(currA+currA,currA,n);
        
        int paste=1+solve(currA+clip,clip,n);
        
        return dp[currA][clip]=min(copyAllPaste,paste);
    }
    int minSteps(int n) {
        if(n==1) return 0;
        memset(dp,-1,sizeof(dp));
       return 1+solve(1,1,n);
    }
};
//Either i can copy all or i can paste
//Base -> size of temp>=n return count
