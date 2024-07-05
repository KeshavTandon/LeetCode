class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //width * NSL-NSR-1 ->max area
        vector<int>NSL,NSR;
        stack<int>st1,st2;
        int ans=INT_MIN;
        int n=heights.size();
        //NSL
        for(int i=0;i<n;i++)
        {
            if(st1.empty())
            {
                NSL.push_back(-1);
            }
            else if(!st1.empty() && heights[st1.top()]<heights[i])
            {
                NSL.push_back(st1.top());
            }
            else if(!st1.empty() && heights[st1.top()]>=heights[i])
            {
                while(!st1.empty() && heights[st1.top()]>=heights[i])
                {
                    st1.pop();
                }
                if(st1.empty())
                    NSL.push_back(-1);
                else
                    NSL.push_back(st1.top());
                
               
            }
             st1.push(i);
        }
        
        //NSR
         for(int i=n-1;i>=0;i--)
        {
            if(st2.empty())
            {
                NSR.push_back(n);
            }
            else if(!st2.empty() && heights[st2.top()]<heights[i])
            {
                NSR.push_back(st2.top());
            }
            else if(!st2.empty() && heights[st2.top()]>=heights[i])
            {
                while(!st2.empty() && heights[st2.top()]>heights[i])
                {
                    st2.pop();
                }
                if(st2.empty())
                    NSR.push_back(n);
                else
                    NSR.push_back(st2.top());
                
               
            }
              st2.push(i);
        }
        reverse(NSR.begin(),NSR.end());
       for(int i=0;i<n;i++)
       {
           ans=max(ans,heights[i] * (NSR[i]-NSL[i]-1));
       }
        return ans;
    }
};