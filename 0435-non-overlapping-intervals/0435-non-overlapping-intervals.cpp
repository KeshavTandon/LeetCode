class Solution
{
    public:
        static bool comp(vector<int> &p1, vector<int> &p2)
        {
            return p1[1] < p2[1];
        }

    int eraseOverlapIntervals(vector<vector < int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), comp);
        int ans = 0;
        int prevTime=intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0]>=prevTime)
            {
                
                prevTime=intervals[i][1];
            }
            else ans++;
        }
        return ans;
    }
};