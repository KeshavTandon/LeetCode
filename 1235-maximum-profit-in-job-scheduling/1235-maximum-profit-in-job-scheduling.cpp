class Solution {
public:
    int dp[50001];
    int calculateNextElement(vector<vector<int>>&arr,int start,int target,int end,int n)
    {
        int ans=n+1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(arr[mid][0]>=target)
            {
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
    int solve(vector<vector<int>>&arr,int index,int n)
    {
        if(index>=n) return 0;
        if(dp[index]!=-1) return dp[index];
        int nextElement=calculateNextElement(arr,index+1,arr[index][1],n-1,n);
        int taken=arr[index][2] +solve(arr,nextElement,n);
        int not_taken=solve(arr,index+1,n);
        return dp[index]=max(taken,not_taken);
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        memset(dp,-1,sizeof(dp));
        vector<vector<int>>arr(n,vector<int>(3,0));
        for(int i=0;i<n;i++)
        {
            arr[i][0]=startTime[i];
            arr[i][1]=endTime[i];
            arr[i][2]=profit[i];
        }
        sort(arr.begin(),arr.end());
        return solve(arr,0,n);
    }
};