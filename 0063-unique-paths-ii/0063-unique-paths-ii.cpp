class Solution {
public:
    int solve(int row,int col,vector<vector<int>>& grid,int rows,int cols,vector<vector<int>>& dp)
    {
        if(row==rows-1 && col==cols-1) return 1;
        if(row<0 || row>=rows || col<0 || col>=cols || grid[row][col]==1) return 0;
        if(dp[row][col]!=-1) return dp[row][col];
        int down=0,right=0;
        down=solve(row+1,col,grid,rows,cols,dp);
        right=solve(row,col+1,grid,rows,cols,dp);
        return dp[row][col]=down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows=obstacleGrid.size();
        int cols=obstacleGrid[0].size();
        vector<vector<int>>dp(rows,vector<int>(cols,-1));
        if(obstacleGrid[rows-1][cols-1]==1) return 0;
        return solve(0,0,obstacleGrid,rows,cols,dp);
    }
};