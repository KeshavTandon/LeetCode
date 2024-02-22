class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustcount(n + 1, 0); 

        // Count trust relationships
        for (const auto& relation : trust) {
            trustcount[relation[0]]--;  
            trustcount[relation[1]]++;  
        }
        for (int i = 1; i <= n; ++i) {       // Check if there is a person who is trusted by everyone else
            if (trustcount[i] == n - 1) {
                return i;
            }
        }
        return -1;    // If no such person found, return -1
    }
};