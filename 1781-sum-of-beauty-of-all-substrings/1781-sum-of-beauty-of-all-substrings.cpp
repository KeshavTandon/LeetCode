class Solution {
public:
    int findAns(vector<int>&dp)
    {
        int maxi=INT_MIN,mini=INT_MAX;
        for(int i=0;i<26;i++)
        {
            if(dp[i]>0){
                maxi=max(maxi,dp[i]);
                mini=min(mini,dp[i]);
            }
        }
        
        return maxi-mini;
    }
    
    int beautySum(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            vector<int>dp(26,0);
            for(int j=i;j<s.size();j++)
            {
                dp[s[j]-'a']++;
                ans+=findAns(dp);
            }
        }
        return ans;
    }
};