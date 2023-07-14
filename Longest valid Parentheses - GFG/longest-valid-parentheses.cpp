//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxLength(string S){
        stack<int>st;
        st.push(-1);
        int maxLen=0;
        for(int i=0;i<S.size();i++)
        {
            char ch=S[i];
            if(ch=='(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if(st.empty())
                {
                    st.push(i); //invalid case
                }
                else
                {
                    int len=i-st.top();
                    maxLen=max(maxLen,len);
                }
            }
        }
        return maxLen;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends