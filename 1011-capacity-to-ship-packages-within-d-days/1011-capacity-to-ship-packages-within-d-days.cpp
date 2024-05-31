class Solution {
public:
    int findSum(vector<int>&w)
    {
        int sum=0;
        for(int i=0;i<w.size();i++)
        {
            sum+=w[i];
        }
        return sum;
    }
    
    bool isPossible(vector<int>&w,int mid,int days)
    {
        int day=1;
        int sum=0;
        for(int i=0;i<w.size();i++)
        {
            if(w[i]>mid) return false;
            if(sum+w[i]>mid)
            {
                day+=1;
                sum=w[i];
            }
            else sum+=w[i];
            
        }
        return day<=days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int start=*min_element(weights.begin(),weights.end());
        int end=findSum(weights);
        int ans=end;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(isPossible(weights,mid,days))
            {
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
};