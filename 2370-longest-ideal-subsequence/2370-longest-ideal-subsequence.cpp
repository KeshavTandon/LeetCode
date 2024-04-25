class Solution {
public:
    int longestIdealString(string s, int k) {
        
        vector<int> dp(s.size(),1) , helper(26,0);

        for(int i=0;i<s.size();i++){
            for(int j=0;j<26;j++){
                if(  abs( s[i] - (j + 'a') ) <=k)
                    dp[i] = max(dp[i], helper[j]+1);    
            }
            helper[s[i]-'a'] = dp[i];
        }

        return *max_element(dp.begin(),dp.end());
    }
};