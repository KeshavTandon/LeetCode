class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        int n = students.size();
        for(int i=0; i<n; i++){
            q.push(students[i]);
        }

        for(int i=0; i<n; i++){
            int count = 0;
            while(count < q.size() && q.front() != sandwiches[i]){
                int ele = q.front();
                q.pop();
                q.push(ele);
                count += 1;
            }
            if(q.front() == sandwiches[i])q.pop();
            else break;
        }
        return q.size();
    }
};