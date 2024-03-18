class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int ans=1;
        vector<int>prev=points[0];
        for(int i=1;i<points.size();i++)
        {
            int currStartPoint=points[i][0];
            int currEndPoint=points[i][1];
            
            int prevStartPoint=prev[0];
            int prevEndPoint=prev[1];
            
            if(currStartPoint>prevEndPoint)
            {
                ans++;
                prev=points[i];
            }
            else
            {
                //overlapping
                prev[0]=max(currStartPoint,prevStartPoint);
                prev[1]=min(currEndPoint,prevEndPoint);
            }
        }
        return ans;
    }
};