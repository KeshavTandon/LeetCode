/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<vector < int>> zigzagLevelOrder(TreeNode *root)
        {
            vector<vector < int>> ans;
            if (!root) return ans;
            queue<TreeNode*> q;
            q.push(root);
            bool leftToRight = true;
            while (!q.empty())
            {
                vector<int> temp;
                int size = q.size();
                for (int i = 0; i < size; i++)
                {
                    TreeNode *frnt = q.front();
                    q.pop();
                    if (frnt->left)
                        q.push(frnt->left);
                    if (frnt->right)
                        q.push(frnt->right);
                    temp.push_back(frnt->val);
                }
                if (leftToRight == true)
                    ans.push_back(temp);
                else
                {
                    vector<int> v(temp.size());
                    for (int i = 0; i < temp.size(); i++)
                    {
                        v[i] = temp[temp.size() - i - 1];
                    }
                    ans.push_back(v);
                }
                leftToRight=!leftToRight;
            }
            return ans;
        }
};