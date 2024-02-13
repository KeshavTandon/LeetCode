class Solution {
public:
    bool checkPalindrome(string &s)
    {
        int i=0,j=s.size()-1;
        while(i<=j)
        {
            if(s[i]==s[j])
                i++,j--;
            else
                return false;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        string ans="";
        for(int i=0;i<words.size();i++)
        {
            if(checkPalindrome(words[i])==true)
            {
                ans=words[i];
                break;
            }
        }
        return ans;
    }
};