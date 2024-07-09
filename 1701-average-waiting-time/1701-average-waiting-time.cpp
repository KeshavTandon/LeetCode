class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int curr_time=customers[0][0]+customers[0][1]; //3
        double avg_wait=curr_time-customers[0][0]; //2
        int n=customers.size();
        for(int i=1;i<n;i++)
        {
            if(curr_time<customers[i][0])
                curr_time=customers[i][0];
            
            curr_time+=customers[i][1];
            avg_wait+=(curr_time-customers[i][0]);
        }
        return avg_wait/n;
    }
};

//5 7  -> 7-5 = 2
//5 4  -> 11-5 = 7
//10 3 -> 15-10 =5
//

//track->current_time
//avg_time/size