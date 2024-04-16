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
    void add(TreeNode* root,int val){
        TreeNode *n1=new TreeNode(val);
        TreeNode *n2=new TreeNode(val);
        n1->left=root->left;
        root->left=n1;
        n2->right=root->right;
        root->right=n2;
    }
    void traverse(TreeNode* root,int depth,int cur,int val){
        if(root!=NULL){
            if(cur==depth-1){
                add(root,val);
            }
            traverse(root->left,depth,cur+1,val);
            traverse(root->right,depth,cur+1,val);
        }

    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode *n1=new TreeNode(val);
            n1->left=root;
            return n1;
        }
        traverse(root,depth,1,val);
        return root;
    }
};