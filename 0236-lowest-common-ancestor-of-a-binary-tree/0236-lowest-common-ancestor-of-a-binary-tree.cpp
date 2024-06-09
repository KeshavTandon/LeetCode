/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //Base Case
        if(root==NULL || root==p || root==q) return root;
        
       TreeNode* lft= lowestCommonAncestor(root->left,p,q);
       TreeNode* rght= lowestCommonAncestor(root->right,p,q);
        
        if(lft==NULL) return rght;
        else if(rght==NULL) return lft;
        else return root; //left and right are not null
    }
};