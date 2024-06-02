class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>lastSeen(3,-1);
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            lastSeen[s[i]-'a']=i;
            if(lastSeen[0]!=-1 && lastSeen[1]!=-1 && lastSeen[2]!=-1)
            {
                int mini=*min_element(lastSeen.begin(),lastSeen.end());
                ans+=1+mini;
            }
        }
        return ans;
    }
};