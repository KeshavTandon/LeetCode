class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>>maxH;
        vector<vector<int>>ans;
        for(int i=0;i<points.size();i++)
        { 
            //x^2+y^2
            int val=(points[i][0]*points[i][0]) + (points[i][1]*points[i][1]);
            maxH.push({val,{points[i][0],points[i][1]}});
            if(maxH.size()>k)
                maxH.pop();
        }
        while(!maxH.empty())
        {
            vector<int>temp;
            temp.push_back(maxH.top().second.first);
            temp.push_back(maxH.top().second.second);
            maxH.pop();
            ans.push_back(temp);
        }
        return ans;

    }
};