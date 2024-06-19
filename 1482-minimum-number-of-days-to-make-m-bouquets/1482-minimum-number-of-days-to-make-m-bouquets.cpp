class Solution {
public:
    bool isPossible(vector<int>& bloomDay,int mid,int m, int k)
    {
        int conse=0;
        int len=0;
        for(int i=0;i<bloomDay.size();i++)
        {
            if(len==k){
                conse++;
                len=0;
            }
            if(bloomDay[i]<=mid)
            {
                len++;
            }
            else{
                len=0;
            }
        }
        if(len==k)
        {
            conse+=len/k;
        }
        return conse>=m;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        long long value=m*1LL *k *1LL;
        if(n<value) return -1;
        int start=*min_element(bloomDay.begin(),bloomDay.end());
        int end=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=end; //in worst case
        
        while(start<=end)
        {
            int mid=start+(end-start)/2;  
            if(isPossible(bloomDay,mid,m,k))
            {
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
};