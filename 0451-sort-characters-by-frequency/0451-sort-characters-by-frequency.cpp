class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char,int>>hash(123);
        for(int i=0;i<s.size();i++)
        {
            int freq=hash[s[i]].second;
            hash[s[i]]={s[i],freq+1};
        }
        auto lambda=[&](pair<char,int>&p1,pair<char,int>&p2)
        {
            return p1.second>p2.second;
        };
        string ans="";
        sort(hash.begin(),hash.end(),lambda);
        for(int i=0;i<123;i++)
        {
            if(hash[i].second>0){
                char ch=hash[i].first;
                int freq=hash[i].second;
                ans+=string(freq,ch);
            }
        }
        return ans;
        
    }
};