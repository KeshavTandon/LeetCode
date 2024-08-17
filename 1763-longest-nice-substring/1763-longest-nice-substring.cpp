class Solution {
public:
    string longestNiceSubstring(string s) {
        if(s.size()<2) return "";
        unordered_set<char>st;
        for(int i=0;i<s.size();i++)
        {
            st.insert(s[i]);
        }
        for(int i=0;i<s.size();i++)
        {
            if(st.count(tolower(s[i])) && st.count(toupper(s[i])))
                continue;
            
            string prev=longestNiceSubstring(s.substr(0,i));
            string next=longestNiceSubstring(s.substr(i+1));
            return prev.size()>=next.size()?prev:next;
        }
        return s;
    }
};

