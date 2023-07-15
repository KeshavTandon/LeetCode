//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
void returnMiddle(stack<int>&s, int sizeOfStack,int middle)
{
    if(middle==sizeOfStack)
    {
        s.pop();
        return;
    }
    int topElement=s.top();
    s.pop();
    sizeOfStack--;
    returnMiddle(s,sizeOfStack,middle);
    s.push(topElement);
    
}
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
    int middle= ceil((sizeOfStack+1)/2);
      returnMiddle(s,sizeOfStack,middle);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends