class Solution {
public:
    int dp[71][71][71];
    int solve(int row,int col1,int col2,vector<vector<int>>&grid,int n,int m)
    {
        if(row>=n) return 0;  //Out Of Bound
        if(dp[row][col1][col2]!=-1) return dp[row][col1][col2];
        int cherry=grid[row][col1];
        if(col1!=col2) cherry+=grid[row][col2]; //no same col should be added
        int ans=0;
        for(int i=-1;i<=1;i++)  //Robot1
        {
            for(int j=-1;j<=1;j++) //Robot2
            {
                int newCol1=col1+i;
                int newCol2=col2+j;
                if(newCol1>=0 && newCol1<m && newCol2>=0 && newCol2<m)
                  ans=max(ans,solve(row+1,newCol1,newCol2,grid,n,m));
            }
        }
        return dp[row][col1][col2]=ans+cherry;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,m-1,grid,n,m);
    }
};