class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       unordered_set<int>st1,st2;
        for(int i=0;i<nums1.size();i++)
            st1.insert(nums1[i]);
        
        for(int j=0;j<nums2.size();j++)
            st2.insert(nums2[j]);
        vector<int>ans;
        for(auto it:st1)
        {
            if(st2.find(it)!=st2.end()) //found the element
                ans.push_back(it);
        }
        return ans;
    }
};