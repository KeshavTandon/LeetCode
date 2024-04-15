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
int sum(TreeNode* root,int current_sum)
{
    if(root==NULL) return 0;
    current_sum=current_sum*10+root->val;
    if(root->left==NULL && root->right==NULL) return current_sum;

    int leftnode=sum(root->left,current_sum);
    int rightnode=sum(root->right,current_sum);
    return leftnode+rightnode;
}

    int sumNumbers(TreeNode* root) {
        int current_sum=0;
        return sum(root,current_sum);
    }
};