class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count=0;
        string a="./";
        string b="../";
        for(int i=0;i<logs.size();i++)
        {
            if(logs[i]==a)
                continue;
            else if(logs[i]==b && count>0)
                count--;
            else if(logs[i]==b && count==0)
                continue;
            else count++;
        }
        return count;
    }
};