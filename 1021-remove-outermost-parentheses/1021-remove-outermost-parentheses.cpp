class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        bool flag=false;
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(st.empty() && s[i]=='(' && !flag)
            {
                flag=true;
                continue;
            }
           
            else if(st.empty() && s[i]==')' && flag)
            {
                flag=false;
                continue;
            }
            else if(st.empty() && s[i]=='(' && flag)
            {
                ans+=s[i];
                st.push(s[i]);
            }
            else if(!st.empty() && s[i]==')' && st.top()=='(')
            {
                ans+=s[i];
                st.pop();
            }
            else{
                ans+=s[i];
                st.push(s[i]);
            }
            
        }
        return ans;
    }
};