class Solution {
public:
    int solve(int row,int col,int m,int n,vector<vector<int>>&dp)
    {
        if(row==m-1 && col==n-1)
            return 1;
        int down=0,right=0;
        if(dp[row][col]!=-1) return dp[row][col];
        if(row==m-1)
            right=solve(row,col+1,m,n,dp);
        if(col==n-1)
            down=solve(row+1,col,m,n,dp);
        if(row>=0 && col>=0 && row<m && col<n)
        {
            down=solve(row+1,col,m,n,dp);
            right=solve(row,col+1,m,n,dp);
        }
        return dp[row][col]=down+right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(0,0,m,n,dp);
    }
};