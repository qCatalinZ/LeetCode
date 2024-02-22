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

void InOrder( vector<int> &v, TreeNode* root )
{
    auto tmp=root;

    if(tmp->left)
        InOrder( v, tmp->left );
    v.push_back(tmp->val);
    if(tmp->right)
        InOrder( v, tmp->right );

}

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> v;

        if(root)
        {
            InOrder(v,root);
        }

        return v;
    }
};