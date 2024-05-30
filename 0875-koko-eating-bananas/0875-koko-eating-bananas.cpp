class Solution {
public:
    int findMax(vector<int>&piles)
    {
        int ans=INT_MIN;
        for(int i=0;i<piles.size();i++)
        {
            ans=max(ans,piles[i]);
        }
        return ans;
    }
    long long findHours(vector<int>&piles,int mid)
    {
        long long ans=0;
        for(int i=0;i<piles.size();i++)
        {
            ans+=ceil(double(piles[i])/double(mid));
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start=1,end=findMax(piles);
        int ans=0;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            long long totalHours=findHours(piles,mid);
            if(totalHours<=h)
            {
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
};