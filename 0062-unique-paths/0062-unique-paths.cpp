class Solution
{
    public:
        int solve(int row, int col,vector<vector<int>>&dp)
        {
            if (row == 0 && col == 0)
            {
                return 1;
            }
            if (row < 0 || col < 0)
                return 0;
            
            if(dp[row][col]!=-1) return dp[row][col];

            int up = 0, left = 0;

            up = solve(row - 1, col,dp);
            left = solve(row, col - 1,dp);

            return dp[row][col]=up + left;
        }

    int uniquePaths(int m, int n)
    {
       	//Either i can go to up or left
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m - 1, n - 1,dp);
    }
};