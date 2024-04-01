class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0;
        bool flag=false;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]==' ' && !flag)
            {
                // cout << ans << endl;
                while(s[i]==' ') i--;
            }
            if(s[i]==' ' && flag) break;
            ans++;
            flag=true;
        }
        return ans;
    }
};