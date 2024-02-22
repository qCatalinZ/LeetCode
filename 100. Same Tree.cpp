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

void s(TreeNode *p,TreeNode*q, bool &adv)
{
        if((p && !q) || (!p && q))
        {
            adv=false;
            return;
        }

        if( p->val != q->val )
        {
            adv=false;
            return;
        }

        if(p->left && q->left)
            s(p->left,q->left,adv);
          
        if(p->left && !q->left)
        {
            adv=false;
            return;
        }
        if(!p->left && q->left)
        {
            adv=false;
            return;
        }

        if(p->right && q->right)
            s(p->right,q->right,adv); 
        
        if(p->right && !q->right)
        {
            adv=false;
            return;
        }
        if(!p->right && q->right)
        {
            adv=false;
            return;
        }
}
 
class Solution 
{
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if( p==nullptr && q==nullptr )
            return true;
        bool adv=true;
        s(p,q,adv);
        return adv;
    }
};