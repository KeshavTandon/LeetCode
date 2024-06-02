class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>hash(256,-1); //char ->index mapping
        int maxi=0;
        int left=0,right=0,n=s.size();
        while(right<n)
        {
          if(hash[s[right]]!=-1)
          {
              if(hash[s[right]]>=left)
              {
                  left=hash[s[right]]+1;
              }
          }
            maxi=max(maxi,right-left+1);
            hash[s[right]]=right;
            right=right+1;
        }
        return maxi;
    }
};