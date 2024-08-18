class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        if(p.size()>s.size()) return ans;
        vector<int>hash_s(26,0),hash_p(26,0);
        int left=0,right;
        for(right=0;right<p.size();right++)
        {
            hash_s[s[right]-'a']++;
            hash_p[p[right]-'a']++;
        }
        cout << right << endl;
        bool f=false;
        for(int i=0;i<26;i++)
        {
            if(hash_s[i]!=hash_p[i]){
                f=true;
                break;
            }     
        }
        if(!f)
            ans.push_back(0);
        
        while(right<s.size())
        {
            hash_s[s[left]-'a']--;
            left++;
            
            hash_s[s[right]-'a']++;
             bool f=false;
        for(int i=0;i<26;i++)
        {
            if(hash_s[i]!=hash_p[i]){
                f=true;
                break;
            }     
        }
        if(!f)
            ans.push_back(left);
        right++;    
        }
        return ans;
    }
};