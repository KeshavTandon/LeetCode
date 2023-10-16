//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<k;i++) //traversing the first window
        {
            mp[A[i]]++;
        }
        ans.push_back(mp.size()); // first window distinct elements are stored
        
        for(int i=k;i<n;i++) //traversing the rest windows
        {
            int add=A[i];
            int sub=A[i-k];
            if(mp[sub]==1){
            mp.erase(sub);
            }
            else
            mp[sub]--;
            mp[add]++;
            ans.push_back(mp.size());
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends