class Solution {
public:
    bool solve(string &a,string &b,string &order)
    {
        int i=0;
        int n=a.size();
        while(i<n && i<b.size() && a[i]==b[i]) i++;
        if(i<a.size() && i==b.size()) return false;
        if(i==a.size()) return true;
        if(order.find(a[i])>order.find(b[i])) return false;
        else return true;
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0;i<words.size()-1;i++)
        {
            if(!solve(words[i],words[i+1],order))
                return false;
        }
        return true;
    }
};
//hello leetcode
//word world
//apple app