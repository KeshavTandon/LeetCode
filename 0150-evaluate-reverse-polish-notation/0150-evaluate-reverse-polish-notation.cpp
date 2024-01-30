class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        unordered_map<string,function<int(int,int)>>mp={
            {"+",[](int a,int b){return a+b;}},
            {"-",[](int a,int b){return a-b;}},
            {"*",[](int a,int b){return a*b;}},
            {"/",[](int a,int b){return a/b;}}
        };
        for(string &strng:tokens)
        {
            if(strng=="+" || strng=="-" || strng=="*" || strng=="/")
            {
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                int z=mp[strng](y,x);
                st.push(z);
            }
            else{
                st.push(stoi(strng));
            }
        }
        return st.top();
    }
};