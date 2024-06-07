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
    int findMaxPathSum(TreeNode* root,int &ans)
    {
        if(!root) return 0;
        int leftSum=max(0,findMaxPathSum(root->left,ans));
        int rightSum=max(0,findMaxPathSum(root->right,ans));
        ans=max(ans,root->val+leftSum+rightSum);
        return root->val+max(leftSum,rightSum);
    }
    
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        findMaxPathSum(root,ans);
        return ans;
    }
};