class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>dp(n+1);
        dp[0]=0;
        if(n==0) return dp;
        dp[1]=1;
        if(n==1) return dp;
        dp[2]=1;
        if(n==2) return dp;
        for(int i=3;i<=n;i++)
        {
            if(i&1)
            {
                dp[i]=dp[i/2]+1;
            }
            else
            {
                dp[i]=dp[i/2];
            }
        }
        return dp;
    }
};
  // 0->0
  // 1->1
  // 2->1
  // 3->2
  // 4->1
  // 5->2
  // 6->2
  // 7->3
  // 8->1
  // 9->2
  // 10->2
  // =>even -> /2
  // =>odd  -> /2+1