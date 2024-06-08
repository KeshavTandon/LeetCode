class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int consecutive=0;
        int prev=skills[0];
        int maxi=skills[0];
        int maxi_index=0;
        int index=0;
        for(int i=1;i<skills.size();i++)
        {
            if(maxi<skills[i])
            {
                maxi=skills[i];
                maxi_index=i;
            }
            
            if(prev>skills[i])
            {
                consecutive++;
            }
            else {
                prev=skills[i];
                index=i;
                consecutive=1;
            }
            if(consecutive>=k) return index;
        }
        return maxi_index;
    }
};