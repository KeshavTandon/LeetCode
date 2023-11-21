//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
int Possible(int A[], int N, int M,int mid)
{
    int noOfStud=1,pages=0;
    for(int i=0;i<N;i++)
    {
        if(pages+A[i]>mid)
        {
            noOfStud++;
            pages=A[i];
        }
        else pages+=A[i];
    }
    return noOfStud;
   
}
    
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if(M>N) return -1;
        int high=0,low=INT_MIN;
        for(int i=0;i<N;i++)
        {
            low=max(A[i],low);
            high+=A[i];
        }
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int val=Possible(A,N,M,mid);
            if(val>M)
            {
                // ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends