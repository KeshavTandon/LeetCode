//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
void PrintSubSum(int index,vector<int>&arr,vector<int>&ds,int N,int sum)
{
    if(index==N)
    {
        ds.push_back(sum);
        return;
    }
    
    PrintSubSum(index+1,arr,ds,N,sum+arr[index]);
    
    PrintSubSum(index+1,arr,ds,N,sum);
}
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>ds;
        PrintSubSum(0,arr,ds,N,0);
        sort(ds.begin(),ds.end());
        return ds;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends