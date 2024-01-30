class Solution {
public:
    int Operate(int x,int y,string op)
    {
        if(op=="+")
        {
            return x+y;
        }
        else if(op=="-")
        {
            return y-x;
        }
        else if(op=="*")
        {
            return y*x;
        }
        else return y/x; 
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(string &strng:tokens)
        {
            if(strng=="+" || strng=="-" || strng=="*" || strng=="/")
            {
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                int z=Operate(x,y,strng);
                st.push(z);
            }
            else{
                st.push(stoi(strng));
            }
        }
        return st.top();
    }
};