//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    int pat_size=pat.size();
	    int txt_size=txt.size();
	    if(pat_size>txt_size) return 0;
	    vector<int>cnt(26),x(26);
	    for(int i=0;i<pat_size;i++)
	    {
	        cnt[pat[i]-'a']++;
	        x[txt[i]-'a']++;
	    }
	    int ans=0;
	    ans+=cnt==x; //checking whether the pattern is there or not
	    for(int i=pat_size,j=0;i<txt_size;i++,j++)
	    {
	        x[txt[i]-'a']++;
	        x[txt[j]-'a']--;
	        ans+=cnt==x;
	    }
	    return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends