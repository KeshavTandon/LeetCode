/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root) return ans;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty())
        {
            int n=st.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* tp=st.top();
                st.pop();
                if(tp->right)
                    st.push(tp->right);
                if(tp->left)
                    st.push(tp->left);
                ans.push_back(tp->val);
            }
        }
        return ans;
        
    }
};