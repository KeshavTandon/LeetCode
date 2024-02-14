class Solution {
public:
    int dp[201][201];
    int solve(int row,int col,vector<vector<int>>&grid,int row_size,int col_size)
    {
        if(row==row_size-1 && col==col_size-1) return grid[row][col];
        if(dp[row][col]!=-1) return dp[row][col];
        if(row==row_size-1) 
            return grid[row][col]+solve(row,col+1,grid,row_size,col_size);
        else if(col==col_size-1)
            return grid[row][col]+solve(row+1,col,grid,row_size,col_size);
        else
            return dp[row][col]=grid[row][col]+min(solve(row+1,col,grid,row_size,col_size),solve(row,col+1,grid,row_size,col_size));
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int row_size=grid.size(),col_size=grid[0].size();
        return solve(0,0,grid,row_size,col_size);
    }
};