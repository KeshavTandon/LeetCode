class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        string t; // using it as a stack
        for(int i = 0; i < n; i++) {
            while (!t.empty() && k > 0 && t.back() > num[i]) {
                k--;
                t.pop_back();
            }
            t.push_back(num[i]);
        }
        
        // for non-increasing order
        while (k > 0) {
            k--;
            t.pop_back();
        } 
        
        // remove zero digits from the left
        while (!t.empty() && t[0] == '0') {
            t.erase(0, 1);
        }

        return (t == "") ? "0" : t;
    }
};