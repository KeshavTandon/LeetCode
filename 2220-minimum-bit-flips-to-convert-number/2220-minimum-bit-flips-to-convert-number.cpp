class Solution {
public:
    int minBitFlips(int start, int goal) {
         int xorOfNumbers=start^goal;
        int ans=0;
        while(xorOfNumbers!=0)
        {
            if(xorOfNumbers&1) ans++;
            xorOfNumbers>>=1;
        }
        return ans;
    }
};