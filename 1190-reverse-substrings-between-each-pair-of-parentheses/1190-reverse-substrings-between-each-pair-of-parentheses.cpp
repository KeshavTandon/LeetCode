class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>lastIndex;
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                lastIndex.push(ans.length()); 
            }
            else if(s[i]==')')
            {
                int l=lastIndex.top();
                lastIndex.pop();
                reverse(ans.begin()+l,ans.end());
            }
            else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
