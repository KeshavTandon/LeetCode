class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0) return false;
        
        map<int,int>mp;
        for(int i=0;i<n;i++)
            mp[hand[i]]++;
        
        while(!mp.empty())
        {
            int number=mp.begin()->first;
            
            for(int i=0;i<groupSize;i++)
            {
                if(mp[number+i]==0)
                    return false;
                
                mp[number+i]--;
                if(mp[number+i]<1)
                 mp.erase(number+i);
              
            }
        }
        return true;
    }
};