class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n=tickets.size();
        int ans=0;
        if(tickets[k]==0) return 0;
        while(true)
        {
            for(int j=0;j<n;j++)
            {
                if(tickets[j]>0){
                tickets[j]-=1;
                ans++;
                }
                if(tickets[k]==0) return ans;
            }
            
        }
    }
};