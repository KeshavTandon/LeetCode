class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int one_count=0,zero_count=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1') one_count++;
            else zero_count++;
        }
        string ans="";
        while(one_count!=1)
        {
            ans+='1';
            one_count--;
        }
        while(zero_count!=0)
        {
            ans+='0';
            zero_count--;
        }
        return ans+'1';
    }
};