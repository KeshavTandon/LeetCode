class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans(numRows);
        for(int i=0;i<numRows;i++)
        {
            ans[i]=vector<int>(i+1,1); //every ith row has i+1 elements
            for(int row=1;row<i;row++)
            {
                ans[i][row]=ans[i-1][row-1]+ans[i-1][row];
            }
        }
        return ans;
    }
};