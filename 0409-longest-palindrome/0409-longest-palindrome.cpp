class Solution {
public:
    int longestPalindrome(string s) {
        //there can be max 1 freq odd
        unordered_map<char,int>mp;
        int ans=0;
        bool flag=true;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        for(auto it:mp)
        {
            if(it.second&1) //odd
            {
                flag=false;
                if(it.second>=3)
                ans+=it.second-1;
            }
            else
            {
                ans+=it.second;
            }
        }
        if(!flag) ans+=1;
        return ans;
    }
};