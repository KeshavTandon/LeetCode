//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string s)
    {
        stack<char>st;
       for(int i=0;i<s.size();i++)
       {
           if(s[i]=='(' || s[i]=='[' || s[i]=='{')
           {
               st.push(s[i]);
           }
           else
           {
               if(!st.empty())
               {
                   char t=st.top();
                   if((s[i]==')' && t=='(') || (s[i]==']' && t=='[') || (s[i]=='}' && t=='{'))
                   {
                       st.pop();
                   }
                   else
                   {
                       return false;
                   }
               }
               else{
               return false;
               }
           }
       }
        return st.empty()?true:false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends