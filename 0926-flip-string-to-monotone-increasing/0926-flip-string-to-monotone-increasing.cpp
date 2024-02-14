class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int flips=0,count_of_ones=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1') count_of_ones++;
            else{
                flips=min(flips+1,count_of_ones);
            }
        }
        return flips;
    }
};